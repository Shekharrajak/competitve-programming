#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
//#define pii pair<int,int>
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;
#define MAX 100000

//const int MAX = 1e4+5;
typedef pair<int ,int> pii;
bool marked[MAX];
vector<pii> adj[MAX];
int prime(int x){
    priority_queue<pii,vector<pii> ,greater<pii> >Q;
    int y;
    int mincost=0;
    pii p;
    Q.push(mp(0,x));
    while(!Q.empty()){
        p=Q.top();
        Q.pop();
        x=p.second;
        if(marked[x] == true){
            continue;
        }
        mincost +=p.first;
        marked[x]=true;
        for(int i=0;i<adj[x].size();i++){
            y= adj[x][i].second;
            if(marked[y] == false){
                Q.push(adj[x][i]);
            }
        }
    }
    return mincost;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            int nodes1,nodes2;
            cin>>nodes1>>nodes2;
            adj[nodes1].pb(mp(1,nodes2));
            adj[nodes2].pb(mp(1,nodes1));
        }
        int minc= prime(1);
        cout<<minc<<endl;

    }
return 0;
}
