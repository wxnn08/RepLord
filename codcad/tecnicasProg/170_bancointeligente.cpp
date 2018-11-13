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

int v[7];
int val[6] = {2,5,10,20,50,100};
int dp[7][5005]; 

int lul (int pos, int saque) {
	if(saque == 0) return 1;
	if(pos >= 6 || saque < 0) return 0;

	int &r = dp[pos][saque];
	if(r!=-1) return r;
	
	int cont = 0;
	for(int i = 0; i <= v[pos]; i++) 
		cont += lul(pos+1, saque - (val[pos]*i));

	return r = cont;
}

int main() {
    ios_base::sync_with_stdio(false);

	int qtd;
	cin >>qtd;
	memset(dp, -1, sizeof dp);

    fori(i, 0, 6) cin >>v[i];
	
	cout <<lul(0, qtd) <<endl;

    return 0;
}

