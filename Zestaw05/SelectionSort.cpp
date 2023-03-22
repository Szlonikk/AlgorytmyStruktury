#include <iostream>
#include <vector>

using namespace std;

template<class T> void sort(vector<T>& v){
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
