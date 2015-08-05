#include <iostream>
#include<cstdio>


int main(int argc, char** argv) {
	int n,index=0;
	
	scanf("%d",&n);
	while(n--){
	int a[200];
		a[0]=1;
		int temp=0;
		int k;
		scanf("%d",k);
		for(;k>=2;k--){
			
			for(int i=0; i<=index;i++){
				temp+=(a[i]*k);
				a[i]=temp%10;
				temp/=10;
				
			}
			while(temp>0){
				a[++index]=temp%10;
				temp=temp/10;
			}
			
		}
		for(int i=index;i>=0;i--){
			printf("%d",a[i]);
		}
	}
	
	return 0;
}
/*
#include <iostream>
#include <algorithm>
#define size 200
using namespace std;
int main()
{
 int n,a[size],index,temp,i,t;
 scanf("%d",&t);
 while(t--)
 {
 a[0]=1;
 index=0;
 scanf("%d",&n);
 for(;n>=2;n--)
 {
 temp=0;
 for(i=0;i<=index;i++)
 {
 temp=(a[i]*n)+temp;
 a[i]=temp%10;
 temp=temp/10;
 }
 while(temp>0)
 {
 a[++index]=temp%10;
 temp=temp/10;
 }
 }
 for(i=index;i>=0;i--)
 printf("%d",a[i]);
 printf("\n");
 }
 return 0;
}

*/

