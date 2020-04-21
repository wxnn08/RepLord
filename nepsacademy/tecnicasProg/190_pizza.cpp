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

int kadane(vector<int> &v) {
	int ans = 0;
	int maior = 0;
	for(int i = 0; i < v.size(); i++) {
		maior = max(0, maior + v[i]);
		ans = max(ans, maior);
	}
	return ans;
}
 
int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	
	vector<int> v;
	for(int i = 0; i < n; i++) {
		int a; cin >>a;
		v.pb(a);
	}
	
	int r1 = kadane(v);

	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += v[i];
		v[i] = -v[i];
	}

	int r2 = kadane(v);
	r2 += sum;

	cout <<max(r1, r2) <<endl;
	
	return 0;
}

