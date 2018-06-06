#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ll a, b, dif;
	cin >>a >>b;
	int res=1;
	dif = b-a;

	if(dif>9) {
		res=0;
	}
	else {
		a = a%10;
		b = b%10;
		if(a>b) res=0;
		else{
			for(int i=b; i>a; i--){
				res *= i;
			}
			res %= 10;
		}
	}

	cout <<res <<endl;
	return 0;
}
