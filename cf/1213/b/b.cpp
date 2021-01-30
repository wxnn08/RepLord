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

const int N = 2e5;

int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >>tc;
	int v[N];
	while(tc--) {
		int n; cin >>n;
		for(int i = 0; i < n; i++) cin >>v[i];
		int menor = v[n-1];
		int ans = 0;
		for(int i = n-1; i >= 0; i--) {
			if(v[i] > menor) ans++;
			else menor = min(menor, v[i]);
		}
		cout <<ans <<endl;
	}
	
	return 0;
}

