/*
bir sayi giriniz: 5
*****
 ****
  ***
   **
    *
*/

#include <iostream>

using namespace std;

int main()
{ 
    cout << "bir sayi giriniz: ";
    int nmbr;
    cin >> nmbr;

    for (int k=1 ; k <= nmbr ; k++){

        for (int j=1; j < k ; j++){
            cout << " ";
        }

        for (int i=1 ; i <= nmbr-k+1 ; i++){
            cout << "*";
        }

        cout << endl;      
    }

    return 0;
}