#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int distance(string s , string t){
    int m = s.length();
    int n = t.length();
    int dp[m][n];
//    char s[m+1],t[n+1];
////    std::size_t length = st.copy(s,m,0);
////  s[length]='\0';
////  std::size_t length2 = tg.copy(t,n,0);
////  tg[length2]='\0';
//    strcpy(s,st);
//    strcpy(t,tg);
//    s[m+1]='\0';
//    t[n+1]='\0';
    //strcpy(s,c_str(st));
    //strcpy(t,c_str(tg));
    for(int i=0;i<m;i++){
        for(int j =0 ;j<n;j++){
            dp[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        dp[i][0]=i;
    }

    for(int i=0;i<n;i++){
        dp[0][i]=i;
    }
    for(int j=1;j<n;j++){
        for(int i=0;i<m;i++){
            if(s[i] == t[i]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(min(dp[i-1][j]+1 , dp[i][j-1]+1),dp[i-1][j-1]+1);
            }
        }
    }
    return dp[m][n];

}
int main()
{
int tc;
scanf("%d",&tc);
while(tc--){

string st,tg;
    cin>>st>>tg;
    cout<<distance(st ,tg)<<endl;
}
    return 0;
}
