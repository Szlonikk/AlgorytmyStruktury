#include <iostream>
#include "set.hpp"

int binSearch(int arr[], int size, int key) {
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

int main(){
    Set<int> s1;
    Set<int> s2;
    Set<int> s3;
    std::cout<<"dodajemy 1-5 do s1 i usuwamy 2 i 5"<<std::endl;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(3);
    s1.insert(5);
    s1.insert(4);
    s1.remove(2);
    s1.remove(5);
    s1.print();
    std::cout<<"===============\ndodajemy 3 i 8 do s2"<<std::endl;
    s2.insert(3);
    s2.insert(8);
    std::cout<<"Zawartosc s2:"<<std::endl;
    s2.print();
    std::cout<<"s3 staje się roznica s1 i s2, zawartosc: "<<std::endl;
     s3=s1.difference(s2);
    s3.print();
        std::cout<<"==============="<<std::endl;
    std::cout<<"s3 staje się suma s1 i s2, zawartosc: "<<std::endl;
     s3=s1.union_(s2);
    s3.print();
        std::cout<<"==============="<<std::endl;
    std::cout<<"s3 staje się przecieciem s1 i s2, zawartosc: "<<std::endl;
     s3=s1.intersect(s2);
    s3.print();
        std::cout<<"==============="<<std::endl;
    
    
    
    
}