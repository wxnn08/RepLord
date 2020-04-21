#include<bits/stdc++.h>
using namespace std;

int main(){
	int h,p,f,d;
	cin >>h >>p >>f >>d;

	if(d==-1){
		if(h<f){
			if(p>h && p<f)	cout <<"N";
			else 			cout <<"S"; 
		}
		else{
			if(p>f && p<h)	cout <<"S";
			else 			cout <<"N";
		}

	}

	if(d==1) {
		
		if(h<f){
			if(p>h && p<f)	cout <<"S";
			else 			cout <<"N"; 
		}
		else{
			if(p>f && p<h)	cout <<"N";
			else 			cout <<"S";
		}

	}

return 0;
}
