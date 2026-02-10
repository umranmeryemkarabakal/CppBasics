#include <iostream>

using namespace std;

int boyut(char *s){
    int b=0;
    char c = s[0];
    while(c != '\0'){
        c = s[++b];
    }
    return b;
}

int main(){
    const char *c = "umran";
    string c1 = "meryem";
    char c3[] = "05";

    char a[6];
    a[0] = 'u'; // Tek tırnak kullanıyoruz
    a[1] = 'm';
    a[2] = 'r';
    a[3] = 'a';
    a[4] = 'n';
    a[5] = '\0';
    cout << a << endl;

    c1 = c;
    c1 = "hello";
    cout << c1 << endl;

    string s1 = "umran";
    string &s2 = s1;
    cout << s1 << endl;
    cout << s2 << endl;
    s2 = "meryem";
    cout << s1 << endl;
    cout << s2 << endl;

    if(strcmp(s1, s2)==0){
        cout << "Eşit" << endl;
    } else {
        cout << "Eşit değil" << endl;
    }
    //c[2] = 'x'; hata verir const
    cout << boyut(s1) << endl;
    //cout << boyut(c1) << endl;
    return 0;
}