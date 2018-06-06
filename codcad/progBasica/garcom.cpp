#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n,l,c, num=0;
	cin >>n;

	for(int i=0; i<n; i++){
		cin >>l >>c;
		if(l>c) num+=c;
	}
	cout <<num;

return 0;
}
