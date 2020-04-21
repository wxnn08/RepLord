#include <bits/stdc++.h>
using namespace std;

int main(){

	int h1,h2,m1,m2,res;

	while (true){
		cin >>h1 >>m1 >>h2 >>m2;
		
		if(h1==0 && m1==0 && h2==0 && m2==0) break;
		
		int t1, t2;

		t2=(h2*60)+m2;
		t1=(h1*60)+m1;

		if(t1<t2){
			cout <<t2-t1;
		}
		else if(t1>t2){
			t1=1440-t1;
			cout <<t1+t2;
		}

		else if (t1==t2) cout << "1440";

		cout <<endl;
	}
return 0;
}
