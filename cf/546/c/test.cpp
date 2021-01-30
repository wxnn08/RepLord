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

int fat(int n) {
	return (n == 0? 1 : n*fat(n-1));
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	int maxValue = fat(n+1);

	int m, a; 
	queue<int> s1, s2;

	cin >>m;
	for(int i = 0; i < m; i++) cin >>a, s1.push(a);
	cin >>m;
	for(int i = 0; i < m; i++) cin >>a, s2.push(a);
	
	int cont = 0;
	while(cont < maxValue and !s1.empty() and !s2.empty()) {
		if(s1.front() < s2.front()) {
			s2.push(s1.front());
			s2.push(s2.front());
		} else {
			s1.push(s2.front());
			s1.push(s1.front());
		}
		s1.pop();
		s2.pop();
		cont++;
	}

	if(s1.empty()) cout <<cont <<' ' <<2 <<endl;
	else if(s2.empty()) cout <<cont <<' ' <<1 <<endl;
	else cout <<-1 <<endl;
	return 0;
}

