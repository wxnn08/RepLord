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
 
const int N = 1e5 + 5;
int v[N];
ii maior[N];
ii menor[N];

int main() {
	ios_base::sync_with_stdio(false);

	string s;
	cin >>s;
	int n = s.size();

	for(int i = 0; i < n; i++) {
		if(s[i] == 'B') v[i+1] = v[i]+1;
		else v[i+1] = v[i]-1;
	}

	maior[n] = mk(v[n], n);
	menor[n] = mk(v[n], n);
	for(int i = n-1; i >= 0; i--) {
		maior[i] = maior[i+1];
		menor[i] = menor[i+1];
		if(maior[i].fi <= v[i]) maior[i] = mk(v[i], i);
		if(menor[i].fi >= v[i]) menor[i] = mk(v[i], i);
	}
	
	int id = 0;
	for(int i = 0; i < n; i++) {
		if(max(abs(menor[id].fi-v[id]), abs(maior[id].fi-v[id])) < 
			max(abs(menor[i].fi-v[i]), abs(maior[i].fi-v[i]))) {
			id = i;
		}
	}
		
	if(abs(menor[id].fi-v[id]) > abs(maior[id].fi-v[id])) {
		cout <<id+1 <<' ' <<menor[id].se <<endl;
	} else {
		cout <<id+1 <<' ' <<maior[id].se <<endl;
	}

	return 0;
}

