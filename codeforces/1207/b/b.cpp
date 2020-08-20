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

const int N = 55;
int a[N][N];
int b[N][N];

void no() {
	cout <<-1 <<endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >>n >>m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >>a[i][j];
		}
	}

	vector<ii> ans;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == 1 and a[i][j+1] == 1 and a[i+1][j] == 1 and a[i+1][j+1] == 1) {
				ans.eb(i+1, j+1);
				b[i][j] = 1;
				b[i+1][j] = 1;
				b[i][j+1] = 1;
				b[i+1][j+1] = 1;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] != b[i][j]) no();
		}
	}

	cout <<ans.size() <<endl;
	for(ii at:ans)
		cout <<at.fi <<' ' <<at.se <<endl;

	return 0;
}

