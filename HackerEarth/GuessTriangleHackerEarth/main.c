#include<stdio.h>
#include<stdlib.h>
main()
{
//clrscr();
float mx1,mx2,mx3,my1,my2,my3;

scanf("%f%f%f%f%f%f",&mx1,&my1,&mx2,&my2,&mx3,&my3);
//printf("%.2f*x + %.2f*y + %.2f*z + %.2f = 0",a,b,c,d);
//printf("%.2f*x + %.2f*y + %.2f*z + %.2f = 0",l,m,n,k);
//printf("%.2f*x + %.2f*y + %.2f*z + %.2f = 0",p,q,r,s);

float cx1 = mx1*2;//(x1+x2) = 2*mx1
float cx2 = mx2*2;//(x2+x3) = 2*mx2
float cx3 = mx3*2;//(x3+x1) = 2*mx3
float cy1 = my1*2;//(y1+y2) = 2*my1
float cy2 = my2*2;//(y3+x2) = 2*my1
float cy3 = my3*2;

float cxx3 = (cx1+cx2+cx3)/2;

float cyy3 = (cy1+cy2+cy3)/2;

float x1 = cxx3 - cx1;
float x2 = cxx3 - cx2;
float x3 = cxx3 - cx3;

float y1 = cyy3 - cy1;
float y2 = cyy3 - cy2;
float y3 = cyy3 - cy3;

printf("%.4f %.4f\n",x3,y3);
printf("%.4f %.4f\n",x1,y1);
printf("%.4f %.4f\n",x2,y2);
//getch();
return 0;
}

