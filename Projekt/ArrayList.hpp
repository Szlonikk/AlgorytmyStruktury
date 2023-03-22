#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP
#include <iostream>
#define maxSize 100000
template<class T>
class ArrayList {
public:
ArrayList(){
    top=0;
    array=new T[maxSize];
}
~ArrayList(){
    delete[] array;
}
void push_front(T x){
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
T pop_front(){
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
void push_back(T x){
    if(full()){
        throw std::out_of_range("LIST IS FULL");
    }
    array[top++]=x;
}
int pop_back(){
    if(empty()){
		throw std::out_of_range("LIST IS EMPTY");
    }
    return array[--top];
}
bool empty(){
    return top==0;
}
void clear(){
    top=0;
}
int find(T x){
    for (int i = 0; i < size(); i++)
			if (array[i] == x)
				return i;
		
		return -1;
}
T erase(int i){
    if(empty()){
		throw std::out_of_range("LIST IS EMPTY");
    }
    T value=array[i];
    for(int j=i;j<top;j++){
        array[i]=array[i-1];
    }
    return value;
}
void insert(int i, int x){
    if(full()){
        throw std::out_of_range("LIST IS FULL");
    }
    for(int j=top;j>i;j--){
        array[j]=array[j-1];
    }
    array[i]=x;
}
int remove(T x){
    int count=0;
    for(int i=0;i<top;i++){
    if(array[i]==x){
        count++;
        erase(i);
    }

    }
    return count;
}
bool replace(T x, T y){
    int i = find (x);
		
	if (i != -1) {
		array[i] = y;
		return true;
	}
		
	return false;
}
bool full(){
    return top==maxSize;
}
int size(){
    return top;
}
T& operator [] (int x){
    if(x>top){
        top=x;
    }
    return array[x];
}

private:
T* array;
int top;
};

#endif