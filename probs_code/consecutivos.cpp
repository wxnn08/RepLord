#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin >>n;
	
	int max=1,MAX=0,ant=0,at;
	for(int i=0; i<n; i++){
		cin >>at;
		
		if(at==ant)max++;
		else{
			if(max>MAX) MAX=max;
			max=1;
			ant=at;
		}

	}
	if(max>MAX) MAX=max;

	cout <<MAX;

return 0;
}
