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

const int N = 3e5;
ll seg[4*N + 5];

void build(int r, int i, int j, int a, int b) {
	if(j < a or i > b) return;
	if(i == j) {
		seg[r] = 0;
		return;
	}
	int mid = (i+j)>>1;
	build(2*r, i, mid, a, b);
	build(2*r+1, mid+1, j, a, b);
	seg[r] = 0;
}

void update(int r, int i, int j, int pos, ll val) {
	if(j < pos or i > pos) return;
	if(i >= pos and j <= pos) {
		seg[r] += val;
		return;
	}
	int mid = (i+j)>>1;
	update(2*r, i, mid, pos, val);
	update(2*r+1, mid+1, j, pos, val);
	seg[r] = seg[2*r] + seg[2*r+1];
}

ll query(int r, int i, int j, int a, int b) {
	if(j < a or i > b) return 0;
	if(i >= a and j <= b) return seg[r];
	int mid = (i+j)>>1;
	return query(2*r, i, mid, a, b) + query(2*r+1, mid+1, j, a, b);
}

int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >>tc;
	
	while(tc--) {
		int n; cin >>n;
		vector<ll> v;
		vector<ll> ve;
		for(int i = 0; i < n; i++) {
			ll a; cin >>a;
			v.pb(a);
			ve.pb(v[i]);
		}
		// Compressão de coordenadas
		sort(ve.begin(), ve.end());
		ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
		map<ll, ll> id;
		ll last = ve.size();
		for(ll i = 0; i < last; i++) id[ve[i]] = i;
		for(int i = 0; i < n; i++) v[i] = id[v[i]];
		// ------------------------

		build(1, 0, N, 0, N);
		ll ans = 0;
		for(int i = 0; i < n; i++) {
			ans += query(1, 0, last, v[i]+1, last);
			update(1, 0, last, v[i], 1);
		}
		cout <<ans <<endl;
	}
	
	return 0;
}
