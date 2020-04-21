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

const int N = 5e5 + 5;
ll t[N];

ll query(int x) {
	ll ans = 0;
	while(x > 0) {
		ans += t[x];
		x -= (x & -x);
	}
	return ans;
}

void update(int x, ll v) {
	while(x < N) {
		t[x] += v;
		x += (x & -x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		

	}
	
	return 0;
}

