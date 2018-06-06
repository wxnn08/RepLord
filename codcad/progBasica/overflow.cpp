#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b;
	char op;
	cin >>n >>a >>op >>b;

	if(op=='+')a+=b;
	else a*=b;

	if(a>n) cout <<"OVERFLOW";
	else cout <<"OK";

return 0;
}
