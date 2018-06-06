#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n, v[100010], v2[100010];
	cin >>n;
	
	for(int i=0; i<n; i++){
		cin >>v[i];
		v2[i]=v[i];
	}
	
	sort(v2, v2+n);
	
	int cont=0, num[100010];
	for(int i=0; i<n; i++){
		if(v[i]!=v2[i]){
			num[cont]=v[i];	
			cont++;
		}
	}

	cout <<cont <<endl;
	sort (num, num+cont);
	for(int i=0; i<cont; i++){
		cout << num[i] <<" ";
	}
			

	return 0;
}
