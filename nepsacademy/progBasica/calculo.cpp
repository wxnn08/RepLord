#include<bits/stdc++.h>
using namespace std;

int v[1010], w[1010], res[1010];
int main(){

	int m,n, beg, val=0; //m-> vetor v, n-> vetor w
	cin >>m >>n;
	char c ='0';
	
	for (int i=0; i<m; i++){
		cin >>v[i];	
	}
	
	for(int i=0; i<n; i++){
		cin >>w[i];
	}
	
	if(m>n){
		beg=n-1;
		c='n';
	}
	else if(n>m){
		beg=m-1; 
		c='m';
	}
	else 
		beg=m-1; //qualquer um
	
	
	for(int i=beg; i>=0; i--){
		res[i]+=v[i]+w[i];
		
		if(res[i]==2){
			res[i]=0;
			res[i-1]=1;
		}
		
		else if(res[i]==3){
			res[i]=1;
			res[i-1]=1;
		}
		
		if(res[i]!=0 && i>=val)
			val=i;
	}

	if(c=='n')
		for(int i=n; i<m; i++){
			res[i]=v[i];
			
			if(res[i]!=0 && i>=val)
				val=i;
		}
	if(c=='m')
		for(int i=m; i<n; i++){
			res[i]=w[i];
		
		if(res[i]!=0 && i>=val)
			val=i;
		}
	
	for(int i=0; i<=val; i++){
		cout <<res[i] <<" ";
	}

return 0;
}
