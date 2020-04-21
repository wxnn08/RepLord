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

const int N = 1e5+5;
ll tree[N];

ll query(int x) {
	ll ans = 0;
	while(x > 0) { 
		ans += tree[x];
		x -= (x & -x);
	}
	return ans;
}

void update(int x, ll v) {
	while(x < N) {
		tree[x] += v;
		x += (x & -x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	vector<ll> v;
	vector<ll> ve;
	for(int i = 0; i < n; i++) {
		ll a, b; cin >>a >>b;
		v.pb(a*a+b*b);
		ve.pb(a*a+b*b);
	}
	
	map<ll, int> id;
	sort(ve.begin(), ve.end());
	ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
	for(int i = 0 ; i < ve.size(); i++) id[ve[i]] = i+1;
	for(int i = 0; i < n; i++) v[i] = id[v[i]];
	
	ll ans = 0;
	for(auto at:v) {
		ans += query(at);
		update(at, 1LL);
	}
	cout <<ans <<endl;
	return 0;
}

