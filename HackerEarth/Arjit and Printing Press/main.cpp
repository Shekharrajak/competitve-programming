#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        char s[maxn],t[maxn];
        cin>>s>>t;
        int cntl[26];
        for(int i=0;t[i];i++){
            cntl[t[i] - 'a']++;
        }
        for(int i=0;s[i];i++){
            for(int j=0;j<26;j++){
                if(cntl[j] >0 && ((j+'a') < s[i])){
                    //s[i]=j+'a';
                    s[i]=j+'a';
                    cntl[j]--;
                    break;
                }
            }
        }
        cout<<s<<endl;
std::memset(s, 0, sizeof s);
 std::memset(t, 0, sizeof t);
    }
return 0;
}
//
//bool myfunction (char i,char j) { return (i<j); }
//
//bool mycmp(char c1,char c2){
//    return tolower(c1)<tolower(c2);
//}
//void func(vector<char> v1,vector<char> v2){
//    int i=0,j=0;
//    for(int k=0;k<v1.size();k++){
//        if(mycmp(v1.at(i),v2.at(j))){
//            cout<<v1.at(i);
//            i++;
//
//        }
//        else{
//        for(int k1=j+1;k1<v2.size();k1++){
//        if(mycmp(v1.at(i),v2.at(k1))){
//
//
//        }
//        else{
//            char c = v2.at(k);
//            cout<<v2.at(k);
//            v2.erase(v2.begin()+k);
//            j++;
//
//        }
//    }
//    }
//    }
//    cout<<endl;
//
//}
//int main()
//{
//    int tc;
//    cin>>tc;
//    while(tc--){
//        char s[1005];
//        char t[1005];
//
//        cin>>s>>t;
//        //cout<<s<<" "<<t<<endl;
//        vector<char> v1,v2;
//        int i=0;
//        while(s[i]!='\0'){
//            v1.push_back(s[i]);
//           // v2.push_back(t[i]);
//            i++;
//        }
//        i =0;
//         while(t[i]!='\0'){
//         //   v1.push_back(s[i]);
//            v2.push_back(t[i]);
//            i++;
//        }
//        sort(v2.begin(),v2.end(),myfunction);
//        func(v1,v2);
//    }
//
//    return 0;
//}
