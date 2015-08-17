#include <iostream>

using namespace std;

void mcoloring(int k,int m,int **adj){
    int x[m];
    for(int i = 0;i<=m ;i++){
        x[i]=0;
    }
    adj[k] = getNodeColor(k);
    if(x[k] == 0){
        return;
    }
    if(k==m){
        for(int i=1;)
    }
}
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    int c=0;
    int **adj ;
    adj =new int*[nodes+1];
    for(int i =0;i<=nodes ;i++){
        adj[i]=new int[nodes+1];
    }
    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
            adj[i][j]=0;
        }

    }
    //enter nodes number from 1 ..... n
    //colors from 1...m
    while(c!=edges){
        int a1,a2;
        cin>>a1>>a2;
        adj[a1][a2]=1;
    }
    //for(int i=1;i<=nodes;i++){
        mcoloring(1,adj);

    cout<<endl<<adj[nodes][nodes]<<endl;
}
