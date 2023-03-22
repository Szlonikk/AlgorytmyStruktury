#include <iostream>
#include <unistd.h>
#include "ArrayStackONP.hpp"
#include <list>

using namespace std;

bool ifNumber(char sign)
{   
	if(sign > 47 && sign < 58){
        return true;
    }
    return false;
}
// bool ifOper(char c)
// {   if(c == '+' || c == '-' || c == '*' || c == '/' || c=='^'){
// 	return 1;
//     }
//     else return 0;

// }

int priority(char x) {
        if(x==')' || x=='('){
            return 0;
        } 
        if (x == '+' || x == '-') {
            return 1;
        }  
        if (x == '*' || x == '/') {
            return 2;
        }
        return 3;
    }


int main(){
    string in;
    string out;
    char sign;
    getline(cin,in);
    Stack stack;
    bool wasNumber=false;
    for(int i=0;i<in.size();i++){
        
        sign=in[i];
        
        if (sign == ' ') {  //ignorujemy spacje na wejsciu
			if(wasNumber){  //dajemy spacje dopiero jak cyfra sie nie powtarza
                out+=" ";
                wasNumber=false;
            }
            continue;
		}


        if(ifNumber(sign)){     //jezeli mamy cyfre to wypisujemy
            out+=sign;
            wasNumber=true;

        }else if(sign=='('){
            stack.push(sign);

        }else if (sign == ')') {	
                while (stack.peek() != '(') {   //wypisujemy do outputu wszystko az znajdziemy nawias otwierajacy
					out += stack.pop();
			        out += " ";
				}
				stack.pop();    // zabieramy tez ten znak "("

			}else if ((priority(sign) > priority(stack.peek())) && stack.size() > 0) { // otrzymany priorytet jest wiekszy niz na stosie
				stack.push (sign);                                                     // to wrzucamy na stos
        
            } else {
				while ((priority(sign) <= priority(stack.peek())) && stack.size() > 0) { // jezeli priotytet jest nizszy lub rowny
					out += stack.pop(); // zabieramy ze stosu wszystkie elementy az do  spotkania wyzszego priorytetu
					out += " ";
				}
				stack.push (sign);  //wrzucamy na stos aktualny znak
			}
		
		
	}
    while (stack.size() > 0) {
       
		out += " ";             // wrzucamy na wyjscie to co zostalo
		out += stack.pop();
	}
    if(out[out.size()-1]==' '){
        out.pop_back();         // usuwamy spacje z konca zeby testy przejsc
    }

    cout<<out<<endl;
}