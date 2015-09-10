#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
long int n;
cin>>n;
char s[n];
cin>>s;
int i=0,w=0,v=0,m=0,n1=0;
while(i!=n){
    if(s[i] == 'v'){v++;}
    else if(s[i] =='w'){w++;}
    else if(s[i] == 'm'){m++;}
    else if(s[i] =='n'){n1++;}
    i++;
}

int maxi=n,mini=n;
//if(v && (v&(v-1)) == 0){
//    mini-=(v/2);
//}
//else{
    mini-=(v/2);
    mini-=(n/2);
//}
//if(w && (w&(w-1))== 0){
//    maxi+=w;
//}
//else{
    maxi+=w;
    maxi+=m;

//}
cout<<mini<<" "<<maxi<<endl;

return 0;
}
