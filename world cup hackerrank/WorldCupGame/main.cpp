#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 50005

vector<int>v[MAX];
long long int a[MAX];
long long sum[MAX],S,SA;

long long rec(int x,int fr){
    long long m= 0;
    sum[x]=a[x];
    for(int i=0;i<v[x].size();i++){
        if(v[x][i] != fr){
            rec(v[x][i],x);
            m=max(m,sum[v[x][i]]);
            sum[x] +=sum[v[x][i]];
        }
    }
       // cout <<"m : "<<m<<" changes to ";
        m=max(m,S-sum[x]);
       // cout<<m<<" ( "<< S <<"-"<<sum[x]<< ") and SA :" <<SA<<" changes to ";

        SA=min(m,SA);
       // cout<<SA<<endl;

    return 0;
}
int sol(){
    SA=S;
    rec(1,1);
    cout<<S-SA<<endl;
    //cout<<S<<"  -- "<<SA<<endl;
    return 0;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    int t;
    //cin>>t;
        cin>>a[i];//a.push_back(t);
        S+=a[i];
    }
    for(int i=0,x,y;i<n-1;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    sol();
    return 0;
}

//
////Actuall solution
//#include <bits/stdc++.h>
//#define pb push_back
//#define MI(a,b) ((a)<(b)?(a):(b))
//#define MA(a,b) ((a)>(b)?(a):(b))
//using namespace std;
//const int N=500002;
//vector <int> v[N];
//int n,a[N];
//long long sum[N],S,SA;
//
//int input(){
//    scanf("%d",&n);
//    for (int i=1;i<=n;i++)
//        scanf("%d",&a[i]),
//        S+=a[i];
//    for (int i=1,x,y;i<n;i++){
//        scanf("%d%d",&x,&y);
//        v[x].pb(y);
//        v[y].pb(x);
//    }
//    return 0;
//}
//
//void go(int x,int fr){
//    long long M=0;
//    sum[x]=a[x];
//    for (int i=0;i<v[x].size();i++)
//    if (v[x][i]!=fr){
//        go(v[x][i],x);
//        M=MA(M,sum[v[x][i]]);
//        sum[x]+=sum[v[x][i]];
//    }
//    cout <<"m : "<<M<<" changes to ";
//        M=max(M,S-sum[x]);
//        cout<<M<<" ( "<< S <<"-"<<sum[x]<< ") and SA :" <<SA<<" changes to ";
//
//        SA=min(M,SA);
//        cout<<SA<<endl;
//}
//
//int sol(){
//    SA=S;
//    go(1,1);
//    cout<<S-SA<<endl;
//    return 0;
//}
//
//int main() {
//    input();
//    sol();
//    return 0;
//}
