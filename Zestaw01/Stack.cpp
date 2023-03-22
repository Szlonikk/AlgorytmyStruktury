#include <iostream>
//#include "ArrayStack.hpp"
#include "LinkedStack.hpp"
using namespace std;

int main(){

    Stack stos;
    string sign;
    int x;
    int operations;
    cin>>operations;
    for(int i=0;i<operations;i++){
        cin>>sign;
        if(sign=="A"){
            
            if(stos.size()<stos.getCapacity()){
            cin>>x;
            stos.push(x);
            }
        }
        else{
             if(sign=="D"){
                
                if(stos.size()!=0){
                cout<<stos.pop()<<endl;
                }else
                cout<<"EMPTY"<<endl;
             }
             else{
                if(sign=="S"){
                    cout<<stos.size()<<endl;
                }
             }

        }
    }
    
    return 0;
}