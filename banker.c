#include<stdio.h>
int max[20][20],avail[20],need[20][20],allo[20][20];
int work[20];
int finish[20];
int m,n,i,j,flag=1;

void main()
{
          printf("Enter the number of processes:");
          scanf("%d",&n);
          printf("Enter the number of resources");
          scanf("%d",&m);

          printf("Enter availbale resources:\n");

          for(j=0;j<m;j++)
          {
                  printf("Available of resource type %d",j+1);
                  scanf("%d",&avail[j]);
                  work[j] = avail[j];

          }

          for(i=0;i<n;i++)
          {
                  finish[i] = 0;

                  for(j=0;j<m;j++)
                  {


                          printf("Enter Process %d's Resource %d requirement:",i+1,j+1);
                          scanf("%d",&max[i][j]);
                          printf("Enter Process %d's Resource %d allocation:",i+1,j+1);
                          scanf("%d",&allo[i][j]);

                          need[i][j] = max[i][j] - allo[i][j];
                          printf("\ndone %d %d",i,j);
                  }
  printf("\noutside inner for\n");
          }

  printf("\noutside read!\n");




          //for(i=0;i<n;i++)
          while(i<n){
                  i=0;
                  //int need_sum = 0;

                  //for(j=0;j<m;j++)
                  //{
                  //      need_sum += need[i][j];
                  //}

                  printf("\ndo started\n");
                  int inner_flag = 1;

                  for(j=0;j<m;j++)
                  {
                          if(need[i][j] > work[j])
                          {
                                  break;
                                  inner_flag = 0;
                          }
                  }

                  if(inner_flag == 0)
                  {
                          break;
                  }

                  if(finish[i] == 0)
                  {
                          work[j] += allo[j];
                          finish[i] = 1;

                  }
                  if(i<n-1)
                  {
                          i++;
                  }

         }

          for(i=0;i<n;i++)
          {
                  if(finish[i] != 1)
                  {
                          printf("NOT SAFE!");
                          flag = 0;
                          break;
                  }
          }

          if(flag == 1)
          {
                 printf("SAFE!");
         }
 }