#include<bits/stdc++.h>
using namespace std;

string title (string F){
	
	bool up = true;
	for(int i=0; i<F.length(); i++){
		if(up){
			F[i] = toupper(F[i]);
			up = false;
		}
		else{
			F[i] = tolower(F[i]);
		}

		if(F[i]==' ') up=true;
	}

	return F;
}

int main (){
	
	string F;
	getline(cin, F);

	cout <<title(F) <<endl;

	return 0;
}
