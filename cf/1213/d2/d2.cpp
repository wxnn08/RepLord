/* O nosso maior medo não é sermos inadequados.
O nosso maior medo é sermos infinitamente poderosos.
É a nossa própria luz, não a nossa escuridão, que nos amedronta.
Sermos pequenos não engrandece o mundo.
Não há nada de transcendente em sermos pequenos,
pois assim os outros não se sentirão inseguros ao nosso lado.
Todos estamos destinados a brilhar, como as crianças.
Não apenas alguns de nós, mas todos.
E, enquanto irradiamos a nossa admirável luz interior,
inconscientemente estamos a permitir aos outros fazer o mesmo.
E, quando nos libertarmos dos nossos próprios medos,
a nossa presença automaticamente libertará os medos dos outros.  */

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
 
const int N = 2e5 + 5;

int main() {
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >>n >>k;
	vector<pair<int, int>> v;
	int ans = 21*N;
	for(int i = 0; i < n; i++) {
		int a; cin >>a;
		int cont = 0;
		v.eb(a, cont);
		while(a > 0) {
			a /= 2;
			v.eb(a, ++cont);
		}
	}

	sort(v.begin(), v.end());
	int cont = 1;
	int ansAt = v[0].se;
	for(int i = 1; i < (int)v.size(); i++) {
		if(v[i].fi != v[i-1].fi) cont = 1, ansAt = v[i].se;
		else cont++, ansAt += v[i].se;
		if(cont == k) {
			ans = min(ans, ansAt);
		}
	}
	cout <<ans <<endl;
	return 0;
}

