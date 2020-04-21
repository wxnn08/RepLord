#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	
	cin >>a >>b >>c;

	if(a-b ==0 || a-c ==0 || b-c==0)
		cout << "S";

	else if(a+b-c==0 || a+c-b==0 || b+a-c==0 || b+c-a==0 || c+b-a==0 || c+a-b==0)
		cout << "S";

	else
		cout << "N";

return 0;
}
