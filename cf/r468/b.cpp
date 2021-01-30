#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    //le n, a e b
    int n, a, b, round=0;
    cin >>n >>a >>b;
    
    //enquanto a!=b, faça:
    while(a!=b){

	//incremente a variavel round
	round++;

	// a=a/2+a%2 e b=b/2 + b%2, simulando cada round
	a=(a/2)+(a%2);
	b=(b/2)+(b%2);
    }
    
    if(round==log(n)/log(2)) cout <<"Final!";
    //se não, imprima round
    else cout <<round;
    
    cout <<endl;
    
    return 0;
}

