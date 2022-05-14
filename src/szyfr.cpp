#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyz"; int alphabet_length = 26; //global variables

int get_index(int i, int shift){ // getting new index int, int  -> int
    if (shift > 0){
        return (i + shift) % alphabet_length;
    }
    else if (shift < 0){
        return (i + shift + alphabet_length) % alphabet_length;
    }
    else{
        return i;
    }
}

void crypt(string s, int shift) {
    for (int i = 0; i < s.length(); i++) {  
        s[i] = tolower(s[i]); //convert to lowercase
        int index = s[i] - 'a'; //get index of letter in alphabet
        int new_index = get_index(index, shift); //get new index
        s[i] = alphabet[new_index]; //get new letter
    }
    cout << s << endl;
}

string read_file(string file_name)
{
    char c;
    string s = "";
    FILE *file = fopen(file_name.c_str(), "r");
    if (file == NULL)
    {
        cout << "Error opening file";
        exit(1);
    }
    while((c = fgetc(file)) != EOF && c!='\n')
        s.append(1, c);
    fclose(file);
    return s;
}

int main(int argc, char * argv[]){
    int shift = -3; 
    crypt(read_file("key.txt"), shift);
    return 0;
}