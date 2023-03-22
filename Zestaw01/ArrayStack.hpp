#ifndef ARRAYSTACK_HPP
#define ARRAYSTACK_HPP
#include <iostream>
#define maxSize 1000000
using namespace std;

class Stack {
public:
Stack(int capacity=maxSize); // Konstruktor. Argumentem jest rozmiar tablicy.
~Stack();
void push(int x); // Wstawia element na stos
int pop(); // Usuwa element ze stosu i zwraca jego wartość
int size(); // Zwraca liczbę elementów na stosie
bool empty(); // Sprawdza czy stos jest pusty
int getCapacity();// zwraca maxSize
int peek(); // sprawdza element na stosie
private:
int top=0;
int capacity;
int *array;
};


Stack::Stack(int size){
    array=new int[size];
    capacity=size;
}
Stack::~Stack(){
    delete[] array;
};
void Stack::push(int x){
    if(top==capacity){
        throw std::out_of_range ("STACK IS FULL");
        
    }
    else{
        array[top++]=x;
    }
}
int Stack::pop(){
    if(top==0){
        throw std::out_of_range ("STACK IS EMPTY");     
    }
    else{

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
int Stack::peek(){
    return array[top-1];
}

#endif