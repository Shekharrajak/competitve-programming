#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
char comp[1000000],user[1000000],n,count=0;
cin>>comp>>user;
//int temp=comp;
//if((temp_r/x)%2 !=0){
//if(comp == user){
//    cout<<"win"<<endl;
//    return 0;
//}

    //char *intComp ; itoa(comp,intComp,10);
    //char *intUser = itoa(user);
    //cout<<sizeof(comp)/sizeof(comp[0])<<endl;
    for(int i=0;comp[i]!='\0';i++){
        if(comp[i] != user[i]){
            count++;
        }
    }
    if(count>1){
        cout<<"lose"<<endl;
        return 0;
    }
    cout<<"win"<<endl;


    return 0;
}









//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//int comp,user,n,count=0;
//cin>>comp>>user;
////int temp=comp;
////if((temp_r/x)%2 !=0){
//if(comp == user){
//    cout<<"win"<<endl;
//    return 0;
//}
//else{
//    char *intComp ; itoa(comp,intComp,10);
//    char *intUser = itoa(user);
//    for(int i=0;i<sizeof(intComp)/sizeof(intComp[0]);i++){
//        if(intComp[i] != intUser[i]){
//            count++;
//        }
//    }
//    if(count>1){
//        cout<<"lose"<<endl;
//    }
//}
//
//    return 0;
//}
