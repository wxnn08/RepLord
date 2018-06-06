#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, t=0;
	cin >>n;

	char c;
	for(int i=0; i<n; i++){
		cin >>c;
		if(c=='P' || c=='C') t+=2;
		else if(c=='A') t++;
		
	}

	cout <<t;

return 0;
}
