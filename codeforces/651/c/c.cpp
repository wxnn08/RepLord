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
typedef pair<ll,ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

ll choose2(ll n) {
	if(n == 1) return 0;
	return (n*(n-1))/2;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	vector<ii> v;
	for(int i = 0; i < n; i++) {
		ll a, b;
		cin >>a >>b;
		v.eb(a, b);
	}

	sort(v.begin(), v.end());

	ll toRm = 0;
	ll cont = 1;
	for(int i = 1; i < n; i++) {
		if(v[i] == v[i-1]) cont++;
		else {
			toRm += choose2(cont);
			cont = 1;
		}
	}
	toRm += choose2(cont);

	ll total = 0;
	cont = 1;
	for(int i = 1; i < n; i++) {
		if(v[i].fi == v[i-1].fi) cont++;
		else {
			total += choose2(cont);
			cont = 1;
		}
	}
	total += choose2(cont);

	sort(v.begin(), v.end(), [] (const ii &a, const ii &b) {
		return a.se < b.se;
	});

	cont = 1;
	for(int i = 1; i < n; i++) {
		if(v[i].se == v[i-1].se) cont++;
		else {
			total += choose2(cont);
			cont = 1;
		}
	}
	total += choose2(cont);

	cout <<total-toRm <<endl;
	
	return 0;
}

