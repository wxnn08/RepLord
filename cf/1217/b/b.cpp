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
 
int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >>tc;
	while(tc--) {
		int n; ll x;
		cin >>n >>x;
		ii maior = ii(0LL, 0LL);
		ii danudo = ii(0LL, 0LL);
		for(int i = 0; i < n; i++) {
			ll a, b;
			cin >>a >>b;
			maior = max(maior, ii(a, b));
			if(danudo.fi-danudo.se < a-b) {
				danudo = ii(a, b);
			}
		}
		if(maior.fi >= x) {
			cout <<1 <<endl;
			continue;
		}

		if(danudo.fi-danudo.se <= 0) {
			cout <<-1 <<endl;
			continue;
		}
		
		ll ans = (x-maior.fi)/(danudo.fi-danudo.se);
		if((x-maior.fi)%(danudo.fi-danudo.se) != 0) ans++;
		cout <<ans+1 <<endl;
	}
	
	return 0;
}

