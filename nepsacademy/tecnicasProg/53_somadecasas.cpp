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
	
	const int TAM = 1e5+5;
	vector <int> casas;
	fori(i, 0, n){
		int aux; cin >>aux;
		casas.pb(aux);
	}
    
	int k;
	cin >>k;

	int res = 0;
	int nCasa = 0;
	bool continua = true;
	while(res!=k && continua){
		if (binary_search(casas.begin(), casas.end(), k-casas[nCasa]) == true){
			continua = false;
		}
		else nCasa++;
	}
	
	cout <<casas[nCasa] <<' ' <<k-casas[nCasa] <<endl;

    return 0;
}

