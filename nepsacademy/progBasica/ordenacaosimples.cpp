#include <bits/stdc++.h>
using namespace std;

int main (){

	int v[100100];
	int n;

	cin >>n;

	for(int i=0; i<n; i++){
		cin >>v[i];
	}
	
	sort(v, v+n);

	for(int i=0; i<n; i++){
		cout << v[i] <<" ";
	}

	cout <<endl;
	return 0;
}
