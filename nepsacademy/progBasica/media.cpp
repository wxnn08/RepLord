#include<bits/stdc++.h>
using namespace std;

int main (){
	
	float a,b;
	cin >>a >>b;
	a=(a+b)/2;

	if(a>=7) cout << "Aprovado";
	else if (a>=4) cout <<"Recuperacao";
	else cout <<"Reprovado";

return 0;
}
