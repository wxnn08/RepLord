#include<iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	cout <<rnd.next(0, (int)1000) <<endl;
	cout <<rnd.next(1, (int)1000) <<' ' <<rnd.next(1, 1000) <<endl;
	cout <<rnd.next(1, (int)1000) <<' ' <<rnd.next(1, 1000) <<endl;
	cout <<rnd.next(1, (int)1000) <<' ' <<rnd.next(1, 1000) <<endl;


	return 0;
}
