#include <iostream>
#include "math/math.h"

using namespace std;

int main(int argc, char ** argv) {
	if (argc == 3) {
		int a = 0;
		int b = 0;
		int i = 0;
		while (argv[1][i] != 0) {
			a = a * 10 + argv[1][i] - '0';		
			i++;
		}
		i = 0;
		while (argv[2][i] != 0) {
			b = b * 10 + argv[2][i] - '0';		
			i++;
		}		
		cout << add(a, b) << endl;
	} else {
		cout << "invalid" << endl;
	}
}
