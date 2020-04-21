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

ll sum(ll n) {
	return (n*(n+1))/2;
}
 
ll search(ll x) {
	ll l = 1, r = 1e9;
	ll ans = 1;
	while(l <= r) {
		ll mid = (l+r)>>1LL;
		if(sum(mid) <= x) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	ll n;	
	cin >>n;
	ll qtd = sum(n-1);
	if(n <= 3) cout <<n-1 <<endl;
	else cout <<n-search(qtd/2)-1 <<endl;
	
	return 0;
}

