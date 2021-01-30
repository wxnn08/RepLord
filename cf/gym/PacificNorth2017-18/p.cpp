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

typedef unsigned long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
ll sum(ll a, ll b) {
	ll aux = (b*b) - (a*a);
	aux += (b+a);
	return aux/2;
}

ll cont(ll n) {
	ll ans = 0;
	for(ll i = 1; i*i <= n; i++) {
		ans += (i*(n/i));
		if(i != (n/i)) 
			ans += (i * sum(n/(i+1) + 1, n/i));
	}
	return ans;
}

int main() {

	ll a, b;
	cin >>a >>b;
	cout <<cont(b) - cont(a-1) <<endl;
/*
	cout <<"-------------------------" <<endl;
	for(int i = a; i <= b; i++) {
		for(int j = 1; j <= i; j++) {
			if(i%j == 0) printf("%2d ", j);
			else cout <<"   ";
		}
		cout <<endl;
	}
*/
	return 0;
}

