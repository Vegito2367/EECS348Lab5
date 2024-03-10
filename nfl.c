#include <stdio.h>
#include <string.h>
void main()
{
  int targetScore;
  for(;;)
  {   
      printf("Enter 0 or 1 to STOP\n");
      printf("Enter the target score: \n");
      scanf("%d",&targetScore);

      if(targetScore<2)
      break;
      //6,3,2,8,7
      int a,b,c,d,e;
      int sum=0;
      for(a=0;a<=(targetScore/8);a++)
      {
        for(b=0;b<=(targetScore/7);b++)
        {
          for(c=0;c<=(targetScore/6);c++)
          {
            for(d=0;d<=(targetScore/3);d++)
            {
              for(e=0;e<=(targetScore/2);e++)
              {
                sum=(8*a)+(7*b)+(6*c)+(3*d)+(2*e);
                if(sum==targetScore)
                {
                  printf("%d TD+2pt, %d TD+FG, %d TD, %d FG, %d Safety\n",a,b,c,d,e);
                }
              }
            }
          }
        }
      }
  }
  
  printf("\nProgram ended successfully");
  
}