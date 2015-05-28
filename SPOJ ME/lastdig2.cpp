#include<stdio.h> 
#include<cstring>
int main() {
	long long int b;
	int c,l,ans=1,i,t,j;
	char a[1000]; 
	scanf("%d",&t);
	for(j=0;j<t;j++) {
		ans=1; 
		scanf("%s",a);
		scanf("%lld",&b); 
		l=strlen(a);
		c=(a[l-1]-'0');
		if(c==0) {
			printf("0\n"); 
			
		} else { 
			b=b%4; 
			for(i=0;i<b;i++) {
				ans=ans*c; 
				
			} 
			ans=ans%10;
			printf("%d\n",ans); 
			
		} 
		
	}
	return 0;
	} 
