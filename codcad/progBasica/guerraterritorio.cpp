#include<bits/stdc++.h>
using namespace std;

int main(){

	int v[100010];
	int soma=0, n;
	cin >>n;

	for(int i=0; i<n; i++){
		cin >> v[i];
		soma += v[i];
	}
	
	int val=soma/2;
	soma = 0;
	for(int i=0; i<n; i++){
		soma += v[i];
		if(val==soma){
			cout <<i+1;
			break;
		}
	}

return 0;
}
