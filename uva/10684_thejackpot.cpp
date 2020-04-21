#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >>n;
    
    int soma, maior, aux;
    while(n){
	soma = 0;
	maior = 0;
	fori(i, 0, n){
	    cin >>aux;
	    soma+=aux;
	    if(soma<0) soma=0;
	    maior = max (maior, soma);
	}
	
	if(soma>0) cout <<"The maximum winning streak is " <<maior <<'.' <<endl;
	else cout <<"Losing streak." <<endl;
	cin >>n;
    }
    
    return 0;
}

