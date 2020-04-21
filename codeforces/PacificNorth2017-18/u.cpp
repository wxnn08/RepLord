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

	double p[10];
	double sum = 0;
	for(int i = 1; i <= 6; i++) {
		cin >>p[i];
		sum += (i*p[i]);
	}
	
	double ans = 0;
	for(int i = 1; i <= 6; i++) {
		double aux = sum - (i*p[i]);
		double aux2 = (3.5 - aux)/p[i];
		if(i == 1 or ans > abs(aux2 - i))
			ans = abs(aux2-i);
	}
	cout <<fixed <<setprecision(3) <<ans <<endl;
	
	return 0;
}

