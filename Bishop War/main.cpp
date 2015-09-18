#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 10

bool findcell(int row,int col,int index,int n1,int m1);
int c=0,lock[MAX][MAX];
char mat[MAX][MAX];
void solve(int row,int col,int index,int n1,int m1){
    int count=0;
    for(int i=row;i<n1;i++){
        if(findcell(row,col,index,n1,m1)){
            //count++;
           // cout<<"done findcell last step"<<endl;
            cout<<c<<endl;
        }
    }
    //cout<<count<<endl;
}


bool canMove(int row,int col,int n1,int m1){
    if(row>=0 && col>=0 && row<n1 && col<m1 && (mat[row][col] == '.') && (lock[row][col] != -1) ){
         if(lock[row+2][col+1] != -2 &&
            lock[row+1][col+2] != -2 &&
            lock[row-1][col+2] != -2 &&
            lock[row-1][col-2] != -2 &&
            lock[row-2][col+1] != -2 &&
            lock[row-2][col-1] != -2 &&
            lock[row+1][col-2] != -2 &&
            lock[row+2][col-1] != -2 )

        {return true;}
    }
    return false;
}

bool findcell(int row,int col,int index,int n1,int m1)
{
//    if(mat[row][col] != '.'){
//        return false;
//    }
    //mat[row][col]=
  //  cout<<"in findcell"<<endl;
   if(canMove(row,col,n1,m1)){
//cout<<"in findcell2"<<endl;
        lock[row][col]=-2;
         lock[row+2][col+1] = -1;
         lock[row+1][col+2] = -1;
         if(row>1)
            {lock[row-1][col+2] = -1;
            lock[row-1][col-2] = -1;
            }
         if(row>2)
            {
            lock[row-2][col+1] = -1;
            lock[row-2][col-1] = -1;
            }
        if(col>2)
            {lock[row+1][col-2] = -1;}
         if(col>1)
           {lock[row+2][col-1] = -1;}
         c++;
    //     cout<<"in findcell3"<<endl;

   }

 //cout<<"in findcell"<<endl;
    if(index == n1*m1-1){

    }
//    if(canMove(row,col,n1,m1) &&findcell(row+2,col+1,index+1,n1,m1)){lock[row+2][col+1]=-1;return true;}
//    if(canMove(row+1,col+2,n1,m1) && findcell(row+1,col+2,index+1,n1,m1)){lock[row+1][col+2]=-1;return true;}
//    if(canMove(row-1,col+2,n1,m1) && findcell(row-1,col+2,index+1,n1,m1)){lock[row-1][col+2]=-1;return true;}
//    if(canMove(row-2,col+1,n1,m1) && findcell(row-2,col+1,index+1,n1,m1)){lock[row-2][col+1]=-1;return true;}
//    if(canMove(row-2,col-1,n1,m1) && findcell(row-2,col-1,index+1,n1,m1)){lock[row-2][col-1]=-1;return true;}
//    if(canMove(row-1,col-2,n1,m1) && findcell(row-1,col-2,index+1,n1,m1)){lock[row-1][col-2]=-1;return true;}
//    if(canMove(row+1,col-2,n1,m1) && findcell(row+1,col-2,index+1,n1,m1)){lock[row+1][col-2]=-1;return true;}
//    if(canMove(row+2,col-1,n1,m1) && findcell(row+2,col-1,index+1,n1,m1)){lock[row+2][col-1]=-1;return true;}
//
for(int k1=row+1;k1<n1;k1++){
    for(int k2=-9;col+k2<m1,col+k2>=0;k2++){
     //cout<<"in findcell"<<endl;
    if(canMove(row+k1,col+k2,n1,m1) && findcell(row+k1,col+k2,index+1,n1,m1)){return true;}
    }
}
//    if(canMove(row+1,col+2,n1,m1) && findcell(row+1,col+2,index+1,n1,m1)){return true;}
//    if(canMove(row-1,col+2,n1,m1) && findcell(row-1,col+2,index+1,n1,m1)){return true;}
//    if(canMove(row-2,col+1,n1,m1) && findcell(row-2,col+1,index+1,n1,m1)){return true;}
//    if(canMove(row-2,col-1,n1,m1) && findcell(row-2,col-1,index+1,n1,m1)){return true;}
//    if(canMove(row-1,col-2,n1,m1) && findcell(row-1,col-2,index+1,n1,m1)){return true;}
//    if(canMove(row+1,col-2,n1,m1) && findcell(row+1,col-2,index+1,n1,m1)){return true;}
//    if(canMove(row+2,col-1,n1,m1) && findcell(row+2,col-1,index+1,n1,m1)){return true;}
//
    c--;
    lock[row][col]=0;
         lock[row+2][col+1] = 0;
         lock[row+1][col+2] = 0;
         if(row>1)
            {lock[row-1][col+2] = 0;
            lock[row-1][col-2] = 0;
            }
         if(row>2)
            {
            lock[row-2][col+1] = 0;
            lock[row-2][col-1] = 0;
            }
        if(col>2)
            {lock[row+1][col-2] = 0;}
         if(col>1)
           {lock[row+2][col-1] = 0;}
    return false;
}


int main()
{
    int n,m;
    cin>>n>>m;
    //char mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
//    cout<<"done mat filling"<<endl;
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            cout<<mat[i][j];
//        }
//        cout<<"\n";
//    }
    solve(0,0,0,n,m);

    return 0;
}
