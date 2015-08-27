#include <iostream>
using namespace std;

int findPair(int *A , int n){
    int M[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            M[i][j] = 0;
        }
    }

}
int main()
{
    int tc,n;
    int *A;
    cin>>tc;
    while(tc--){
        cin>>n;
        A = new int[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        cout<<findpait(A,n)<<endl;

        delete[] A;
    }
    return 0;
}
