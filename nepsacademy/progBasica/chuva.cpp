#include <bits/stdc++.h>
using namespace std;

int m[101][101];

int main (){
	
	int n;
	cin >>n;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >>m[i][j];
		}
	}
	
	int p;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >>p;
			cout << m[i][j]+p <<" ";
		}
		cout <<endl;
	}
return 0;
}
