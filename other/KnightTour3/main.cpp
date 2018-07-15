
/*
Objec­tive : A knight’s tour is a sequence of moves of a knight on a chess­board such that the knight vis­its
every square only once. If the knight ends on a square that is one knight’s move from the begin­ning square (so
 that it could tour the board again imme­di­ately, fol­low­ing the same path), the tour is closed, oth­er­wise it is open.
 (Source : http://en.wikipedia.org/wiki/Knight%27s_tour)


*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool canMove(int x,int y,int n ,int ** mat){
    if(x>=0 && y >=0 && x<n && y<n && mat[x][y] == 0){
        return true;
    }
    return false;
}
bool solveKnightUtil(int **mat , int x, int y, int index,int n){
    if(index == n*n-1){
        mat[x][y] =index;
        return true;
    }
    else{
          mat[x][y] =index;

        if(canMove(x+1,y-2,n,mat) && solveKnightUtil(mat,x+1,y-2,index+1,n)){
            return true;
        }
         if(canMove(x+2,y-1,n,mat) && solveKnightUtil(mat,x+2,y-1,index+1,n)){
            return true;
        }
         if(canMove(x-1,y-2,n,mat) && solveKnightUtil(mat,x-1,y-2,index+1,n)){
            return true;
        }
         if(canMove(x-2,y-1,n,mat) && solveKnightUtil(mat,x-2,y-1,index+1,n)){
            return true;
        }
        if(canMove(x+1,y+2,n,mat) && solveKnightUtil(mat,x+1,y+2,index+1,n)){
            return true;
        }
        if(canMove(x+2,y+1,n,mat) && solveKnightUtil(mat,x+2,y+1,index+1,n)){
            return true;
        }
        if(canMove(x-1,y+2,n,mat) && solveKnightUtil(mat,x-1,y+2,index+1,n)){
            return true;
        }
        if(canMove(x-2,y+1,n,mat) && solveKnightUtil(mat,x-2,y+1,index+1,n)){
            return true;
        }
        else{
            mat[x][y] =0;
            index--;
            return false;
        }

    }


}
void print(int **mat){
    int s =sizeof(mat);
    cout<<s<<endl;
    //int s = sizeof((int*)*mat)/sizeof((int*)mat[0]);
    //cout<<s<<endl;
    for(int i =0;i<s;i++){
        for(int j=0;j<s;j++){
            cout<<"  "<<mat[i][j];
        }
        cout<<"\n";
    }
}
void solveKnight(int n){
    int **mat;
    mat = new int*[n];

    for(int i=0;i<n;i++){
        mat[i] =new int[n];
        for(int j=0;j<n;j++){
            mat[i][j]=0;
        }
    }
    if(solveKnightUtil(mat,0,0,0,n) == true){
        print(mat);
        return;
    }
    else{
        cout<<"Can't traversal \n";
        return;
    }

    for(int i =0;i<n;++i){
        delete[] mat[i];
        }
    delete[] mat;
}
int main()
{
    //cout << "Hello world!" << endl;
    int n;
    cin>>n;
    solveKnight(n);
    return 0;
}
