#include <iostream>
using namespace std;

int main(){
    int a = 5;
    
    /*
    *****
    ****
    ***
    **
    *
    */
    for(int i=a ; i>0 ; i--) 
    {
    for (int j = 0 ; j < i ; j++){
        cout << "*";
    }
    cout << endl;
    }

    /*
    *****
     ****
      ***
       **
        *
    */
    
    for (int i=1 ; i <= a; i++)
    {
        for (int j=1 ; j <=i+1 ; j++ ){
            cout << " ";
        }
        for (int k=a ; k >= i ; k-- ){
            cout << "*";
        }
        cout << endl;
    }
    
    /*
        * i=1 , j=4
       ** i= 2 , j=3
      *** i=3 , j=2
     **** i=4 , j=1
    ***** i=5 , j=0
    */
    
    for (int i=0 ; i < a; i++)
    {
        for (int j=0 ; j < a - (i+1) ; j++ ){
            cout << " ";
        }
        for (int k=0 ; k < i+1 ; k++ ){
            cout << "*";
        }
        cout << endl;
    }
    
    int b;
    cout << "boyutu giriniz: ";
    cin >> b;
    
    for( int i=0 ; i<b ; i++ ){
        for (int j=0 ; j<b ; j++) {
            if (i==j)
                cout << "1" ;
            else
                cout << "0" ;
        }
        cout << endl ;
    }

    // 0001 i=0 j=3 b=4 i+j == b-1
    // 0010 i=1 j=2
    // 0100 i=2 j=1
    // 1000 i=3 j=0

    for( int i=0 ; i<b ; i++ ){
    for (int j=0 ; j<b ; j++) {
        if (i+j==b-1)
            cout << "1" ;
        else
            cout << "0" ;
    }
    cout << endl ;
    }

    // 1111 i=0 j=3
    // 1110 i=1 j=2
    // 1100 i=2 j=1
    // 1000 i=3 j=0
    
        cout << endl ;
        cout << endl ;
    for (int i=0 ; i<b ; i++ ){
        for (int j=0 ; j<b ; j++) {
            if (i+j < b-1)
            //if (i<j)
                cout << "1" ;
            else
            cout << "0";

        }
        cout << endl ;
    }
    return 0;
}