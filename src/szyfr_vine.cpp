#include <iostream>

using namespace std;

string table[26]={
"abcdefghijklmnopqrstuvwxyz",
"bcdefghijklmnopqrstuvwxyza",
"cdefghijklmnopqrstuvwxyzab",
"defghijklmnopqrstuvwxyzabc",
"efghijklmnopqrstuvwxyzabcd",
"fghijklmnopqrstuvwxyzabcde",
"ghijklmnopqrstuvwxyzabcdef",
"hijklmnopqrstuvwxyzabcdefg",
"ijklmnopqrstuvwxyzabcdefgh",
"jklmnopqrstuvwxyzabcdefghi",
"klmnopqrstuvwxyzabcdefghij",
"Imnopqrstuvwxyzabcdefghijk",
"mnopqrstuvwxyzabcdefghijkl",
"nopqrstuvwxyzabcdefghijklm",
"opqrstuvwxyzabcdefghijklmn",
"pqrstuvwxyzabcdefghijklmno",
"qrstuvwxyzabcdefghijklmnop",
"rstuvwxyzabcdefghijklmnopg",
"stuvwxyzabcdefghijklmnopqr",
"tuvwxyzabcdefghijklmnopqrs",
"uvwxyzabcdefghijklmnopqrst",
"vwxyzabcdefghijklmnopqrstu",
"wxyzabcdefghijklmnopqrstuv",
"xyzabcdefghijklmnopqrstuvw",
"yzabcdefghijklmnopqrstuvwx",
"zabcdefghijklmnopqrstuvwxy",
};

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

bool * crypt(string key, string file_name) 
{
    string to_crypt = read_file(file_name);
    bool * space = new bool[to_crypt.length()];
    for(int i = 0; i < to_crypt.length(); i++)
        space[i] = false;
    // get rid of spaces
    for(int i=0; i<to_crypt.length(); ++i)
        if(to_crypt[i]==' '){
            space[i] = true;
            to_crypt.erase(i,1);
        }     

    for(int i=0; i<key.length(); ++i)
        if(key[i]==' ')
            key.erase(i,1);

    for(int i=0; i<to_crypt.length(); ++i){
        char x, y;
        x = to_crypt[i];
        y = key[i%key.length()];
        int xi = x - 'a';
        int yi = y - 'a';
        cout <<  table[xi][yi] <<endl;
    }
    return space;
}

int main(int argc, char ** argv){
    crypt("ala", "tajna_wiadomosc.txt");
    return 0;
};
