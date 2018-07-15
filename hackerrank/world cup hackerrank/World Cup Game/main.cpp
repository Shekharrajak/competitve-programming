#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000


vector<pair<long int ,long int> >p;
//int m;
class graph{
    long int v;
    list<long int> *adj;

    public:
        graph(long int v);
        void addEdge(long int v,long int w);
        bool isAdjacent(long int v,long int w);
        bool isVisited(long int v);
};
graph::graph(long int v){
    this->v =v;
    adj =new list<long int>[v];
}
void graph::addEdge(long int v,long int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}
bool graph::isAdjacent(long int v,long int w){
   list<long int>::iterator findIter = find(adj[v].begin(), adj[v].end(),w );
   if(findIter != adj[v].end()){
    return true;
   }
    return false;
}

//int* graph::AdjacentList(int v,int w){
//   list<int>::iterator findIter = find(adj[v].begin(), adj[v].end(),w );
//   if(findIter != adj[v].end()){
//    return true;
//   }
//}

bool compare(const pair<long int,long int>&i, const pair<long int,long int>&j)
{
    return i.second > j.second;
}
//int maxi1=0;
long int pick(graph g,long int k){
    long int hasVisited1,hasVisited2;
    long int visit[k];
    memset(visit,0,sizeof visit);
    long int maxi2,maxi1=0;
    for(long int i=0;i<k, i>hasVisited1;i++){
    maxi2=0;
   // cout<<"i m in for loop1"<<endl;
    maxi2+=p[i].second;//first time
    visit[p[i].first]=1;
    hasVisited1 = i;
    long int tempm1=0;
    for(long int j=0;j<k ,j>hasVisited2;j++){
        long int tempm2=maxi2;
       // cout<<"i m in for loop2"<<endl;
        if(!visit[p[j].first])//first time picked
        {visit[p[j].first]=1;hasVisited2 =j;}//second person choose



    long int count=0;
    long int l1,l2;
    while(count<k-1 && count != i){
    //cout<<"i m in for loop3"<<endl;
    tempm2=maxi2;
        if((!visit[p[count].first]) && (g.isAdjacent(p[i].first,p[count].first))){
            tempm2+=p[count].second;

            visit[p[count].first]=1;
            l1=p[count].first;
            long int tempc=0;//count+2;
            while(tempc<k-1 && tempc!=j){
           // cout<<"i m in for loop4"<<endl;
                if((!visit[p[tempc].first]) && (g.isAdjacent(p[j].first,p[tempc].first))){
                visit[p[tempc].first]=1;
                l2=p[tempc].first;
                }
                tempc+=1;
                break;
            }
              if(tempm2 > tempm1){
                    tempm1=tempm2;
        //cout<<maxi2<<"changed"<<endl;
            break;
                }
                visit[l1]=0;
            visit[l2]=0;
            count+=1;
        }
        count+=1;
        //count++;
        if(tempm1 > maxi2){
        maxi2=tempm1;
        //cout<<tempm1<<"changed"<<endl;
        break;

        }

//         visit[l1]=0;
//            visit[l2]=0;

    }
if(maxi2 > maxi1){
        maxi1=maxi2;
        //cout<<maxi2<<"changed"<<endl;
        break;
    }
    visit[p[hasVisited2].first]=0;
    }
    memset(visit,0,sizeof(visit));
}

return maxi1;
}


int main()
{
    long int n;
    cin>>n;
    assert (1<=n && n<=500000);
    long int m=n;
    graph g(m);
    //int val[n];
    for(long int i=0;i<m;i++){
        long int temp;
        cin>>temp;
        assert (1<=temp && temp<=1000000000);
        p.push_back(make_pair(i,temp));
    }


    //cout<<"done graph dec"<<endl;
    long int c=(m-1);
    while(c--){
        long int a,b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    //cout<<"done"<<endl;

     sort(p.begin(),p.end(),compare);
//    for(int i=0;i<n;i++){
//        cout<<p[i].first<<" "<<p[i].second<<endl;
//    }
    //cout<<g.isAdjacent(1,2);

    cout<<pick(g,n)<<endl;
    return 0;
}
