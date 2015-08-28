 #include <iostream>
    using namespace std;
    void swap(int *a, int *b);
    void swap2(int &a, int &b);
    void ref(int &a,int &b);
int main()
    {
        int a = 5, b = 10;
        ref(a, b);
        swap(&a, &b);
        swap2(a, b);//both swap are correct
        cout << "In main " << a << b;
        return 0;
    }
    void swap(int *a, int *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
        cout << "In swap " << *a << *b<<endl;
    }
     void swap2(int &a, int &b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
        cout << "In swap 2 :" << a << b<<endl;
    }
    void ref(int &a, int &b)
    {

        cout << "In ref a,b " << a << b<<endl;
        cout << "In ref &a,&b" << &a << &b<<endl;

    }
