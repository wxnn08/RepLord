#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int cont=0;
	string n;
	char vogal[55];
	cin >>n;
	
	for(int i=0; i<n.size(); i++){
		if(n[i]=='a' || n[i]== 'e' || n[i] =='i' || n[i] == 'o' || n[i] == 'u'){
			vogal[cont]=n[i];
			cont++;
		}
	}
	
	int l=cont, stop=0;
	
	for(int i=0; i<=(l/2) && stop==0; i++){
		if(vogal[i]!=vogal[l-i-1]) {
			cout <<"N";
			stop=1;
		}
	}
	if(stop==0) cout <<"S";
	
	return 0;
}
