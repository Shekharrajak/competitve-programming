//Shekhar Prasad Rajak codechef august 2015 cooking machine
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int result(int a,int b){

    if(a==b){

        return 0;
    }
    //int count=0;
    if(a%2 == 0 && b%2 ==0){
        if(a>b){

        return 1+result(a/2,b);
        }
        else{
         return 1+result(a,b/2);
        }
    }

else if(a/2 == 1 )//&& b%2 ==0)
{
        return 2+result( ((a/2)*2),b);
    }
    else if (b/2 ==1)//(a%2 == 0 &&
    {
        return 2+result(a,(b/2)*2);
    }


    else if(a%2 != 0)// && b%2 ==0)
    {
        if(a==1){
            return 1+result(a*2,b);
        }
       return 1+result(a/2,b);
    }
     else if(b%2 !=0 )//a%2 == 0 &&
     {
         if(b==1){
            return 1+result(a,b*2);
        }
        return 1+result(a,b/2);
    }




}
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        int a,b;
        cin>>a>>b;
        cout<<result(a,b)<<endl;
    }
    return 0;
}
 
