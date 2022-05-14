#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;


void print_table(char ** tablica, int table_width, int table_height){
    for(int i = 0; i < table_height; ++i){
        for(int j = 0; j < table_width; ++j){
            cout << tablica[i][j];
        }
        cout << endl;
    }
}
char ** make_table(int table_width, int table_height){
    char ** tablica = new char*[table_height];
    for(int i = 0; i < table_height; ++i){
        tablica[i] = new char[table_width];
    }
    return tablica;
}
char ** flip_table(char ** tablica, int table_width, int table_height){
    char ** flipped_table = new char * [table_width]; 
    for(int i = 0; i < table_width; ++i) flipped_table[i] = new char[table_height];

    for(int i = 0; i < table_width; ++i){
        for(int j = 0; j < table_height; ++j){
            flipped_table[i][j] = tablica[table_height - j - 1][i];
        }
    }
    return flipped_table;
}
int find_pattern(char ** tablica, int table_width, int table_height, string pattern, bool flipped)
{
    int count = 0;
    int pattern_length = pattern.length();
    print_table(tablica, table_width, table_height);
    for(int i = 0; i < table_height; ++i){
        for(int j = 0; j < table_width - pattern_length + 1; ++j){
            bool found = true;
            for(int k = 0; k < pattern_length; ++k){
                if(tablica[i][j + k] != pattern[k]){
                    found = false;
                    break;
                }
            }
            if(found) {
                if(!flipped)
                    {++count; cout << "found at " << i << " " << j << endl;}
                else
                    {++count; cout << "found at " << table_height - j - 1 << " " << i << endl;}
                }
        }
    }
    return count;
}
int count_occurances_in_file(string file_name, string pattern, int x, int y)
{
    char c; int n = 0;
    char ** tablica = make_table(x, y);

    FILE *file = fopen(file_name.c_str(), "r");
    if(file == NULL) return 0;
    while((c = fgetc(file)) != EOF)
        if(c!='\n'){
            tablica[n/x][n%x] = c;
            ++n;
        }
    fclose(file); 

    return find_pattern(tablica, x, y, pattern, false) + find_pattern(flip_table(tablica, x, y), y, x, pattern, true);


    return 0;
}





int main(int argc, char * argv[])
{
    string pattern = argv[1]; 
    string file_name = argv[2];
    int table_width = atoi(argv[3]);
    int table_height = atoi(argv[4]);
    cout << "pattern: " << pattern << endl;
    cout << "file: " << file_name << endl;
    cout << "table_width: " << table_width << endl;
    cout << "table_height: " << table_height << endl;

    int count = count_occurances_in_file(file_name, pattern, table_width, table_height);
    return 0;
}