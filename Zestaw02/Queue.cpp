#include <iostream>
//#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"
using namespace std;

int main(){

    Queue kolejka;
    string sign;
    int x;
    int operations;
    cin>>operations;
    for(int i=0;i<operations;i++){
        cin>>sign;
        if(sign=="A"){
            
            if(kolejka.size()<kolejka.getCapacity()){
            cin>>x;
            kolejka.push(x);
            }
        }
        else{
             if(sign=="D"){
                
                if(kolejka.size()!=0){
                cout<<kolejka.pop()<<endl;
                }else
                cout<<"EMPTY"<<endl;
             }
             else{
                if(sign=="S"){
                    cout<<kolejka.size()<<endl;
                }
             }

        }
    }
    
    return 0;
}