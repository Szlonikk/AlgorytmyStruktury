#ifndef LINKEDSTACK_HPP
#define LINKEDSTACK_HPP
#include <iostream>
#define SIZE 100000
using namespace std;
class Queue {
public:
struct Node{
    Node *ptr;
    int value;
};
Queue(); // Konstruktor. Argumentem jest rozmiar tablicy.
~Queue();
void push(int x); // Wstawia element na stos
int pop(); // Usuwa element ze stosu i zwraca jego wartość
int size(); // Zwraca liczbę elementów na stosie
bool empty();
int getCapacity(); // Zwraca maxSize

private:
int maxSize;
int top=0;
Node *first;
Node *last;
Node *el;
};
Queue::Queue(){
     maxSize=SIZE;
     first=NULL;
     last=NULL;
     el=NULL;
}
Queue::~Queue(){
    while(!empty()){
         pop();
    }
}
void Queue::push(int x){
    if(top==maxSize){
        throw std::out_of_range ("STACK IS FULL");
        
    }else
    if(top==0){
        last=new Node;  
        last->value=x;  //przypisanie ostatniemu elementowi wartosci
        first=new Node; 
        first->ptr=last; //element pierwszy wskazuje na ostatni
    }else{

    
        el=new Node; 
        el->value=x; // nowy elemny przypisuje wartosc
        last->ptr=el; //otatni wskazuje na nowy
        last=el; //ostatni staje sie tym nowym
    }
	top++;
}

int Queue::pop(){
    if(top==0){
        throw std::out_of_range ("STACK IS EMPTY");     
    }
    
    el=first;
    
    first=first->ptr; //wskazuje na elemnt za nim
    int wynik = first->value;
    delete el;  //usuwamy pierwszy elemnt
    top--;
	return wynik;
}

    

int Queue::size(){
    return top;
}
bool Queue::empty(){
    
    return top==0;
}
int Queue::getCapacity(){
    return maxSize;
}



#endif