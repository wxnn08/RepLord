#include<bits/stdc++.h>
using namespace std;

int main (){
	
	int n, val=0;
	char a;
	string res;
	
	cin >>n >>res;
	for (int i=0; i<n; i++){
		cin >>a;
		if(a==res[i]) val++; 
	}

	cout <<val;

return 0;
}
