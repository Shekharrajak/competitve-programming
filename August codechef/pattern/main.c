#include <stdio.h>
#include <stdlib.h>

int main()
{
//   i//nt p =1;
   for(int i=0;i<5;i++){
    for(int j=i;j>=0;j--){
        printf("%d",(j+1)%2);
    }
    printf("\n");
   }
   return 0;
}
