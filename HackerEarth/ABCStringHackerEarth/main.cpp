#include <iostream>
#include<bits/stdc++.h>
#define MOD 100000007
using namespace std;

//int factorial(int n)
//{
//  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
//}
//
//int comb(int a,int b){
//    return (factorial(a)/(factorial(b)*factorial(a-b)));
//}
int main()
{
    int tc,sum=1;
    //cout<<comb(3,1)<<"\t"<<comb(2,1)<<"\t"<<comb(1,1);
    cin>>tc;
    //char set[3]={'a','b','c'};
    while(tc--){

        long int k,n;
        cin>>k;
        n=k;
        //int s = sizeof(set)/sizeof(set[0]);
       // cout<<s;
        while(n>=3){

            //return 0;

        if(k==3){
            //int sum1=comb(3,1)*comb(2,1)*comb(1,1);
            //n--;
            int sum1=6;
            cout<<sum1<<endl;
            break;
        }
        if(n==3){
             //sum=sum*comb(3,1)*comb(2,1)*comb(1,1);
             sum=sum*6;
            n--;
        }
        else{

            //sum*=comb(3,1);
            sum*=pow (3.0,n-3) ;
            n=n-3-1;
        }
    }
    if(k>3){
    cout<<(sum*2 + MOD)%MOD<<endl;
    }
    else if(k<3){
        cout<<"0"<<endl;
    }
    sum=1;
}
    return 0;
}
