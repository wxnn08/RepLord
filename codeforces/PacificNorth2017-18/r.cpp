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

struct Swalk {
	double l, r, v;
	bool operator < (const Swalk &a) const {
		return l < a.l;
	}
};

int n;
double x, v;
vector<Swalk> sws; 

// Retorna custo em seg do segmento
double cost(double t) {
	return x/(cos(t) * v);
}

// Retorna absoluto da distância entre onde terminou e o ponto 0
double f(double t) {
	double y = x * tan(t);
	for(auto sw:sws) {
		double dx = sw.r - sw.l;
		double yf = sw.v * (dx/(cos(t) * v));
		y += yf;
	}
	return abs(y);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >>n >>x >>v;

	for(int i = 0; i < n; i++) {
		double l, r, v;
		cin >>l >>r >>v;
		sws.pb({l,r,v});
	}
	sort(sws.begin(), sws.end());

	double l = -PI/3;
	double r = PI/3;
	for(int i = 0; i < 10000; i++) {
		double mid = (l+r)/2;
		if(f(mid) > 0.0) r = mid;
		else l = mid;
	}
	
	if(abs(f(l)) > 1e-9) cout <<"Too hard" <<endl;
	else cout <<fixed <<setprecision(3) <<cost(l) <<endl;
	return 0;
}

