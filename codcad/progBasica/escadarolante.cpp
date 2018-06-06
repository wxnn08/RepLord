#include <bits/stdc++.h>
using namespace std;

int main(){
		
		int n,t,ant=0,total=0;
		cin >>n;

		for(int i=0; i<n; i++){
			cin >>t;
			
			if(ant==0){
				total=10;
				ant=t+10;	
			}
			
			else{
				t=t+10;
				if(t-ant<=10)  total+=t-ant;
				else total+=10;
			
				ant=t;
			}
		}
		cout <<total;

return 0;
}
