#include <iostream>
#include <vector>

using namespace std;

template <class T> void sort(vector<T>& v){
    for(int i=0;i<v.size()-1;i++){
        for(int j=v.size()-1;j>i;j--){
            if(v[j-1]>v[j]){
                swap(v[j-1],v[j]);
            }
        }
    }
}
int main(){
    int value;
    vector<int> v;
    while(cin>>value){
        v.push_back(value);
    }
    sort<int>(v);
    for(const auto& i : v){
		cout<<i<< endl;
    }
} 