#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, max=-1;

	while(true){
		cin >>n;
		if(n==0) break;
		if(n>max) max=n;
	}
	cout <<max;

return 0;
}
