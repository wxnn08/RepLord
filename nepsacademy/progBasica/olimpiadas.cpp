#include <bits/stdc++.h>
using namespace std;

int main(){

	int g1,g2,s1,s2,b1,b2;
	cin >>g1 >>s1 >>b1 >>g2 >>s2 >>b2;

	if(g1!=g2){
		if(g1>g2) cout <<"A";
		else cout <<"B";
	}
	else if(s1!=s2){
		if(s1>s2) cout <<"A";
		else cout <<"B";
	}
	else if(b1>b2) cout <<"A";
	else cout <<"B";

return 0;
}
