#include<stdio.h>
int main()
{
FILE *fp;
int words=0,lines=0,chars=0;
char prev,curr;
fp=fopen("1.txt","r");
while(fscanf(fp,"%c",&curr)!=EOF)
{
chars++;
if(curr=='\n')
lines++;
if((curr==' ')||(curr=='\n'))
words++;
prev=curr;
}
printf("%d %d %d",chars,lines,words);
return 0;
}

