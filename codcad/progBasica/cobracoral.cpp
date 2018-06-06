#include <bits/stdc++.h>
using namespace std;

int main(){

	int a,b,c,d;
	cin >>a >>b >>c >>d;

	if (a==c && b!=a && b!=d)
			cout <<"V";
			
	else if(b==d && c!=b && c!=a)
			cout <<"V";

	else cout <<"F";

return 0;
}
