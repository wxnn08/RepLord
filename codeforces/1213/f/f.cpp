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
 
int main() {
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >>n >>k;
	vector<ii> it;
	for(int i = 1; i <= n; i++) {
		int a; cin >>a;
		if(a > i) it.eb(min(i, a), 1), it.eb(max(i, a)+1, -1);
	}
	for(int i = 1; i <= n; i++) {
		int a; cin >>a;
		if(a > i) it.eb(min(i, a), 1), it.eb(max(i, a)+1, -1);
	}
	sort(it.begin(), it.end());

	int cont = 0;
	int posIt = 0;
	int id = 1;
	vector<int> v;
	for(int i = 1; i <= n; i++) {
		while(posIt < (int)it.size() and it[posIt].fi == i) {
			cont += it[posIt].se;
			posIt++;
		}
		if(cont == 0) {
			v.pb(id++);
		} else {
			v.pb(id);
		}
	}

	if(v.back() < k) {
		cout <<"NO" <<endl;
		return 0;
	}
	cout <<"YES" <<endl;
	cont = 0;
	char charAt = 'a';
	for(int i = 0; i < n; i++) {
		if(v[i] <= v.back()-k+1) cout <<(char)charAt;
		else {
			if(v[i] != v[i-1]) cout <<(char)(++charAt);
			else cout <<(char)charAt;
		}
	}
	cout <<endl;
	return 0;
}
