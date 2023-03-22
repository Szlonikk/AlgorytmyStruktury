#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>
#define maxSize 1000

class List {

struct Node{
    int value;
	Node* next;
    Node* prev;
};
public:
List();
~List();
void push_front(int x); // Dołącza element na początek listy
int pop_front(); // Usuwa i zwraca element z początku listy
void push_back(int x); // Dołącza element na koniec listy
int pop_back(); // Usuwa i zwraca element z końca listy
int size(); // Zwraca liczbę elementów w liście
bool empty(); // Zwraca true gdy lista jest pusta
void clear(); // Czyści listę
int find(int x); // Zwraca pozycję pierwszego elementu o wartości x
int erase(int i); // Usuwa i zwraca element na pozycji i
void insert(int i, int x); // Wstawia element x przed pozycję i
int remove(int x); // Usuwa wystąpienia x i zwraca ich liczbę
bool full();
bool replace(int x,int y);
private:
Node* guard;
int top;
};
List::List(){
    guard=new Node();
    guard->next=guard;
    guard->prev=guard;
    top=0;
}
List::~List(){
    while(!empty()){
        pop_front();
    }
    delete guard;
}
void List::push_front(int x){
    Node* temp=new Node();
    temp->value=x;
    temp->next=guard->next;
	temp->prev=guard;
	guard->next->prev=temp;
	guard->next=temp;
    top++;
}
int List::pop_front(){
    int x=guard->next->value;
	Node* temp=guard->next;
	guard->next=temp->next;
	temp->next->prev=guard;
	top--;
	delete temp;
	return x;
}
void List::push_back(int x){
	Node* temp=new Node();
	temp->value=x;
	temp->prev=guard->prev;
	temp->next=guard;
	guard->prev->next=temp;
	guard->prev=temp;
	top++;		
}
int List::pop_back(){	
	int x=guard->prev->value;
	Node* temp=guard->prev;
	guard->prev=temp->prev;
	temp->prev->next=guard;
	top--;
	delete temp;
	return x;
}
	
int List::size(){
	return top;
}
bool List::empty(){
    return top==0;
}
bool List::full(){
    return top==maxSize;
}
void List::clear() {
	while(guard->next!=guard){
		pop_front();
	}
}
int List::find(int x){
    Node* search=guard;
    for(int i=0;i<size();i++){
		search=search->next;
		if (search->value==x){
			return i;
		}
	}
	return -1;
}

int List::erase(int i){	
	Node* temp=guard->next;
	for(i;i>0;i--){
		temp=temp->next;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	int x=temp->value;
	top--;
	delete temp;
	return x;
}
	
void List::insert(int i, int x){ 		
	Node* temp=new Node();
	temp->value=x;
	Node* insert=guard;
	for(int n=0;n<i;n++){
		insert = insert->next;
	}
	temp->next=insert->next;
	temp->prev=insert;
	insert->next->prev=temp;
	insert->next=temp;
	top++;
		
}
	
int List::remove(int x){	
	int count=0;
	int i=-1;
	while((i=find(x))!=-1){
		erase(i);
		count++;
	}
	return count;		
}
bool List::replace(int x,int y){
	int i;
	if((i=find(x))==-1){
		return false;
	}
	erase(i);
    insert(i,y);
    return true;
}
#endif