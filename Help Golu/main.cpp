#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int count1 =0;
bool primeCheck(long int num){
    bool flag=true;;
    for(long int i=2;i<=sqrt(num);i++)
   {
      if(num%i == 0 && i !=2)
      {
         flag = false;
         return flag;
      }

      else if(num%i == 0 && i ==2 && num<6)
      {
         //flag = false;
         count1+=2;
         return flag;
      }
      else if(num%i == 0 )
      {
         flag = false;
         return flag;
      }
   }
   //cout<<num<<" is prime count++ done "<<endl;
   count1++;
   return flag;

}

void func(long int n){
    int m=n;
    while(n){
        if(primeCheck(m)){
            n-=m;
            m=n;
        }
        else{m--;}
        //m--;


    }
    cout<<count1<<endl;

}
int main()
{
   long int t;
   cin>>t;
   while(t--){
        long int n;
        cin>>n;
        count1=0;
        func(n);
       // count1=0;
   }
    return 0;
}
