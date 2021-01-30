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

	int w1, w2;
	cin >>w1 >>w2;
	
	if(w1 == w2) {
		cout <<0 <<endl;
		return 0;
	}
	int div = __gcd(w1, w2);
	int r1 = w1/div, r2 = w2/div;
	int qtd1 = 0, qtd2 = 0;
	
	while(r1%5 == 0) qtd1++, r1 /= 5;
	while(r1%3 == 0) qtd1++, r1 /= 3;
	while(r1%2 == 0) qtd1++, r1 /= 2;
	if(r1 != 1) {
		cout <<-1 <<endl;
		return 0;
	}
	
	while(r2%5 == 0) qtd2++, r2 /= 5;
	while(r2%3 == 0) qtd2++, r2 /= 3;
	while(r2%2 == 0) qtd2++, r2 /= 2;
	if(r2 != 1) {
		cout <<-1 <<endl;
		return 0;
	}
	
	cout <<qtd1+qtd2 <<endl;
	
	return 0;
}

