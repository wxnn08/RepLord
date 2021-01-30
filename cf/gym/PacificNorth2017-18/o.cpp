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
 
const int N = 40;
int n;
char mat[N][N];

string solve() {
	for(int i = 0; i < n; i++) {
		unordered_set<char> s;
		s.clear();
		for(int j = 0; j < n; j++) {
			if(s.count(mat[i][j])) {
				return "No";
			}
			s.insert(mat[i][j]);
		}
	}

	for(int i = 0; i < n; i++) {
		unordered_set<char> s;
		s.clear();
		for(int j = 0; j < n; j++) {
			if(s.count(mat[j][i])) {
				return "No";
			}
			s.insert(mat[j][i]);
		}
	}

	for(int i = 1; i < n; i++) {
		if(mat[0][i] < mat[0][i-1]) {
			return "Not Reduced";
		}

		if(mat[i][0] < mat[i-1][0]) {
			return "Not Reduced";
		}
	}

	return "Reduced";
}

int main() {
	ios_base::sync_with_stdio(false);

	while(cin >>n) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >>mat[i][j];
			}
		}

		cout <<solve() <<endl;
	}

	return 0;
}

