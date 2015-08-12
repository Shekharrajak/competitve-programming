#include <iostream>
#include<bits/stdc++.h>
#include <math.h>
using namespace std;

long int result(long int a,long int b){
long int count =0;
    while(a & (a-1) != 0){
        a=a/2;
        count++;
    }

    count+= (abs(log2(a) -log2(b)));


    return count;
}
int main()
{
    int tc;
    cin>>tc;

    while(tc--){
            long int a,b;
            cin>>a>>b;
            cout<<result(a,b)<<endl;
    }
}
