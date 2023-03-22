#include <iostream>
#include <vector>

using namespace std;

template<class T> void sort(vector<T>& v){
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

