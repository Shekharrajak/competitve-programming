
#include <stdio.h>
#include <stdlib.h>

int main()
{
int comp,user,n,count=0;
scanf("%d%d",&comp,&user);
//int temp=comp;
//if((temp_r/x)%2 !=0){
if(comp == user){
    printf("win\n");
    return 0;
}
else{
    char *intComp ; itoa(comp,intComp,10);
    char *intUser = itoa(user);
    for(int i=0;i<sizeof(intComp)/sizeof(intComp[0]);i++){
        if(intComp[i] != intUser[i]){
            count++;
        }
    }
    if(count>1){
        printf("lose\n");
    }
}

    return 0;
}
