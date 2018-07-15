// Demonstration of Hybrid Inheritance

#include<iostream.h>
#include<conio.h>
class student
{
    protected:
                       int htno;
                       char name[20];
    public:
                 void getdata()
                 {
                     cout<<"Enter Htno,Name\n";
                     cin>>htno>>name;
                 }
                 void disp()
                 {
	    cout<<"\n\nHtno = "<<htno<<"\tName = "<<name;
                 }
};

class derived1:public student
{
   protected:
                       float m1,m2,m3;
   public:
                 void getdata()
                 {
                     cout<<"Enter Marks in 3 Subjects\n";
                     cin>>m1>>m2>>m3;
                 }
};

class derived2:public derived1
{
   protected:
                     float tot,avg;
   public:
                void calculate()
                {
                    tot=m1+m2+m3;
                    avg=tot/3;  
                }   
                void disp()
                {
                   cout<<"\nTotal = "<<tot<<"\tAverage = "<<avg;
                }
};

class details
{
    protected:
                       char gender[8],qual[30];
    public:
                    void getdata()
                    {
                        cout<<"Enter Gender and Educational Qualification\n";
                        cin>>gender>>qual;
                    }
                    void disp()
                    {
                        cout<<"\nGender = "<<gender<<"\tQualification = "<<qual;
                    }
};

class child:public derived2,public details
{
    public:
                 void getdata()
                 {
                     student::getdata();
                     derived1::getdata();
                     derived2::calculate();      
                     details::getdata();
                 }
                 void disp()
                 {
                     student::disp(); 
                     details::disp();
                     derived2::disp();
                 }
};

void main()
{
    clrscr();
    child ch;
    ch.getdata();
    ch.disp(); 
  getch();
}