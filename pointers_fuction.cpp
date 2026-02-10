#include <iostream>
using namespace std;

int f(int *p) {
    *p = 10;
}

int g(int *p){
    p[2] =10;
}

int toplam(int *a, int boyut){
    int topla = 0;
    for (int i=0; i<boyut; i++){
        topla += a[i];
    }
    return topla;
}

int main() {
    int a[3];
    int *p = (int *)malloc(sizeof(int) * 5);
    p[2] = 8;
    cout << p[2] << endl;
    int *q = (int *)malloc(sizeof(int)); // void *
    *q = 40;
    f(q);
    cout << *q << endl;
    
    for(int i=0; i<5 ; i++){
        cin >> *(p+i);
    }
    for(int i=0; i<5 ; i++){
        cout << *(p+i) << " ";
    }

    int b[3] = {1,2,3};
    int *r = b;
    g(r);
    cout << b[2] << endl;
    g(b); // 1,2,10
    cout << b[2] << endl;

    cout << "Toplam: " << toplam(b, 3) << endl;

    
    return 0;
}