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
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

ll cont_inv(vector<ll> &v) {
	if(v.size() == 1) return 0;

	ll contInv = 0;
	vector<ll> v1,v2;
	for(int i = 0; i < v.size()/2; i++) v1.pb(v[i]);
	for(int i = v.size()/2; i < v.size(); i++) v2.pb(v[i]);

	contInv += cont_inv(v1);
	contInv += cont_inv(v2);

	v1.pb(INF);
	v2.pb(INF);

	int c1 = 0, c2 = 0;
	ll cont = 0;
	for(int i = 0; i < v.size(); i++) {
		if(v1[c1] <= v2[c2]) {
			v[i] = v1[c1++];
			cont++;
		}
		else {
			v[i] = v2[c2++];
			contInv += cont;
		}
	}

	return contInv;
}
 
int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	vector<ll> v;
	for(int i = 0; i < n; i++) {
		ll x, y;
		cin >>x >>y;
		v.pb(x*x+y*y);
	}
	
	cout <<cont_inv(v) <<endl;
	
	return 0;
}

