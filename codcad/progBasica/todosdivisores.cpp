#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int x,n;
	cin >>x;
	
	n=1;
	while(n<=(x/2)){
		if(x%n==0) cout <<n <<" ";
		n++;
	}
	cout <<x;

return 0;
}
