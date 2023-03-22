#ifndef ARRAYSTACKONP_HPP
#define ARRAYSTACKONP_HPP
#include <iostream>
#define maxSize 1000000
using namespace std;

class Stack {
public:
Stack(int capacity=maxSize); // Konstruktor. Argumentem jest rozmiar tablicy.
~Stack();
void push(char x); // Wstawia element na stos
char pop(); // Usuwa element ze stosu i zwraca jego wartość
int size(); // Zwraca liczbę elementów na stosie
bool empty(); // Sprawdza czy stos jest pusty
int getCapacity();// zwraca maxSize
char peek(); // sprawdza element na stosie
char *array;
private:
int top=0;
int capacity;

};


Stack::Stack(int size){
    array=new char[size];
    capacity=size;
}
Stack::~Stack(){
    delete[] array;
};
void Stack::push(char x){
    if(top+1>=capacity){
        throw std::out_of_range("STACK IS FULL");
        
    }
    else{
        array[top++]=x;
    }
}
char Stack::pop(){
    if(top==0){
        throw std::out_of_range("STACK IS EMPTY");
    }
    else
    {
        return array[--top];
        
    }
}

int Stack::size(){
    return top;
}
bool Stack::empty(){
    if(top==0) return true;
    return false;
}
int Stack::getCapacity(){
    return capacity;
}
char Stack::peek(){
    if(top!=0){
    return array[top-1];
    }else{
        return char(0);
    }
}

#endif
