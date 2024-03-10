#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Include stdlib.h for malloc

struct Dictionary
{
    char* monthName;
    float sales;
};



int main()
{
    FILE *file;
    char line[50];
    file=fopen("sample.txt","r");
    float prices[13];
    int m=0;
    while (fgets(line,sizeof(line),file) && (m<12))
    {
      float num=atof(line);
      prices[m]=num;
      m++;
    }
    
    struct Dictionary monthlySales[12];
    char* names[] = {"January", "February", "March", "April","May","June","July","August","September","October","November","December"};
    int i;
    float sumPrices=0;
    struct Dictionary maxMonth;
    maxMonth.monthName="January";
    maxMonth.sales=prices[i];

    struct Dictionary minMonth;
    minMonth.monthName="January";
    minMonth.sales=prices[i];


    for (i = 0; i < m; i++)
    {
        monthlySales[i].monthName = malloc(strlen(names[i]) + 1); // Allocate memory for monthName
        strcpy(monthlySales[i].monthName, names[i]);
        monthlySales[i].sales = prices[i];
        sumPrices=sumPrices+prices[i];
        if(prices[i]>maxMonth.sales)
        {
          maxMonth.sales=prices[i];
          maxMonth.monthName=names[i];
        }
        if(prices[i]<minMonth.sales)
        {
          minMonth.sales=prices[i];
          minMonth.monthName=names[i];
        }

    }

    printf("Monthly sales report for 2022:\n");
    printf("%-10s %-10s\n", "Month", "Sales");
    //Printing Monthly Sales report
    for (int j = 0; j < m; j++)
    {
        printf("%-10s $%.2f\n", monthlySales[j].monthName, monthlySales[j].sales); // Corrected indexing here
    }

    //Sales Summary
    printf("\n\nSales summary:\n");
    printf("%-15s $%.2f\t(%s)\n","Minimum Sales:",minMonth.sales,minMonth.monthName);
    printf("%-15s $%.2f\t(%s)\n","Maxiumum Sales:",maxMonth.sales,maxMonth.monthName);
    printf("%-15s $%.2f\n","Average Sales:",(sumPrices/12));

    monthlySales[0].monthName="January";
    //Moving Average
    printf("\n\n");
    printf("Six-Month Moving Average Report:\n"); 
    int n;
    for (n=0;n<7;n++)
    {
      float tempsum=0.0;
      for (int m1=0;m1<6;m1++){
        tempsum+=monthlySales[n+m1].sales;
      }
      float movingAverage=(tempsum/6);
      printf("%-10s - %-10s $%.2f\n",monthlySales[n].monthName,monthlySales[n+5].monthName,movingAverage);
    }

    
    //Sorting Part
    int index=0;
    int min=0;
    struct Dictionary temporary;
    for (index=0;index<12;index++)
    {
      min=index;
      for (int j=index+1;j<12;j++)
      {
        if(monthlySales[min].sales > monthlySales[j].sales)
        {
          min=j;
        }
      }

      temporary = monthlySales[index];
      monthlySales[index] = monthlySales[min];
      monthlySales[min] = temporary;

    }

    printf("\n\n");
    printf("Highest to Lowest:\n");
    printf("%-10s %-10s\n", "Month", "Sales");

    for (int j = m-1; j >= 0; j--)
    {
        printf("%-10s $%.2f\n", monthlySales[j].monthName, monthlySales[j].sales); 
        free(monthlySales[j].monthName);
    }
    return 0;
}