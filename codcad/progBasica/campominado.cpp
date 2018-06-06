#include<bits/stdc++.h>
using namespace std;

int v[51];
int main(){

	int n;
	cin >>n;

	for(int i=0; i<n; i++){
		cin >>v[i];
	}

	for(int i=0; i<n; i++){
		if(i==0) cout <<v[i]+v[i+1] <<endl;
		else if(i==n-1) cout <<v[i]+v[i-1] <<endl;
		else if(i!=0 && i!=(n-1)) cout <<v[i-1]+v[i]+v[i+1] <<endl;
	}

return 0;
}
