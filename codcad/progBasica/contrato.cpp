#include<bits/stdc++.h>
using namespace std;

int main(){

	int zero,vazio;
	char d;
	string n;
	

	while(1){
		zero=1;
		vazio=1;

		cin >>d >>n;
		if(d=='0' && n=="0") break;	

		for(int i=0; i<n.size(); i++){
			if(n[i]!=d){

				if(n[i]!='0'){
					zero=0;
				}
				
				if(zero==0){
					cout<<n[i];
					vazio =0;
				}
			}
		}
		if(vazio==1) cout <<"0"; 
		cout <<endl;
	}
return 0;
}
