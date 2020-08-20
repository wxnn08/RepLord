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

struct node {
	int u, v;
	ll w;

	bool operator < (const node &a) const {
		return w < a.w;
	}
};

int pai[N];
ll qtd[N];

void init(int n) {
	for(int i = 0; i <= n; i++) {
		qtd[i] = 1LL;
		pai[i] = i;
	}
}

int find(int x) {
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void join(int x, int y) {
	int a = find(x);
	int b = find(y);
	if(qtd[a] > qtd[b]) swap(a, b);
	pai[a] = b;
	qtd[b] += qtd[a];
}

ll calc(ll n) {
	return (n*(n-1))/2LL;
}

int main() {
	// ios_base::sync_with_stdio(false);

	int n, m;
	cin >>n >>m;
	vector<node> v;
	vector<pair<ll, int>> q;
	
	init(n);
	for(int i = 0; i < n-1; i++) {
		int a, b;
		ll w;
		cin >>a >>b >>w;
		v.pb({a, b, w});
	}
	for(int i = 0; i < m; i++) {
		ll a; cin >>a;
		q.eb(a, i);
	}
	
	sort(q.begin(), q.end());
	sort(v.begin(), v.end());
	
	int i = 0;
	vector<pair<int, ll>> ans;
	ll ansAt = 0;
	for(auto at:q) {
		while(i < (int)v.size() and v[i].w <= at.fi) {
			ansAt = ansAt - (calc(qtd[find(v[i].u)]) + calc(qtd[find(v[i].v)]));
			join(v[i].u, v[i].v);
			ansAt += calc(qtd[find(v[i].u)]);
			i++;
		}
		ans.eb(at.se, ansAt);
	}

	sort(ans.begin(), ans.end());
	for(auto at:ans) {
		cout <<at.se <<' ';
	}
	cout <<endl;

	return 0;
}

