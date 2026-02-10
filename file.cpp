#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream dosya;
    dosya.open("deneme.txt");

    if(dosya.is_open()){
        dosya << "Merhaba Dosya Islemleri!" << endl;
        dosya.close();
    } else {
        cout << "Dosya açılamadı!" << endl;
    }

    string line;
    ifstream dosyaOku("deneme.txt");
    if(dosyaOku.is_open()){
        while(getline(dosyaOku, line)){
            cout << line << endl;
        }
        dosyaOku.close();
    } else {
        cout << "Dosya açılamadı!" << endl;
    }


    return 0;
}