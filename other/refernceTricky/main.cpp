#include <iostream>
    using namespace std;
    int main()
    {
        int a = 9;
        int & aref = a;
        //a++;
        ++a;
        cout << "The value of a is " << aref;
        return 0;
    }
