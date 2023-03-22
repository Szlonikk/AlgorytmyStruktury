#include <iostream>
#include <fstream>
#include "Dict.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
	string input1,input2;
	Dict<string, string> dictionary;
    fstream file;
	file.open (argv[1], ios::in);
	while(!file.eof()){
		file>>input1;
		file>>input2;
		dictionary.insert(make_pair(input1,input2));
	}
	file.close();
	while(cin>>input1){
		if(dictionary.find(input1)){
			cout<<dictionary[input1]<<endl;
		}else{
			cout<<"-"<<endl;
		}
	}
	
}