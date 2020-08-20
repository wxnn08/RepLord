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

	string s;
	cin >>s;

	int l = 0;
	ll tam = (ll) s.size();
	ll total = (tam*(tam+1))/2;
	cc(total);
	ll qtdRemove = 0;
	for(int i = 3; i < s.size(); i++) {
		if((s[i-3] == 'b' and s[i-2] == 'e' and s[i-1] == 'a' and s[i] == 'r') or i == s.size()-1) {
			ll n = i-l;
			qtdRemove += ((n*(n+1))/2);
			l = i+1;
		}
	}

	cout <<qtdRemove <<endl;
	
	return 0;
}

