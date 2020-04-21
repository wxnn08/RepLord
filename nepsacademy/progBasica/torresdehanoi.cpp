#include<bits/stdc++.h>
using namespace std;

int hanoi(int n){
	if(n==1) return 1;
	else return 2*hanoi(n-1)+1;
}

int main(){
	int n;
	for(int i=1;;i++){
		cin >>n;
		if(n==0) break;

		else{
			cout <<"Teste " <<i <<endl;
			cout <<hanoi(n) <<endl <<endl;
		}
	}
	
	return 0;
}
