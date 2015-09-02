#include <iostream>
using namespace std;

int main()
{
    char str[1010];
    cin>>str;
    char ch = str[0];
    int cnt=1;
    int ans=0;
    for(int i=1;str[i]!='\0';i++)
    {
    	if(ch == str[i])
    	cnt++;
    	else
    	{
    		ans=ans+((cnt*(cnt+1))/2);
    		cnt=1;
    		ch = str[i];
    	}
    }
    ans+=(((cnt+1)*cnt)/2);
    cout<<ans<<endl;
    return 0;
}
