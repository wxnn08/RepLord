#include<bits/stdc++.h>
using namespace std;

int main(){

	int cv,ce,cs,fv,fe,fs;
	cin >>cv >>ce >>cs >>fv >>fe >>fs;
	cv = 3*cv+ce;
	fv = 3*fv+fe;

	if(cv!=fv){
		if (cv>fv) cout <<"C";
		else cout <<"F";
	}
	else if(cs>fs) cout <<"C";
	else if(cs<fs) cout <<"F";
	else cout <<"=";

return 0;
}
