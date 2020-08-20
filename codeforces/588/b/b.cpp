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

const int N = 1e6+5;
vector<int> primes;
bool notPrime[N];


void sieve() {
	for(ll i = 2; i < N; i++) {
		if(notPrime[i]) continue;
		primes.pb(i);
		for(ll j = i+i; j < N; j += i) {
			notPrime[j] = true;
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);

	ll n;
	cin >>n;
	
	sieve();
	vector<ll> select;
	for(ll prime:primes) {
		if(n%prime == 0) select.pb(prime);
		while(n%prime == 0) n /= prime;
	}
	if(n > 1) select.pb(n);

	ll ans = 1;
	for(ll at:select) ans *= at;
	cout <<ans <<endl;
	
	return 0;
}

