#ifndef ARRAYQUEUE_HPP
#define ARRAYQUEUE_HPP
#define SIZE 100000
class Queue {
public:
Queue(); // Konstruktor domyślny
~Queue();
void push(int x); // Wstawia element x do kolejki (także enqueue)
int pop(); // Usuwa element z kolejki i zwraca jego wartość (dequeue)
int size(); // Zwraca liczbę elementów w kolejce
bool empty(); // Sprawdza czy kolejka jest pusta
int getCapacity();
private:
int* array;
int len = 0;
int buffStart = -1;
int buffEnd = 0;
int maxSize;
};
Queue::Queue(){
    maxSize=SIZE;
    array=new int[SIZE];
}
Queue::~Queue(){
    delete[] array;
}
void Queue::push(int x){
    if(len==maxSize){
        throw std::out_of_range("QUEUE IS FULL");
    }
    array[buffEnd++]=x;
    buffEnd%=maxSize;
    len++;
}

int Queue::pop(){
    if(len==0){
        throw std::out_of_range("QUEUE IS EMPTY");
    }
    buffStart++;
    buffStart%=maxSize;
    len--;
    return array[buffStart];
}
int Queue::size(){
    return len;
}
bool Queue::empty(){
    return len==0;
}
int Queue::getCapacity(){
    return maxSize;
}


#endif
