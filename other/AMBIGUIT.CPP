// Ambiguity in Multiple Inheritance

#include<iostream.h>
#include<conio.h>
class first
{
    public:
	   void disp()
	   {
	     cout<<"From Class A"<<endl;
	   }
};

class second
{
   public:
	  � void disp()
	    {
	      cout<<"From Class B"<<endl;
	    }
};

class third : public first,public second
{
};

void main()
{
   clrscr();
   third obj; // Object for Third Calss
   //obj.disp(); Ambiguity, will not compile
   obj.first::disp();
   obj.second::disp();
 getch();
}


