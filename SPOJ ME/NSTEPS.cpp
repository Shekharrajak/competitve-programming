#include <iostream>
#include<cstdio>
int main() {
	int n;
	scanf("%d",&n);
	while(n--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==b){
			if(a<2){
				printf("%d\n",a);
				
			}
			else if(a%2 != 0){
				printf("%d\n",2*a-1);
			}
			else{
				printf("%d\n",2*a);
			}
			
		}
		else if((a+b)%2 ==0){
			if(a%2 != 0){
				printf("%d\n" ,a+b-1 );
			}
			else{
				printf("%d\n" , a+b);
			}
		}
		else{
			printf("No Number\n");
		}
	}
	
	return 0;
}



/*

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int x,y,r,t;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        if(x==y)
        {
            if(x%2==0)
                r=2*x;
            else
                r=2*x-1;
            cout<<r<<endl;
        }
        else if(x==y+2)
        {
            if(x%2==0)
                r=x+y;
            else
                r=x+y-1;
            cout<<r<<endl;
        }
        else
            cout<<"No Number"<<endl;
    }
}
    

*/
