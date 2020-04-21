#include <bits/stdc++.h>
using namespace std;

int main(){

	int n,p,e1,e2;
	cin >>n >>p;
	
	int i=0, cont=0;
	while(i<n){
		
		cin >>e1 >>e2;
		
		if((e1+e2)>=p) cont ++;
		
		e1=0;
		e2=0;
		i++;
	}

	cout <<cont;

return 0;
}
