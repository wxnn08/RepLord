#include <bits/stdc++.h>
using namespace std;

int n, m[11][11], val=0, test, test2;

bool isMagicH(){

	for(int j=0; j<n; j++){	
		test=0;

		for(int i=0; i<n; i++){
			test+=m[i][j];
		}
		
		if(test!=val) 
			return 0;
	}

	return 1;

}

bool isMagicV(){

	for(int i=0; i<n; i++){	
		test=0;

		for(int j=0; j<n; j++){
			test+=m[i][j];
		}
		
		if(test!=val) 
			return 0;
	}

	return 1;
}

bool isMagicD(){

	test=0;
	test2=0;

	for(int i=0; i<n; i++){
		test += m[i][i];
		test2 += m[n-1-i][i];
	}
	
	if(test!=val || test2!=val)
		return 0;

	return 1;
}

void readInput(){

	cin >>n;
	for(int i=0; i<n; i++){
		cin >>m[i][0];	
		val += m[i][0];
	}
	
	for(int j=1; j<n; j++){
		for(int i=0; i<n; i++){
			cin >>m[i][j];
		}
	}
}

int main(){
	
	readInput(); 

	if(isMagicV() && isMagicH() && isMagicD())
		cout <<val;
	else
		cout <<"-1";
	
return 0;
}
