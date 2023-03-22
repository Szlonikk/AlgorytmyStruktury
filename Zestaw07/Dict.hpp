#include "ArrayList.hpp"
#define SIZE 100
template<class K, class V>
class Dict {
using Pair = std::pair<K, V>;
private:

ArrayList<Pair> dictionary[SIZE];
int top=0;
Pair def;
public:

unsigned long Hash(const std::string str) { 
    unsigned long hash = 17;
    int c;
    const char* input = str.c_str();
    while ((c = *input++)){
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash% SIZE;
}

void clear(){
    for(int i=0;i<SIZE;i++){
        dictionary[i].clear();
    }
}
bool insert(const Pair& p){
    int hash=Hash(p.first);
	if(!find(p.first)){
		dictionary[hash].push_back(p);
		top++;
		return true;
	}
	for(int i=0;i<dictionary[hash].size();i++){
		if(dictionary[hash][i].first==p.first){
			dictionary[hash][i].second=p.second;
			return false;
		}
	}
	return false;
}

bool find(const K& k){
	int hash=Hash(k);
	
	for(int i=0;i<dictionary[hash].size();i++){
		if(dictionary[hash][i].first==k){
			return true;
		}
	}return false;

}

V& operator[] (const K& k){
	int hash=Hash(k);
	for(int i=0;i<dictionary[hash].size();i++){
		if(dictionary[hash][i].first==k){
			return dictionary[hash][i].second;
		}
	}
	def.first=k;
	insert(def);
	return def.second;
}

bool erase(const K& k){
	int hash=Hash(k);
	for(int i=0;i<dictionary[hash].size();i++){
		if(dictionary[hash][i].first==k){
			dictionary[hash].erase(i);
			top--;
			return true;
		}
	}
	return false;
}

bool epmpty(){
	return top==0;
}
int size(){
	return top;
}
void buckets(){
		int mini = 100000;
		int maxi = 0;
		
		for (int i=0;i<SIZE; i++) {
			if (dictionary[i].size() > maxi) {
				maxi = dictionary[i].size();
			}
			if (dictionary[i].size() < mini) {
				mini = dictionary[i].size();
			}
		}
		
		std::cout << "# " << top << " " << SIZE << " " << mini << " " << maxi << std::endl;
}
};
