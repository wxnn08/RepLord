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

vector<int> v;
int solve() {
	vector<int> p;
	
	for(auto &at:v) {
		auto it = lower_bound(p.begin(), p.end(), at);
		if(it == p.end()) p.pb(at);
		else *it = at;
	}

	return p.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >>n >>m;

	unordered_map<int, int> sn;
	for(int i = 0; i < n; i++) {
		int a; cin >>a;
		sn[a] = i;
	}
	for(int i = 0; i < m; i++) {
		int a; cin >>a;
		if(sn.count(a)) v.pb(sn[a]);
	}
	
	cout <<solve() <<endl;
	
	return 0;
}

