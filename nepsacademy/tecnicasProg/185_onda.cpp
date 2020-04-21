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
int m;
int lis[N][2];

void calc1(const vector<int> &v, int mode) {
	vector<int> p;
	for(int i = 0; i < m; i++) {
		auto it = lower_bound(p.begin(), p.end(), v[i]);
		if(mode == 0) lis[i][mode] = it-p.begin()+1;
		else lis[m-i-1][mode] = it-p.begin()+1;
		if(it == p.end()) p.pb(v[i]);
		else *it = v[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	
	cin >>m;
	vector<int> v;
	for(int i = 0; i < m; i++) {
		int a; cin >>a;
		v.pb(a);
	}

	calc1(v, 0);
	reverse(v.begin(), v.end());
	calc1(v, 1);
	
	int ans = 0;
	for(int i = 0; i < m; i++) 
		ans = max(ans, 2*min(lis[i][0], lis[i][1])-1);
	cout <<ans <<endl;
	
	return 0;
}

