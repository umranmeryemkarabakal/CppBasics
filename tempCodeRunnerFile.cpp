#include <iostream>

#include <cstdlib> // rand ve srand fonksiyonları için
#include <ctime>   // time fonksiyonu için

using namespace std;

int f (int x){
    cout << x << endl;
    return 5;
}

void g (int x){
    cout << x+5 << endl;
}

// iteravive fonk
int factorial(int x){ // 3! = 3*2*1
    int carpim = 1;
    for (int i = x ; i>0 ; i--){
        carpim *= i;
    }
    return carpim;
}

int combination(int a, int b){ // a! / (b! * (a-b)!)
    int x = factorial(a);
    int y = factorial(b);
    int z = factorial(a-b);
    return x / (y * z);
}

// iterative - dongu ile
// recursive - fonksiyon ile

// call back stack
int factorial_recursive_fonk(int x){
    if (x==1){
        return 1;
    }
    return x * factorial_recursive_fonk(x-1);
}

int us(int taban, int u){
    int sonuc = 1;
    for (int i=0; i<u; i++){
        sonuc *= taban;
    }
    return sonuc;
}

// fermat teoremi bir sayının asal olup olmadığı sayının karekökündeki sayıya kadar kontrol edilmesi yeterlidir
bool asal_control(int x){
    for (int i=2 ; i*i<=x ; i++){
        if ( x%i == 0){
            return false;
        }
    }
    return true;
}

// ilk 20 asal sayı
void asal_sayilar_20(){
    int c = 0;
    for(int i ; c<=20 ; i++){
        if (asal_control(i)){
            cout << i << endl;
            c++;
        }
    }
}

int n_asal(int x){
    int c=0;
    double i;
    for (i=2 ; c<x; i++){  //x. asl sayı
        if(asal_control(i)){
            c++;
        }
    }
    return i-1;
}

int carpim_recursive(int a, int b){
    int sonuc = 0;
    if (b==0 || a==0)
        return 0;
    if (b<0)
        return carpim_recursive(0-a, 0-b);
    return a + carpim_recursive(a, b-1);
}

int carpim_iterative(int a, int b){
    int sonuc = 0;
    for (int i=0 ; i<b ; i++){
        sonuc += a;
    }
    return sonuc;
}


int main()
{
    cout << f(5) << endl;
    cout << "--" << endl;
    g(10);
    cout << "--" << endl;
    g(f(10));
    cout << "++" << endl;
    cout << factorial(5) << endl;
    cout << "++" << endl;
    cout << combination(5, 2) << endl;
    cout << "++" << endl;   
    cout << factorial_recursive_fonk(5) << endl;
    cout << "**" << endl;
    cout << us(2, 5) << endl; // 2^5
    cout << "**" << endl;
    cout << asal_control(29) << endl;
    cout << asal_control(2) << endl;
    cout << asal_control(15) << endl;
    cout << "***" << endl;
    int x=4;
    cout << n_asal(x) << endl;  // 2,3,5,7,11
    cout << "***" << endl;
    asal_sayilar_20();
    cout << "*" << endl;
    cout << carpim_recursive(3, 4) << endl;
    cout << carpim_iterative(3, 4) << endl;
    cout << carpim_recursive(-5, 4) << endl; 
    
    // random number generator
    int rg ;
    srand (time(NULL));
    rg = rand() % 6 + 1; // 1-6
    cout << "Random number: " << rg << endl;
    rg = rand() % 2 + 1; // 1-2
    cout << "Random number: " << rg << endl;



    return 0;
}


