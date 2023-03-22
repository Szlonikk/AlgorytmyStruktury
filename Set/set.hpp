#ifndef SET_H
#define SET_H
template<class T>
class Set{
private:
    int N=100;
    int size_=0;
    T *arr;
    int binSearch(T arr[], int size, T key) {
        int low = 0;
        int high = size - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == key) {
                return mid;
            } else if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
        
    }
    int whereInsert(T arr[], int n, int x) {
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

public:
    Set(){
        arr=new T[N];
    }
    bool isMember(T x){
        if(binSearch(arr,size_,x)==-1){
            return false;
        }    
        else{
            return true;
        }
    }
    void insert(T x){
        if(size_==0){
            arr[0]=x;
            size_++;
        }
        if(!isMember(x)){   
            if(size_+1>=N){
                int newCapacity = N * 2;
                T *newArr = new T[newCapacity];
                std::copy(arr, arr + size_, newArr);
                delete[] arr;
                arr = newArr;
                N = newCapacity;
    

            }
            int i=whereInsert(arr,size_,x);
            for(int j=size_;j>i;j--){
                arr[j]=arr[j-1];
            }
            size_++;
            arr[i]=x; 
        }   
    }
    T remove(T x){
        if(!isMember(x)){
            throw std::out_of_range("Brak elementu");
        }
        //int i=binSearch(arr,size_,x);
        for(int i=binSearch(arr,size_,x);i<size_-1;i++){
            arr[i]=arr[i+1];
        }
        size_--;
        if(size_<N/4){
            int newCapacity = N /2;
            T *newArr = new T[newCapacity];
            std::copy(arr, arr + size_, newArr);
            delete[] arr;
            arr = newArr;
            N = newCapacity;

        }
        return x;
    }
    
    T pop(){
        size_--;
        return arr[size_];
    }
    int size(){
        return size_;
    }
    Set<T> intersect(Set<T> s1){
        Set<T> s3;
        T x;
        for(int i=0;i<size_;i++){
            x=arr[i];
            if(isMember(x) && s1.isMember(x)){
                s3.insert(x);
            }
        }
        return s3;
    }
    Set<T> difference(Set<T> s1){
        Set<T> s3;
        T x;
        for(int i=0;i<size_;i++){
            x=arr[i];
            if(!s1.isMember(x)){
                s3.insert(x);
            }
        }
        return s3;
    }
    Set<T> union_(Set<T> s1){
        Set<T> s3;
        
        
        for(int i=0;i<size_;i++){
            s3.insert(arr[i]);
        }
        T x;
        for(int i=0;i<s1.size();i++){
            x=s1.pop();
            if((!isMember(x))){
                s3.insert(x);
            }
        }
        return s3;    
    }
    void print(){
        for(int i=0;i<size_;i++){
            std::cout<<arr[i]<<std::endl;
        }
    }
};
#endif
