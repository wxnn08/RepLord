#include <bits/stdc++.h>
using namespace std;

int main(){
	
	double l, a, p, r;
	cin >>l >>a >>p >>r;
	
	double l2, a2, p2; 
	
	l2 = pow(a,2);
	a2 = pow(l,2);
	p2 = pow(p,2);

	double d = 2*r;

	if(sqrt(l2+a2)<=d && sqrt(l2+p2)<=d && sqrt(a2+p2)<=d){
		cout<< "S";
	}
	else cout << "N";

	return 0;
}
