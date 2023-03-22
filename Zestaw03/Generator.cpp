#include <iostream>
#include <stdlib.h>

using namespace std;

int main () {
	
	int value;
    int numberOfOperations;
    srand(time(NULL));
    numberOfOperations=rand()%1000;
    cout<<numberOfOperations<<endl;
	for (int i=0;i<numberOfOperations;i++) {
        value=(rand()%6);
		
			if(value==0){
				cout<<"F"<<" "<<rand()%1000<<endl;
            }else if(value==1){
				cout<<"B"<<" "<<rand()%1000<<endl;
			}else if(value==2){
                cout<<"f"<<endl;
            }else if(value==3){
                cout<<"b"<<endl;
            }else if(value==4){
                cout<<"R"<<" "<<rand()%1000<<" "<<rand()%1000<<endl;
            }else if(value==5){
                cout<<"S"<<endl;
            }
	}
	
}