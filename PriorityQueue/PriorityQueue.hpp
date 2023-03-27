#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
template<class T>
class PriorityQueue{
public:
struct QueueElement{
    int priority;
    T obj;
    
    int GetPrio(){
        return priority;
    }
    T GetObj(){
        return obj;
    }
};
using QE=QueueElement;

private:
    
    int size_=0;
    QE *arr;
    int N=100;
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    void heapify(int i){
    int largest = i;
    int l = left(i);
    int r = right(i);
    if(l < size_ && arr[l].priority > arr[largest].priority){
        largest = l;
    }
    if(r < size_ && arr[r].priority > arr[largest].priority){
        largest = r;
    }
    if(largest != i){
        std::swap(arr[i], arr[largest]);
        heapify(largest);
    }
}

public:
    PriorityQueue(){
        arr=new QE[N];
    }
    ~PriorityQueue(){
        delete[] arr;
    }
    void increaseKey(int i, int k){
        if(k>arr[i].priority){
            arr[i].priority=k;
            while(arr[i].priority>arr[parent(i)].priority){
                std::swap(arr[i],arr[parent(i)]);
                i=parent(i);
                if(i==0){
                    break;
                }
            }
        }else{
            throw std::logic_error("TOO SMALL KEY");
        }    
    }
    void insert(T x,int k){
        if(size_+1>=N){
            int newCapacity = N * 2;
            QE *newArr = new QE[newCapacity];
            std::copy(arr, arr + size_, newArr);
            delete[] arr;
            arr = newArr;
            N = newCapacity;
        }
        size_++;
        arr[size_-1].obj=x;
        arr[size_-1].priority=-1;
        
        increaseKey(size_-1,k);
        
    }
    int size(){
        return size_;
    }
    QE Max(){
        return arr[0];
    }
    QE ExtractMax(){
        if(size_!=0){
            if(size_<N/4){
                int newCapacity = N /2;
                QE *newArr = new QE[newCapacity];
                std::copy(arr, arr + size_, newArr);
                delete[] arr;
                arr = newArr;
                N = newCapacity;

            }
            QE result=arr[0];
            std::swap(arr[0],arr[size_-1]);
            size_--;
            heapify(0);
            return result;
        }else{
            throw std::out_of_range("QUEUE IS EMPTY");}
        }
    void print(){
        for(int i=0;i<size_;i++){
            std::cout<<arr[i].GetObj()<<" "<<arr[i].priority<<std::endl;
        }
    }
};
#endif