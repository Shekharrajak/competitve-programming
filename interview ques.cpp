#include <stdlib.h>
using namespace std;
int main(){
	long long int time;
	cout<<"Enter the time after which pc should shut down :"<<endl;
	cin>>time;
	while(time--){
		system("explorer C:\\user\\desktop\\shutdown_icon"); //the shortcut icon which contains :"  shutdown -s -t 0 "
	}

return 2;
}
