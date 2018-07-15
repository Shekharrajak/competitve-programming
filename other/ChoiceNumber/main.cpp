#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* Function to get no of set bits in binary
   representation of passed binary no. */
int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while(n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
int cn(int a,int b){
    return countSetBits(a)+countSetBits(b);
}
int main()
{
    int tc,n,k;
    cin>>tc;
    while(tc--){
        cin>>n>>k;
        int a[n];
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        int max = INT_MIN;
        int count INT_MIN;
        for(int i=0;i<n-k;i++){
            for(int j=i+1;j<n;j++){
                 count = cn(a[i],a[j]);
                if(max < count){
                    max = count;
                }
            }
        }
        cout<<max<<endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
