#include<bits/stdc++.h>
using namespace std;

int v[30];
int main(){
	while(1){
		int b, n, d, c, val, fim=0;
		cin >>b >>n;
		
		if(b==0 && n==0) break;

		for (int i=0; i<b; i++){
			cin >>v[i];
		}
		
		for(int i=0; i<n; i++){
			cin >>d >>c >>val;
			v[d-1]-=val;
			v[c-1]+=val;
		}

		for(int i=0;i<b;i++){
			if(v[i]<0) fim=1;
		}

		if(fim==1) cout <<"N" <<endl;
		else cout <<"S" <<endl;
	}
return 0;
}
