#ifndef LINKEDSTACK_HPP
#define LINKEDSTACK_HPP
#include <iostream>
#define maxSize 1000000
using namespace std;
class Stack {
public:
struct Node{
    Node *next;
    int value;
};
Stack(); // Konstruktor. Argumentem jest rozmiar tablicy.
~Stack();
void push(int x); // Wstawia element na stos
int pop(); // Usuwa element ze stosu i zwraca jego wartość
int size(); // Zwraca liczbę elementów na stosie
bool empty();
int getCapacity(); // Zwraca maxSize
private:
int top=0;
int capacity=maxSize;
Node *stack;
};
Stack::Stack(){stack=NULL;}
Stack::~Stack(){
    while(!empty()){
        pop();
    }
}
void Stack::push(int x){
     if(top==capacity){
        throw std::out_of_range ("STACK IS FULL");
        
    }else{
    Node* temp = new Node;
	temp->value = x;
	temp->next = stack;
	stack = temp;
	top++;
    }
}
int Stack::pop(){
    if(top==0){
        throw std::out_of_range ("STACK IS EMPTY");     
    }
    int wynik = stack->value;
    
	Node* prev = stack->next;
	delete stack;
    top--;
	stack = prev;
    
	
	return wynik;
}

    

int Stack::size(){
    return top;
}
bool Stack::empty(){
    
    return top==0;
}
int Stack::getCapacity(){
    return capacity;
}



#endif