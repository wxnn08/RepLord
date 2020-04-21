/* Aí, você já parou pra pensar, por que que você vive?
 * O que é que te move?
 * Aquele momento que decodifica o segredo da sua alma
 * E de repente tudo começa a fazer sentido.
 * É um chamado legítimo que vem lá do íntimo 
 * É quando a poesia entra em sincronia com o ritmo 
 * E te faz pensar 
 * Se não fosse isso eu podia até respirar, mas vivo eu também não ia tá!
 */
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
 
const int N = 1e3 + 5;
int n, m;
char g[N][N];

void init() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			g[i][j] = '.';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	init();

	cin >>n >>m;
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++) 
			cin >>g[i][j];

	cout <<contaCosta() <<endl;
	
	return 0;
}

