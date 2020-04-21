#include<bits/stdc++.h>
using namespace std;

int main() {

	int v[4] = {50, 10, 5, 1};
	int tc = 1;
	int n;
	while(cin >>n) {
		if(n == 0) return 0;	
		cout <<"Teste " <<tc++ <<endl;
		for(int i = 0; i < 4; i++) {
			cout <<n/v[i] <<' ';
			n -= ((n/v[i]) * v[i]);
		}
		cout <<endl <<endl;
	}
	return 0;
}
