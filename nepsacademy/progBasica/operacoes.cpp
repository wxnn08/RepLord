#include<bits/stdc++.h>
using namespace std;

int main(){

	char op;
	cin >>op;
	
	double a,b;
	cin >>a >>b;

	if(op=='M') cout <<fixed <<setprecision(2) <<a*b;
	else cout <<fixed <<setprecision(2) <<a/b;

return 0;
}
