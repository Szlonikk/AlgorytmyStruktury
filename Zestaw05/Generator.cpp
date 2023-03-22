#include <iostream>
#include <time.h>

using namespace std;

int main (int argc, char *argv[]) {
	
	int n = atoi (argv[1]);
	int i = atoi (argv[2]);
	
	for (n; n>0; n--) {
		cout << rand() % i << endl;
	}
	
}