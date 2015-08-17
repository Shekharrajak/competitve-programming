#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void generate(char * str, int x ,int y){
    if(x == y-1){
        cout<<str<<endl;
        return;
    }
    else{
        for(int i=x;i<y;i++)
            {
            swap(str[x],str[i]);
            generate(str ,x+1,y);
            swap(str[x],str[i]);
            }

    }
    return;
}
int main()
{
    //cout << "Hello world!" << endl;
    char * str;
    int s;
    cin>>s;
    str = new char[s];
    cin>>str;
    cout<<strlen(str)<<endl;
    generate(str,0,strlen(str));

    return 0;
}
