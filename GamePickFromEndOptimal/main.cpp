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


pair<int ,int> dp(int val[]){
    vector<vector<pair<int,int> > > vec;

    int s =sizeof(val)/sizeof(val[0]);
    int l=1;
    while(l<s+1){
        if(l==1){
             for(int i =1;i<=s ;i++){
        vec[i][i].first = val[i];
        vec[i][i].second = 0;

        }
        cout<<endl<<endl;
         for(int i =1;i<=s ;i++){
            for(int j=1;j<=s ; j++){
                cout<<vec[i][j].first<<","<<vec[i][j].second<<"  ";
            }
            cout<<endl;

        }

    }
        else{
            for(int i =1;;i++){
                vec[i][i+l-1].first = max(
                                    (vec[i][i].first + vec[i+1][i+l-1].second),
                                    (vec[i+l-1][i+l-1].first + vec[i][i+l-2].second)
                                  );
                 vec[i][i+l-1].second = (vec[i][i+l-1].first == (vec[i][i].first + vec[i+1][i+l-1].second) ? vec[i+1][i+l-1].first : vec[i][i+l-2].first);
                if((i+l-1 )== s){
                    break;
                }
            }
        }
        l++;
    }
            cout<<endl<<endl;
         for(int i =1;i<=s ;i++){
            for(int j=1;j<=s ; j++){
                cout<<vec[i][j].first<<","<<vec[i][j].second<<"  ";
            }
            cout<<endl;

        }

    return vec[1][s];
}
int main()
{
    int pots,temp;
    cin>>pots;

    int *val;

    for(int i =1;i<=pots;i++){
        cin>>temp;
        val[i] = temp;;
    }
    for(int i =1;i<=pots;i++){
        cout<<val[i];
    }
    pair<int,int> ans = dp(val);
    cout<<ans.first <<" "<<ans.second;

}


/*
pair<int ,int> dp(vector<int> val){
    vector<pair<int,int> > vec[val.size()+1];

    int l=1;
    while(l<(int)val.size()+1){
        if(l==1){
             for(int i =1;i<=val.size() ;i++){
        vec[i][i].first = val[i];
        vec[i][i].second = 0;

        }
        cout<<endl<<endl;
         for(int i =1;i<=val.size() ;i++){
            for(int j=1;j<=val.size() ; j++){
                cout<<vec[i][j].first<<","<<vec[i][j].second<<"  ";
            }
            cout<<endl;

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
        l++;
    }
            cout<<endl<<endl;
         for(int i =1;i<=val.size() ;i++){
            for(int j=1;j<=val.size() ; j++){
                cout<<vec[i][j].first<<","<<vec[i][j].second<<"  ";
            }
            cout<<endl;

        }

    return vec[1][val.size()];
}
int main()
{
    int pots,temp;
    cin>>pots;

    vector<int> val;

    for(int i =1;i<=pots;i++){
        cin>>temp;
        val.push_back(temp);
    }
    vector<int> :: iterator itr = val.begin();
    while(itr != val.end()){
        cout<<*itr<<" ";
        itr++;
    }
    for(int i =1;i<=pots;i++){
        cout<<val[i];
    }
    pair<int,int> ans = dp(val);
    cout<<ans.first <<" "<<ans.second;

}
*/
