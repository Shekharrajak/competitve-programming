#include <iostream>
using namespace std;

int fac(int r){
	int sum=1;
	if(r==0||r==1){
		return 1;
	}
	else{
		return r*fac(r-1);
	}
}
int main() {
int n;
	scanf("%d",&n);
	while(n--){
		int a,b;
		scanf("%d%d\n",&a,&b);
		printf("%d", (fac(a)/(fac(b)*fac(a-b))));
	}
	
		return 0;
}
