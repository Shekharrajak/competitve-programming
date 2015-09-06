#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAXN 5007


long int id[MAXN];
long nodes,edges;
pair<long,pair<long,long> > p[MAXN];
void initialize(){
    for(long int i=0;i<MAXN;i++){
        id[i]=i;
    }
}
long int root(long int i){
    while(id[i]!=i){
        id[i]=id[id[i]];
        i= id[i];
    }
    return i;
}

void union1(long int x ,long int y){
    long int p= root(x);
    long int q = root(y);
    id[p]=id[q];
}
long long krushkal(pair<long int,pair<long int,long int> > p[]){
    long int x ,cost,y;
    long long maximumCost=0;
    for(int i=edges-1;i>=0;i--){
            x =p[i].second.first;
        y=p[i].second.second;
        cost = p[i].first;
        if(root(x)!=root(y)){
            maximumCost+=cost;
            union1(x,y);
        }
    }
    return maximumCost;
}
int main()
{
    long int x,y;
    long long weight,maximumc;
    initialize();
    int tc;
    cin>>tc;
    while(tc--){
    cin>>nodes>>edges;
    for(long int i=0;i<edges;i++){
        cin>>x>>y>>weight;
        p[i]=make_pair(weight,make_pair(x,y));
    }
    sort(p,p+edges);
    maximumc = krushkal(p);
    cout<<maximumc<<endl;
    }
    return 0;
}
