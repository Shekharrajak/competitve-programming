/*
N pots, each with some number of gold coins, are arranged in a line. You are playing a game against
 another player. You take turns picking a pot of gold. You may pick a pot from either end of the line,
  remove the pot,
 and keep the gold pieces. The player with the most gold at the end wins. Develop a strategy for
  playing this game.
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int ,int> dp(vector<int> val){
    vector<pair<int,int> > vec[val.size()+1];

    int l=1;
    while(l<val.size()+1){
        if(l==1){
             for(int i =1;i<=val.size() ;i++){
        vec[i][i].first = val[i];
        vec[i][i].second = 0;

        }

    }
        else{
            for(int i =1;;i++){
                vec[i][i+l-1].first = max(
                                    (vec[i][i].first + vec[i+1][i+l-1].second),
                                    (vec[i+l-1][i+l-1].first + vec[i][i+l-2].second)
                                  );
                 vec[i][i+l-1].second = (vec[i][i+l-1].first == (vec[i][i].first + vec[i+1][i+l-1].second) ? vec[i+1][i+l-1].first : vec[i][i+l-2].first);
                if((i+l-1 )== val.size()){
                    break;
                }
            }
        }
    }
    vec[1][val.size()+1];
}
int main()
{
    int pots;
    cin>>pots;

    vector<int> val;
    for(int i =1;i<=pots;i++){
        cin>>val[i];
    }
    pair<int,int> ans = dp(val);
    cout<<ans.first <<" "<<ans.second;

}
