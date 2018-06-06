#include<bits/stdc++.h>
using namespace std;

int v[95], w[95];
int main(){
		
	int n,b,dif, somaV;
	while(1){
		cin >>n >>b;
		if(n==0 && b==0) break;

		for(int i=0; i<b; i++){
			cin >>v[i];
		}

		for(int i=0; i<=n; i++){
			w[i]=i;
		}
		
		for(int i=0;i<b;i++){
			for(int j=0;j<b;j++){	
				dif=abs(v[i]-v[j]);
				if(dif<=n)
					w[dif]=-1;
			}
		}
		
		for(int i=0; i<=n; i++){
			if(w[i]!=-1){
				cout <<"N" <<endl;
				break;
			}
			if(i==n)
				cout <<"Y" <<endl;

		}
	}

	

return 0;
}
