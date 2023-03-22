#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP
#include <iostream>
#define maxSize 1000
template<class T>
class ArrayList {
public:
ArrayList();
~ArrayList();
void push_front(T x); // Dołącza element na początek listy
T pop_front(); // Usuwa i zwraca element z początku listy
void push_back(T x); // Dołącza element na koniec listy
T pop_back(); // Usuwa i zwraca element z końca listy
int size(); // Zwraca liczbę elementów w liście
bool empty(); // Zwraca true gdy lista jest pusta
void clear(); // Czyści listę
int find(T x); // Zwraca pozycję pierwszego elementu o wartości x
T erase(int i); // Usuwa i zwraca element na pozycji i
void insert(int i, T x); // Wstawia element x przed pozycję i
int remove(T x); // Usuwa wystąpienia x i zwraca ich liczbę
bool replace(T x,T y);
bool full();
private:
T* array;
int top;
};
ArrayList::ArrayList(){
    top=0;
    array=new T[maxSize];
}
ArrayList::~ArrayList(){
    delete[] array;
}
void ArrayList::push_front(T x){
    T temp;
    if(full()){
        throw std::out_of_range("LIST IS FULL");
    }
    for(int i=top;i>0;i--){
        array[i]=array[i-1];
    }
    array[0]=x;
    top++;
}
T ArrayList::pop_front(){
    if(empty()){
		throw std::out_of_range("LIST IS EMPTY");
    }
	T value=array[0];

    for(int i=0;i<top;i++){
        array[i]=array[i+1];
    }
    top--;
    return value;
}
void ArrayList::push_back(T x){
    if(full()){
        throw std::out_of_range("LIST IS FULL");
    }
    array[top++]=x;
}
int ArrayList::pop_back(){
    if(empty()){
		throw std::out_of_range("LIST IS EMPTY");
    }
    return array[--top];
}
bool ArrayList::empty(){
    return top==0;
}
void ArrayList::clear(){
    top=0;
}
int ArrayList::find(T x){
    for (int i = 0; i < size(); i++)
			if (array[i] == x)
				return i;
		
		return -1;
}
T ArrayList::erase(int i){
    if(empty()){
		throw std::out_of_range("LIST IS EMPTY");
    }
    T value=array[i];
    for(int j=i;j<top;j++){
        array[i]=array[i-1];
    }
    return value;
}
void ArrayList::insert(int i, int x){
    if(full()){
        throw std::out_of_range("LIST IS FULL");
    }
    for(int j=top;j>i;j--){
        array[j]=array[j-1];
    }
    array[i]=x;
}
int ArrayList::remove(T x){
    int count=0;
    for(int i=0;i<top;i++){
    if(array[i]==x){
        count++;
        erase(i);
    }

    }
    return count;
}
bool ArrayList::replace(T x, T y){
    int i = find (x);
		
	if (i != -1) {
		array[i] = y;
		return true;
	}
		
	return false;
}
bool ArrayList::full(){
    return top==maxSize;
}
int ArrayList::size(){
    return top;
}
#endif