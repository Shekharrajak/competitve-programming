#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
  //int p =1;
  int flag =0;
   for(int i=0;i<5;i++){
    for(int j=i;j>=0;j--){
        if(flag%2 != 0){
        printf("%d",(j+1)%2);

        }
        //else{
          //   printf("%d",(j)%2);
        //flag--;
        //}
        else{
             printf("%d",(j+1)%2);
        }
    }
    printf("\n");
    flag++;
    }
    return 0;
}
