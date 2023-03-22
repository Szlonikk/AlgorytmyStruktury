#include <iostream>
#include "FibHeap.hpp"

using namespace std;

int main(){
    
    cout<<"Tworzymy kopiec"<<endl;
    FibonacciHeap Kopiec;
    for(int i=1;i<11;i++){
        Kopiec.push(i);
    }
    cout<<"Dodalismy 10 wartosci"<<endl;
    cout<<"Najmniejsza to: "<<Kopiec.top()<<endl;
    cout<<"Rozmiar kopca: "<<Kopiec.size()<<endl;
    cout<<"Usuwamy najmnieszy element ktorym jest: "<<Kopiec.pop()<<endl;
    cout<<"Aktualny minimalny: "<<Kopiec.top()<<endl;
    cout<<"Rozmiar kopca: "<<Kopiec.size()<<endl;
    cout<<"Ilosc dzieci minimalnego: "<<Kopiec.minRoot()->degree<<endl;
    cout<<"Ilosc dzieci sasiada: "<<Kopiec.minRoot()->right->degree<<endl;
    
    return 0;
}
