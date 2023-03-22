#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int value;
    int numberOfOperations;

    
    //losowanie polecenia dla stosu
    srand(time(NULL));
    numberOfOperations=rand()%1000000;
    cout<<numberOfOperations<<endl;
    for(int i=0;i<numberOfOperations;i++){
        value=(rand()%3);
        if(value==0){
            cout<<"A"<<" "<<rand()%1000000<<endl;
            
        }
        else{
            if(value==2){
                cout<<"D"<<endl;
            }
            else{
                cout<<"S"<<endl;
            }
        }
    }


}