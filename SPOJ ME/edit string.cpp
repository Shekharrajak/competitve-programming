#include <stdio.h> 
#include <iostream>
#include<string.h>
using namespace std;
int smallest(int a,int b) {
	if(a<b) return a; else return b;
	} 
int main()
{
	int t; 
	char a[2100];
	char b[2100];
	static int dp[20001][2001]; 
	scanf("%d",&t); 
	for(int x=0;x<t;x++)
	{
		int len_a,len_b;
		scanf("%s",a);
		scanf("%s",b); 
		len_a=strlen(a);
		len_b=strlen(b);
		dp[0][0]=0;
		for(int i=1;i<=len_a;i++) 
		{
			dp[i][0]=i;
			}
			for(int j=1;j<=len_b;j++)
			{
				dp[0][j]=j; }
				for(int i=1;i<=len_a;i++)
				{
					for(int j=1;j<=len_b;j++) 
					{
						int a1,a2; 
						if(a[i-1]==b[j-1])
							a1=dp[i-1][j-1];
						else
							a1=dp[i-1][j-1]+1;
					a2=smallest(dp[i-1][j],dp[i][j-1])+1;
					dp[i][j]=smallest(a1, a2);
					}
				}
			printf("%d\n",dp[len_a][len_b]);
	} return 0;
} 
