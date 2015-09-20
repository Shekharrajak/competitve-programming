#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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

vector<pair< int ,pair<int,int> > >p;
int id[MAX];
void initialize(){
    FOR(i,MAX){
        id[i]=i;
    }
}
int root(int x){
    while(id[x]!=x){
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}
void union1(int x,int y){
    int p=root(x);
    int q=root(y);
    id[p]=id[q];
}
//int m;

int krushkal(int s1,int a,int h,int edges){
    int x,y,c,mincost=0;
    for(int i=s1;i<edges && p[i].second.first != a && p[i].second.first != h;i++){
     //if(p[i].second.first == s2){return mincost;}
        x= p[i].second.first;
        y=p[i].second.second;
        c=p[i].first;

        if(root(x) != root(y)){
            mincost +=c;
            union1(x,y);
        }
    }
    return mincost;
}

int krushkal1(int s1,int s2,int edges){
    int x,y,c,mincost=0;
    for(int i=s1;i<edges;i++){
     if(p[i].second.first == s2){return mincost;}
        x= p[i].second.first;
        y=p[i].second.second;
        c=p[i].first;

        if(root(x) != root(y)){
            mincost +=c;
            union1(x,y);
        }
    }
    return mincost;
}

int krushkal2(int s1,int s2,int edges){
    int x,y,c,mincost=0;
    for(int i=s1;i<edges;i++){
        if(p[i].second.first == s2){return mincost;}
        x= p[i].second.first;
        y=p[i].second.second;
        c=p[i].first;
        if(root(x) != root(y)){
            mincost +=c;
            union1(x,y);
        }
    }
    return mincost;
}
bool compare(const pair< int,pair< int,int> >&i, const pair< int,pair< int,int> >&j)
{
    return i.first > j.first;
}
class graph{
    int v;
    list<int> *adj;

    public:
        graph(int v);
        void addEdge(int v,int w);

        //bool isAdjacent( int v,int w);
        //bool isVisited(int v);
};
graph::graph(int v){
    this->v =v;
    adj =new list< int>[v];
}
void graph::addEdge(int v,int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int main()
{

    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
         graph g(m);
        FOR(i,m){
        int x,y,c;
        cin>>x>>y>>c;
            g.addEdge(x,y);
            p.pb(mp(c,mp(x,y)));
        }
        sort(p.begin(),p.end(),compare);
        int s,a,h;
        cin>>s>>a>>h;
        initialize();
        int t= krushkal(s,a,h,m);
        initialize();
        int t1= krushkal1(s,a,m);
        cout<<t1<<endl;
        initialize();
        int t2=krushkal2(a,h,m);
        cout<<t2<<endl;
        cout<<t1+t2+t<<endl;
    }


    return 0;
}
