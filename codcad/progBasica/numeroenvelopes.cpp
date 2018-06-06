#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, r, min;
	cin >>n;
	cin >>r;
	min=r;
	for(int i=1; i<n; i++){
		cin >>r;
		if(r<min) min=r;
	}
	cout <<min;
	
return 0;
}
