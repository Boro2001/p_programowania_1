#include <iostream>

using namespace std;

void sum(int a, int b, int *c) { //pass by value
    *c =  a + b;
}

void sum(int *a, int *b , int *c) { //passing pointers
    *c = *a + *b;
}
// sum function passing by reference
void sum(int &a, int &b, int &c) {
    c = a + b;
}

int main(int argc, char * argv[])
{
    cout << argc << endl; // argc = number of arguments on the input line
    int a = argc; 
    int *b;
    cout<<b; // b = address of b
    cout << static_cast<int>(*b) << endl; // *b = value of b, which is unassigned
    b = &a; // b = address of a
    cout << static_cast<int>(*b) << endl; // *b = value of a

    int c = 0;
    sum(a, *b, &c); // we passed the address of c and the value of a and value of cell which is stored by b
    cout<<c<<endl;


    return 0;
}

