#include <iostream>
#include <vector>
#include <cmath>
//#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"

#define maxSize 1000000

using namespace std;

void radix(vector<int>& v){
    Queue queues[10];
    bool end = false;
	int i=0;
	int value;
	int wchichQueue;
	while (!end) {
		
		for (vector<int>::iterator ite = v.begin(); ite != v.end(); ++ite)
		{
			value = *ite;
			wchichQueue=(value / (int)pow (10, i)) % 10;
			queues[wchichQueue].push(value);
		}
		if (queues[0].size() == (int)v.size()) //preszlismy cala tablice
			end = true;
		
		
		v.clear();
		
		for (int j = 0; j < 10; j++) {
			while (!queues[j].empty()) {
				v.push_back (queues[j].pop());
			}
		}
		i++;
	}
 
   
}

int main(){
    int value;
	vector<int> v;
	
	while (cin >> value) {
		v.push_back(value);
	}
	radix (v);

	for(vector<int>::iterator ite = v.begin(); ite != v.end(); ++ite){
		cout << *ite << endl;
	}

}