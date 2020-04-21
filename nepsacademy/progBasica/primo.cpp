#include<bits/stdc++.h>
using namespace std;

bool ehPrimo(int n){
	
	if(n==2) return true;
	if(n==1) return false;
	if(n%2==0) return false;

	for(int i=3;i<=sqrt(n);i+=2){
		if(n%i==0) return false;
	}

	return true;
}

int main(){

	int x;
	cin >>x;

	if(ehPrimo(x)){
		cout <<"S" <<endl;
	}
	else{
		cout <<"N" <<endl;
	}

	return 0;
}
