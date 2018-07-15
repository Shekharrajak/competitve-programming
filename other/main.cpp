#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct arr{
    long long int val;
    int horv;
};
int compare( arr a, arr b){
    return a.val > b.val ? 1 : 0;
}
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n,m;
        scanf("%d %d",&m,&n);
        int i;
        arr a[m+n];
        int j=0;
        for(i=1;i<m;i++){
            scanf("%lld",&a[j].val);
            a[j].horv=1;    // its a horizontal line
            j++;
        }
        //j=0;
        for(i=1;i<n;i++){
            scanf("%lld",&a[j].val);
            a[j].horv=0;  // verticle line
            j++;
        }
        sort(a,a+j,compare);
        int v=0;
        int h=0;
        long long int cost=0;
        for(i=0;i<j;i++){
            if(a[i].horv==1){  // making cut along horizontal line
                cost=(cost+(a[i].val*(v+1))%1000000007)%1000000007;
                h++;
            }
            else if(a[i].horv==0){  // making cut along verticle line
                cost=(cost+(a[i].val*(h+1))%1000000007)%1000000007;
                v++;
            }
        }
        printf("%lld\n",cost);
        }
    return 0;
}
