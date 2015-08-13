#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int coinChange(int coins[],int total,int n){

    //int size = sizeof(coins)/sizeof(coins[0]);
    int res[n+1][total+1];
    //memset(res,1 , sizeof(res));
    //for(int i = 1 ;i<size;i++){
        for(int j=0;j<total+1;j++){
            res[1][j]=1;
        }
    //}
    for(int i=1;i<=n;i++){
            res[i][0]=1;
        }
    for(int i = 1 ;i<=n;i++){
        for(int j=0;j<total+1;j++){
            if(j>=coins[i]){
                res[i][j] = res[i-1][j]+res[i][j-coins[i]];
            }
            else{
                res[i][j] = res[i-1][j];
            }
        }
    }
    for(int i = 1 ;i<=n;i++){
        for(int j=0;j<total+1;j++){
            cout<<res[i][j]<<" ";
        }
      }
    return res[n][total];
}
int main()
{
    //int *coins;
    int n,total;
    cin>>n>>total;
   int coins[n] ;
    for(int i =0 ;i<n;i++){
        cin>>coins[i];
    }

    cout<< endl<<coinChange(coins,total,n);
}
