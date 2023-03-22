#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;

template<class T> void InsertionSort(vector<T>& v){
    int x; 
    int j;   
    for(int i=1;i<v.size();i++){
        x=v[i];
        j=i-1;
        while(j>=0 && v[j]>x){
            v[j+1]=v[j];
            j--;
        }
    v[j+1]=x;
    }
}
template<class T> void SelectioinSort(vector<T>& v){
    int mini;
	for (int i=0;i<v.size();i++) {
		mini=i;
		for (int j=i;j<(int)v.size();j++) {
			if(v[j]<v[mini]){
				mini=j;
			}
		}
		swap(v[i],v[mini]);
	}
}
template <class T> void BubbleSort(vector<T>& v){
    for(int i=0;i<v.size()-1;i++){
        for(int j=v.size()-1;j>i;j--){
            if(v[j-1]>v[j]){
                swap(v[j-1],v[j]);
            }
        }
    }
}
int main(){
    vector<int> v_ins;
    vector<int> v_sel;
    vector<int> v_bub;
    fstream dane("insertion.txt",ios::out);
    for(int i=500;i<5500;i++){ ///test insert (ilosc liczb)

        for(int j=0;j<i;j++){
            v_ins.push_back(rand()%10000);
        }
        auto begin = std::chrono::high_resolution_clock::now();

        InsertionSort<int>(v_ins);
        auto end = std::chrono::high_resolution_clock::now();
        auto trwanie = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        v_ins.clear();
        dane<<trwanie.count()<<endl;
    }
    dane.close();
    
    fstream dane2("selection.txt",ios::out);
    for(int i=500;i<5500;i++){ ///test insert (ilosc liczb)

        for(int j=0;j<i;j++){
            v_sel.push_back(rand()%10000);
        }
        auto begin = std::chrono::high_resolution_clock::now();

        SelectioinSort<int>(v_sel);
        auto end = std::chrono::high_resolution_clock::now();
        auto trwanie = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        v_sel.clear();
        dane2<<trwanie.count()<<endl;
    }
    dane2.close();
    
    fstream dane3("bubble.txt",ios::out);
    for(int i=500;i<5500;i++){ ///test insert (ilosc liczb)

        for(int j=0;j<i;j++){
            v_bub.push_back(rand()%10000);
        }
        auto begin = std::chrono::high_resolution_clock::now();

        BubbleSort<int>(v_bub);
        auto end = std::chrono::high_resolution_clock::now();
        auto trwanie = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        v_bub.clear();
        dane3<<trwanie.count()<<endl;
    }
    dane3.close();

}