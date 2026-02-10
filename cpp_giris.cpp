#include <iostream>

using namespace std;

// single line comment
/* multi line comment */

int main() 
{
    
    int a; // tipi, ismi
    a = 10; // variable: degisken
    cout << a << endl; // endl: end of line aalt satıra geç
    a=20; // atama, assignment
    cout << "Hello world!" << a << endl;    
    int b = 30; // statement: ifade
    int x=2, y=10, z;
    cout << z << endl;
    
    float pi = 3.14;
    long tl = 2386482658;
    char chr = 'x';
    bool isTrue = false;
    
    int cc = chr;
    cout << cc << endl; // c karakterinin asci değeri
    
    int ipi = pi;
    cout << ipi << endl; // pi'nin tam sayı kısmı, yuvarlama yapmaz
    
    int randi = 2.5;
    float randf = randi;
    cout << randf << endl; // 2.0
    
    int at = 64;
    char ch = at;
    cout << ch << endl; // 'A' karakteri
    cout << (char)ch << endl; // type casting
    cout << (char)65 << endl; // 'A' karakteri
    
    at ++; // bir artırır postfix
    cout << a << endl;
    ++ at; // increment bir artırır prefix
    cout << a << endl;
    
    b = 20;
    cout << a+b << endl;
    
    at --;
    at = at - 1;
    at -= 5; // at = at -5
    at *= 2; // at = at *2 
    cout << at << endl;
    
    cout << 15%2 << endl; // remainder, modulo 15/2 = 7.5 15%2 = 1
    
    cout << b++ << endl; // b=20, cout 20, b=21, b'nin degeri alınıp kullanılır sonra 1 artırılır
    cout << ++b << endl; // b=22, cout 22, b'nin degeri once artırılır sonra denkleme konulur
    
    a = 10;
    b = a << 2; // sola kaydırma, shift left
    cout << b << endl; // 40 (10=1010) 1010<<2 = 101000 =40
    int c = b >> 3; // sağa kaydırma, shift right
    cout << c << endl; // 5 (40=101000) 101000>>3 = 101 =5
    
    // ^ bitwise XOR
    x = 22 & 13;
    cout << x << endl; // 4 (22=10110, 13=01101, 10110&01101=00100=4)

    int q;
    cin >> q; // klavyeden deger okur
    cout << "girdiginiz deger: " << q << endl;


    return 0;
}
