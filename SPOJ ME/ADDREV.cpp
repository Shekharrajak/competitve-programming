#include <iostream>
using namespace std;

int rev(int k){
	int r=0;
	for(;k!=0;){
		// r =r*10;
		r=r*10+k%10;
		k/=10;
	}
	return r;
}

int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
//	printf("%d",n);
int j=0,a[n][2];

for(int i =0 ;i<n;i++){
	scanf("%d%d", &a[i][j++],&a[i][j--]);
	//printf("%d\t%d\n",a[i][j++],a[i][j--]);
}	
//int r=0;

j=0;


for(int i=0;i<n;i++){
	printf("%d\n",rev(rev(a[i][j++])+rev(a[i][j--])) );
}

	return 0;
}

/*


#include <iostream>
#include <algorithm>
 
using namespace std;
int rev(int n)
{
int r=0;
while(n>0)
{
r=r*10+(n%10);
n/=10;
}
return r;
}
int main()
{
int t,n1,n2;
scanf("%d",&t);
while(t--)
{
scanf("%d%d",&n1,&n2);
printf("%d\n",rev(rev(n1)+rev(n2)));
}
return 0;
}
*/
