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
    int a = 5; 
    
    int *b;
    cout<<b; // b = address of b
    cout << static_cast<int>(*b) << endl; // *b = value of b, which is unassigned
    b = &a; // b = address of a
    cout << *b << "wartość komorki na ktora wskazuje b" << endl; // *b = value of a
    *b  = 3;

    cout << a << "wartość  a" << endl; // a = value of b
    return 0;
}