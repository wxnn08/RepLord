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

ll choose(ll x, ll y) {
	return (x*x*y*y+x*y*(x+y+1))/4;
}
 
int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >>tc;
	while(tc--) {
		int n, m, k;
		cin >>n >>m >>k;
		vector<ll> xs, ys;
		xs.pb(0);
		ys.pb(0);
		xs.pb(n+1);
		ys.pb(m+1);

		for(int i = 0; i < k; i++) {
			ll x, y;
			cin >>x >>y;
			xs.pb(x);
			ys.pb(y);
		}
		sort(xs.begin(), xs.end());
		sort(ys.begin(), ys.end());
		xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
		ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

		ll ans = 0;
		for(int i = 1; i < xs.size(); i++) {
			cc(xs[i]);
			ll at = choose(xs[i]-xs[i-1]-1, m);
			ans += at;
		}

		for(int i = 1; i < ys.size(); i++) {
			cc(ys[i]);
			ll at = choose(n, ys[i]-ys[i-1]-1);
			cc(at);
			ans += at;
			for(int j = 1; j < xs.size(); j++) {
				ll at2 = choose(xs[j]-xs[j-1]-1, ys[i]-ys[i-1]-1);
				cc(at2);
				ans -= at2;
			}
		}

		cout <<ans <<endl;
	}
	return 0;
}

