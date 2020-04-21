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

ll k, p, x;

double cost(ll m) {
	return m*x + ((double)k/m) * p;
}

double search(ll l, ll r) {
	while(r-l > 1) {
		ll mid = (l+r)>>1;
		if(cost(mid) < cost(mid+1)) r = mid;
		else l = mid;
	}
	return cost(l+1);
	
}

 
int main() {
	ios_base::sync_with_stdio(false);

	cin >>k >>p >>x;
	cout <<fixed <<setprecision(3) <<search(0, 1e9) <<endl;
	
	return 0;
}

