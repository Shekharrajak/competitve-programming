#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
int x,r,n,count=0;
cin>>x>>r;
int temp_r=r;
//if((temp_r/x)%2 !=0){
if((temp_r/x) && ((temp_r/x) & ((temp_r/x)-1)!=0)){
    temp_r-=x;
    count++;

}
if(!temp_r){
    cout<<count<<endl;
        return 0;
    }

        int temp_x = temp_r/x;
       while(temp_x){

            count += temp_x & 1;
            temp_x>>=1;

       }


cout<<count<<endl;

    return 0;
}
