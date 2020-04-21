/* Aí, você já parou pra pensar, por que que você vive?
 * O que é que te move?
 * Aquele momento que decodifica o segredo da sua alma
 * E de repente tudo começa a fazer sentido.
 * É um chamado legítimo que vem lá do íntimo 
 * É quando a poesia entra em sincronia com o ritmo 
 * E te faz pensar 
 * Se não fosse isso eu podia até respirar, mas vivo eu também não ia tá!
 */
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int mat[25][25];
int calc(int ii, int jj) {
	ll ans = 0;
	ll at;
	if(ii+3 < 20) {
		at = 1;
		for(int i = 0; i < 4; i++) 
			at *= mat[ii+i][jj];
		ans = max(at, ans);
	}
	if(jj+3 < 20) {
		at = 1;
		for(int i = 0; i < 4; i++) 
			at *= mat[ii][jj+i];
		ans = max(at, ans);
	}

	if(ii+3 < 20 and jj+3 < 20) {
		at = 1;
		for(int i = 0; i < 4; i++) 
			at *= mat[ii+i][jj+i];
		ans = max(at, ans);
	}
	if(ii+3 < 20 and jj+3 < 20) {
		at = 1;
		for(int i = 0; i < 4; i++) 
			at *= mat[ii+i][jj-i];
		ans = max(at, ans);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n = 20;

	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) 
			cin >>mat[i][j];
	
	int ans = 0;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) 
			ans = max(ans, calc(i, j));

	cout <<ans <<endl;
	return 0;
}

