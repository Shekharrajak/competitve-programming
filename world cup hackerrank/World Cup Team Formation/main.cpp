#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int a[10];
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    sort(a,a+9);

    cout<<(a[9]+a[7]+a[5]);

    return 0;
}
