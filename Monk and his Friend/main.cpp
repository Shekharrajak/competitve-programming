#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* Function to get no of set bits in binary
   representation of passed binary no. */
int countSetBits(long long m , long long p)
{
  int count =0;
  while(m || p)
  {
    if(m & 1 == p & 1){
        count++;
    }
    m >>= 1;
    p >>=1;
  }
  return count;
}

int main()
{
    long long tc,m,p;
    cin>>tc;
    while(tc--){
        cin>>m>>p;

        cout<<countSetBits(m,p)<<endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
