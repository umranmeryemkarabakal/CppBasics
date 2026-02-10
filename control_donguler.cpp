#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    // <, >, <=, >=, ==, !=
    if (a>5) {cout << "5ten buyuktur" << endl;}
    else if (a==5) {cout << "5e esittir" << endl;}
    else {cout << "5ten kucuktur" << endl;}

    switch(a){
        case 1 : cout << "a 1e esittir" << endl;
            break; // en exits the switch
        case 5 : cout << "a 5e esittir" << endl;
            break;
        default : cout << "a ne 1e ne 5e esittir" << endl;
    }

    a = 0;
    while(a<10){
        cout << "merhaba while" << a << endl;
        a++; 
    }
    cout << "dongu bitti" << a<< endl;

    for (int i=0 ; i<10 ; i++){
        cout << "merhaba for" << i << endl;
    }

    int x=100;
    do {
        cout << "merhaba do-while" << x << endl;
        x++;
    }
    while(x<10);
    cout << "dongu bitti" << x << endl;

    return 0;
}