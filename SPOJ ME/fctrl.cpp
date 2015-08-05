#include <iostream>
#include<math.h>
#include<stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int k,n;
	scanf("%d",&n);
	while(n--){
	 scanf("%d",&k);
		int count=0;
		int i=1;
		int l=k;
		while(l!=0){
			count+=k/pow(5,i);
			
			i++;
				l/=pow(5,i);
		
		}
		printf("%d\n",count);
	}
	return 0;
}

/*

#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
 int t,n,count;
 scanf("%d",&t);
 while(t--)
 {
 count=0;
 scanf("%d",&n);
 while(n>=5)
 {
 count += n/5;
 n /= 5;
 }
 printf("%d\n",count);
 }
 return 0;
}
*/
