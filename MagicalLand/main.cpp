#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//
//typedef struct res{
//    int i;int j;int sum;
//}res;
//
//int kadane(int a[],int i1,int j1,int n,int k){
//    int i;
//    res max_curr,result;//*max_sum;
//    //max_sum = new res();
//        int max_= INT_MIN;
//    max_curr.sum = INT_MIN;
//
//    for(int i=i1;i<=j1;i++){
//        if(max_curr.sum<0){
//            max_curr.sum = a[i];
//            max_curr.i=i;
//            max_curr.j=i;
//        }
//        else{
//            max_curr.sum +=a[i];
//            max_curr.j=i;
//        }
//        if(max_curr.sum > max_){
//            max_ = max_curr.sum;
//            result = max_curr;
//
//        }
//         if(k == abs(result.j - result.i )){
//]
//                return result.sum;
//            }
//            else{
//                kadane(a,result.i,result.j,n,k);
//            }
//
//        //max_sub[i] =max_;
//
//    }
//}
bool Checkgcd(int value1, int value2)
{
    while (value1 != 0 && value2 != 0)
    {
        if (value1 > value2)
            value1 %= value2;
        else
            value2 %= value1;
    }
    int r= max(value1, value2);
    if(r!=1){
        return true;
    }
    else{
        return false;
    }
}
void magicland(int n,int m,int k,int key[],int chest[],int gem[]){
    int mat[n];
    int check[m];
    for(int i=0;i<m;i++){
        check[i]= 0;
    }
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<m;j++){
            if(Checkgcd(key[i],chest[j]) && !check[j]){
                count+=gem[j];
                check[j]=1;
            }
            mat[i] =count;
        }

    }
    std::sort(mat,mat+n);
     int count1=0;
    for(int i=n-1;i>=n-k;i--){
        count1+=mat[i];
    }
    cout<<count1<<endl;


}
int main()
{
    int t,n,m,k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int key[n],chest[m],gem[m];
        for(int i =0 ;i<n;i++){
            cin>>key[i];
        }
        for(int i =0;i<m;i++){
            cin>>chest[i];
        }

        for(int i =0;i<m;i++){
            cin>>gem[i];
        }
        magicland(n,m,k,key,chest,gem);


    }
    return 0;
}
