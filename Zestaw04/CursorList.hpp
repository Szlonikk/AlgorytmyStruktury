#ifndef CURSORLIST_HPP
#define CURSORLIST_HPP
#include <iostream>
#define maxSize 10000
class CursorList { // Klasa listy
public:
struct Node { // Zagnieżdżona klasa węzła
    int value; // Element przechowywany przez węzeł listy
    int next; // Indeks kolejnego węzła
};
CursorList();
~CursorList();
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
bool replace(int x,int y);
bool full();
private:
Node arr[maxSize]; // Tablica węzłów
int head; // Indeks pierwszego węzła
int tail; // Indeks ostatniego węzła
int top; // Rozmiar listy
int spare; // Indeks pierwszego nieużytego elementu tablicy
};
CursorList::CursorList(){
    
	for(int i=0;i<=maxSize;i++){
		arr[i].next = i + 1;
	}
	spare = 0;
	head = 0;
	tail = 0;
	top = 0;
}
CursorList::~CursorList(){
}
void CursorList::push_front(int x){
    if(full()){
        throw std::out_of_range("LIST IS FULL");
    }
    int temp=head;
    head=spare;
    arr[head].value=x;
    spare=arr[spare].next;
    arr[head].next=temp;

    top++;
}
int CursorList::pop_front(){
    if(empty()){
		throw std::out_of_range("LIST IS EMPTY");
    }
    int temp=head;
    head = arr[head].next;
	arr[temp].next = spare;
	spare = temp;
		
	top--;
	if (empty()){		
        head = spare;
    }
	return arr[spare].value;
}
void CursorList::push_back(int x){
    if(full()){
        throw std::out_of_range("LIST IS FULL");
    }
    int temp=tail;
    tail=spare;
    arr[tail].value=x;
    spare=arr[spare].next;
    arr[temp].next=tail;
    top++;
}
int CursorList::pop_back(){
    if(empty()){
		throw std::out_of_range("LIST IS EMPTY");
    }
    int temp=head;
    for(int i=0;i<size()-2;i++) {
			temp=arr[temp].next;
	}
		
	arr[tail].next=spare;
	spare=tail;
	tail=temp;
		
	top--;
	return arr[spare].value;
}
int CursorList::size(){
    return top;
}    
bool CursorList::empty(){
    return top==0;
}
bool CursorList::full(){
    return top==maxSize;
}
void CursorList::clear(){
    while(size()!=0){
        pop_front();
    }
}
int CursorList::find(int x){
    int temp=head;
    for(int i=0;i<size();i++){
        if(arr[temp].value=x){
            return i;
        }
        temp=arr[temp].next;
    }
    return -1;
}
int CursorList::erase(int i){
    if(empty()){
		throw std::out_of_range("LIST IS EMPTY");
    } 
    int temp=head;
    for(i;i>1;i--){
        temp=arr[temp].next;
    }
    int old_spare=spare;
    spare=arr[temp].next;
    arr[temp].next=arr[arr[temp].next].next;
    arr[spare].next=old_spare;
    top--;
    return arr[spare].value;
}
void CursorList::insert(int i,int x){
    if(size()+1==maxSize){
		throw std::out_of_range("LIST IS FULL");
    }
    int temp=head;
	for(i;i>1;i--) {
		temp = arr[temp].next;
	}
		
	int node=spare;
	spare=arr[spare].next;
	arr[node].value=x;
		
	if (i==0) {
		arr[node].next=head;
		head=node;
	}else{
		arr[node].next=arr[temp].next;
		arr[temp].next=node;
	}
	top++;
}
int CursorList::remove(int x){
    int count = 0;
	int temp = head;
	for (int i=0;i<size()-1;i++) {	
		temp = arr[temp].next;
		if (arr[arr[temp].next].value != x){
			continue;
        }	
		erase(i);
		
		count++;
		}
		
	return count;
}
bool CursorList::replace (int x, int y) { // zamienia pierwsze wystąpienie elementu x na element y
	int search = head;
	for (int i = 0; i < size(); i++) {
		if (arr[search].value == x) {
			arr[search].value = y;
			return true;
		}
		search = arr[search].next;
	}
		
	return false;
}
#endif
