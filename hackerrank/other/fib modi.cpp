#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long nthterm(long a,long b,long n){
    long count,sum;
    while((n-2) != count){
        sum = pow(b,2)+a;
        a=b;
        b=sum;
        count++;
    }
    return sum;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long a,b,n;
    cin>>a>>b>>n;
    cout<<nthterm(a,b,n);
    return 0;
}

