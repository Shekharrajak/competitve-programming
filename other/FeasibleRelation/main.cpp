#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct rel{
    int l=0;
    int r=0;
    int data;
};
int main()
{
     char input[16] = "abc,d";
    char *p;
    p = strtok(input, ",");

    if(p)
    {
    printf("%s\n", p);
    }
    p = strtok(NULL, ",");

    if(p)
           printf("%s\n", p);

    int tc;
    cin>>tc;
    while(tc--){
        int n,k;
        cin>>n>>k;
        rel r[n];
        for(int i=0;i<k;i++){
            char s[(n*(n-1)/2)];
            cin>>s;
           // cout<<s<<endl;
           while(s != '\n')
            {char* p;
            p=strtok(s, " != ");
            if(!p) p=strtok(s, " = ");
            if(p){

                printf("%s\n",p);
            }
            p=strtok(NULL," != ");
            if(!p) p=strtok(s,"!=");
            if(p){
                printf("%s\n",p);
            }

        }
        }

    }
    return 0;
}
