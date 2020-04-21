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
 
const int N = 1e7+5;

vector<int> ps;
int vis[N];

void sieve() {
	for(int i = 2; i < N; i++) {
		if(vis[i]) continue;
		ps.pb(i);
		for(int j = i+i; j < N; j += i) {
			vis[j] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	
	sieve();
	
	int n;
	while(cin >>n) {
		if(n < 8) {
			cout <<"Impossible." <<endl;
			continue;
		}
		
		int val = 2 + (n%2);
		cout <<2 <<' ' <<val <<' ';
		n -= (2 + val);
		for(int at:ps) {
			if(binary_search(ps.begin(), ps.end(), n-at)) {
				cout <<at <<' ' <<n-at <<endl;
				break;
			}
		}
	}

	return 0;
}
