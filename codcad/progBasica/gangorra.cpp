#include<bits/stdc++.h>
using namespace std;

int main(){

	int p1,c1,p2,c2,e,d;
	cin >>p1 >>c1 >>p2 >>c2;
	
	e=c1*p1;
	d=c2*p2;

	if(e==d) cout <<"0";
	else if(e<d) cout <<"1";
	else cout <<"-1";
	
return 0;
}
