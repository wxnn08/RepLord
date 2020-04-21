#include<bits/stdc++.h>
using namespace std;
/*
1- 1 2 3 
2- 1 3 2 
3- 2 1 3 
4- 2 3 1
5- 3 1 2 
6- 3 2 1
*/

int main (){
	int a,b,c;
	cin >>a >>b >>c;

	if(a<b && b<c)
		cout << "1\n2\n3";

	else if(a<c && c<b)
		cout << "1\n3\n2";

	else if(b<a && a<c)
		cout << "2\n1\n3";
	
	else if(b<c && c<a)
		cout <<"2\n3\n1";

	else if(c<a && a<b)
		cout <<"3\n1\n2";
	
	else
		cout <<"3\n2\n1";

	

return 0;
}
