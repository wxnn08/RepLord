#include<bits/stdc++.h>
using namespace std;

int main (){
	string a,b;
	cin >>a;
	
	for(int i=0; i<a.size(); i++){

		if(a[i]=='A' || a[i]=='B' ||a[i]=='C') a[i]='2';
		else if(a[i]=='D' || a[i]=='E' ||a[i]=='F') a[i]='3';
		else if(a[i]=='G' || a[i]=='H' ||a[i]=='I') a[i]='4';
		else if(a[i]=='J' || a[i]=='K' ||a[i]=='L') a[i]='5';
		else if(a[i]=='M' || a[i]=='N' ||a[i]=='O') a[i]='6';
		else if(a[i]=='P' || a[i]=='Q' ||a[i]=='R' || a[i]=='S') a[i]='7';
		else if(a[i]=='T' || a[i]=='U' ||a[i]=='V') a[i]='8';
		else if(a[i]=='W' || a[i]=='X' ||a[i]=='Y' || a[i]=='Z') a[i]='9';
	}

	cout <<a;
return 0;
}
