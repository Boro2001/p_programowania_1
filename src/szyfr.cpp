#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

// boyer-moore algorithm
// https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_string-search_algorithm
/*
Działanie programu:
1. Program czyta tekst z pliku o nazwie "tekst.txt"
2. Użytkownik podaje wzorzec
3. Program zapisuje wszystkie wystąpienia wzorca w pliku "wynik.txt" w postaci:
*/

using namespace std;

int cout_occurances_in_file(string file_name){

    FILE *file = fopen(file_name.c_str(), "rw");

    if(file == NULL){
        cout << "File not found" << endl;
        return 0;
    }
    else{
        // read file
        char c;
        int y = 0;
        int x = 0;

        while((c = fgetc(file)) != EOF){ // EOF = End Of File
            cout<<c;
            x++;
            if(c == '\n'){
                ++x;
                ++y;
            }
        }
        ++y;
        x = x / y;
        cout << "\nNumber of lines: " << y << endl;
        cout << "Number of characters in line: " << x << endl;

    }
};



int main(int argc, char * argv[])
{
    cout_occurances_in_file("text.txt");

    char a = 'a';
    char b = '\n';
    char c = EOF;
    return 0;
}