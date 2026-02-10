#include <iostream>

using namespace std;

int g (int x){ // call by value
    x=10;
}

int f (int *x){ // call by reference 
    *x=30;
} 

int h (int *x , int *y , int *z){
    *x = 40;
    *y = 90;
    *z = 100;
    return 50;
}

int main() {
    int a = 10;
    int *p;
    p = &a;
    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value of p (address of a): " << p << endl;
    cout << "Value pointed to by p: " << *p << endl;
    cout << "Address of pointer p: " << &p << endl; 

    *p = 20;
    cout << "New value of a after modifying through pointer p: " << a << endl;

    int x[3] = {1, 2, 3};
    int *q;
    q = x; // or q = &x[0];
    cout << q[0] << " " << q[1] << " " << q[2] << endl;
    q[2] = 8;
    cout << x[0] << " " << x[1] << " " << x[2] << endl;

    int *qq;
    qq = x;
    qq[2] = q[2] = x[2];

    g(a);
    cout << "Value of a after calling g (call by value): " << a << endl;
    f(p);
    cout << "Value of a after calling f (call by reference): " << a << endl;
    int *w,*r,*t;
    int v1, v2, v3; 
    w = &v1;       
    r = &v2;
    t = &v3;
    h(w, r, t);
    cout << *w << " " << *r << " " << *t << endl;

    return 0;
}