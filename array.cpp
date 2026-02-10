#include <iostream>

using namespace std;

int main(){
    int a[3] = { 5,6,2};
    cout << a[1] << endl;
    a[2] = 8;
    for (int i=0; i<3; i++){
        cout << a[i] << endl;
    }

    cout << "-----" << endl;
    
    int b[2];
    b[0] = 10;
    b[1] = 20;
    cin >> b[2];
    cin >> b[3];
    for (int i=0; i<4; i++){
        cout << b[i] << endl;
    }

    cout << "-----" << endl;
    int c[2][2] = { {1,2}, {3,4} };
    cout << c[1][0] << endl;
    cout << "-----" << endl;
    for (int i=0 ; i<2 ; i++){
        for (int j=0 ; j<2 ; j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

}