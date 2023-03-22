#include <iostream>
#include <stdlib.h>
#include "ArrayList.hpp"

#define ROZMIAR 1000

using namespace std;

int main (int argc, char *argv[]){
	
ArrayList lista;
int x;
int y;
int operations;
char sign;
cin>>operations;
for(int i=0;i<operations;i++){
    cin>>sign;
    if(sign=='F'){
        cin>>x;
        if(!lista.full()){
            lista.push_front(x);
        }
    }else if(sign=='B'){
        cin>>x;
        if(!lista.full()){
            lista.push_back(x);
        }
    }else if(sign=='f'){
        if(lista.size()>0){
            cout<<lista.pop_front()<<endl;
        }else{
            cout<<"EMPTY"<<endl;
        }
    }else if(sign=='b'){
        if(lista.size()>0){
            cout<<lista.pop_back()<<endl;
        }else{
            cout<<"EMPTY"<<endl;
        }
    }else if(sign=='R'){
        cin>>x;
        cin>>y;
        if(lista.replace (x, y)) {
		cout<<"TRUE"<<endl;
    	} else {
			cout<<"FALSE"<<endl;
		}
    }else if(sign=='S'){
        cout<<lista.size()<<endl;
    }


}
}
	

