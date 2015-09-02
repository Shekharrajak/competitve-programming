#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
char comp[105];
int c=0;
cin>>comp;
bool flag =true;
string str = string(comp);
//cout<<str.length()<<endl;
for(int i=0;i<str.length();i++){
    for(int j=i;j<str.length()+1;j++){
        string str2 = str.substr (i,j);
       // cout<<str2<<" i= "<<i<<" j="<<j<<"  ";
            flag =true;
            if(str2.length() == 1){
                flag=true;
               // break;
            }
            else{
                for (int k=0; k<str2.length(); k++)
                {
                if(str2.at(k) != str2.at(0)){
                    flag=false;

                    }

                }
            }
            //cout<<flag<<endl;
            if(flag){
                c+=1;
            }
    }
}
cout<<c<<endl;

    return 0;
}
