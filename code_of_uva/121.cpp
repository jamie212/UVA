#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char list[30];
int count=1;
void swap(int i, int j)
{ 
  char temp;
  temp=list[i];
  list[i]=list[j];
  list[j]=temp; 

} 


void perm(char *list, int i, int n)
{  
    int j;
    if (i==n) 
      {
         printf("%d.  ", count);
         count++;
         for(j=0; j<=n; j++) printf("%c", list[j]);
         printf("\n");
       }
    else {
             for(j=i; j<=n; j++){
               swap(i, j);
               printf("Swap i : %d j : %d count : %d\n", i, j, count);
               perm(list, i+1, n);
               swap(i, j);
               printf("Sawpp i : %d j : %d count : %d\n", i, j, count);
            }

    }
}
int main ()
{
  int stringlength; //輸入字串 list 長度 
  int sequence=1;   //排列的序號 
  printf("\n\n Input String : ");
  scanf("%s",list);
  printf("\n\n");
  printf("\n\n The string we sorted is : %s  ", list);
  printf("\n\n\n\n\n");
  stringlength=strlen(list);
  
  perm(list, 0, stringlength-1);
  
  printf("\n\n\n\n");
  system ("pause");
  return (0); 
}