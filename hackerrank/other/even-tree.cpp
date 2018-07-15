
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
list<int >li[500];
int has[500][500];
int vis[10001];
int c=0;
void  bfs(int a,int b)///  count no of nodes after disconnecting grah byy
                            //deleting edge b/w node aand node b
 {
   queue<int>q;
   q.push(a);
   vis[a]=1;
   int start;
    int cou=0;
    while(!q.empty())
     {
       start=q.front();
       q.pop();
        cou++;
      
        list<int>:: iterator it;
        for(it=li[start].begin();it!=li[start].end();it++)
         {
          if(vis[*it]==0 && *it!=b) //because a and b is disconnected before calling bfs(a,b) 
           {
            vis[*it]=1;
            q.push(*it);
           }
          
         }
     }
     int cou1=0;
     start=b;
     q.push(b);
     vis[b]=1;
     while(!q.empty())
      {
         start=q.front();
         q.pop();
         cou1++;
         
         list<int> ::iterator it;
          for(it=li[start].begin();it!=li[start].end();it++)
           {
            if(vis[*it]==0  && *it!=a ) //because a and b is disconnected before calling bfs(a,b) 
             {
       vis[*it]=1;
       q.push(*it);
             
             }
           }
      }
      
if(cou1%2==0 && cou%2==0) c++;  // if both dissconected                                                                        //components  contain even                                                                // no  of nodes then increase
                                                        // count 
                                                           
                                                           
                                                                         
 }
int main()
 {
  int n,m;
   cin>>n>>m;
    for(int i=1;i<=m;i++)
     {
        int a,b;
         cin>>a>>b;
          li[a].push_back(b);
          li[b].push_back(a);
          has[a][b]=1;// has contain is there any edge b/w aandb;
           has[b][a]=1;
     }
     
     for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
         {
            if(i!=j && has[i][j]  && has[j][i])// means there is a                                                                                   edge is b/w i,j
             {
               for(int i=0;i<=n;i++) vis[i]=0;
                has[i][j]=0;//unhash 
                has[j][i]=0;// unhash
                   bfs(i,j);
                   
             }
         }
      }
      cout<<c<<endl;
  
 }
