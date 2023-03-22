#include <iostream>
#include <vector>

using namespace std;

template<class T> void sort(vector<T>& v){
    int mini;
    int porownania=0;
    int przestawienia=0;
	for (int i=0;i<v.size();i++) {
		mini=i;
		for (int j=i;j<(int)v.size();j++) {
            porownania++;
			if(v[j]<v[mini]){
				mini=j;
			}
		}if(v[i]!=v[mini]){
		swap(v[i],v[mini]);
        przestawienia++;
        }
	}
    cout<<"Porownania: "<<porownania<<endl<<"Przestawienia: "<<przestawienia;
}

int main(){
    int value;
    vector<int> v;
    while(cin>>value){
        v.push_back(value);
    }
    sort<int>(v);
    

}
