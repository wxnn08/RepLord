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

	int tc;
	cin >>tc;
	while(tc--) {
		ll n, m;
		cin >>n >>m;
		vector<ll> last;
		ll sum = 0;
		for(ll i = 1; i <= 10; i++) {
			last.pb((i*m)%10LL);
			sum += last.back();
		}
		ll qtdInt = (n/m)/10LL;
		ll ans = qtdInt * sum;
		for(ll i = 0; i < (n/m) - (qtdInt*10LL); i++) {
			ans += last[i];
		}
		cout <<ans <<endl;
	}
	
	return 0;
}

