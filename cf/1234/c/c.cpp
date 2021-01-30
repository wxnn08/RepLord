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
 
int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >>tc;

	while(tc--) {
		int n;
		cin >>n;
		string s[2];
		cin >>s[0] >>s[1];

		bool ans = false;
		int lin = 0;
		int i;
		for(i = 0; i < n; i++) {
			if(s[lin][i] <= '2') continue;
			if(s[lin][i] > '2' and s[1-lin][i] > '2') lin = 1 - lin;
			else break;
		}
		if(i == n and lin == 1) ans = true;
		cout <<(ans?"YES":"NO") <<endl;
	}
	
	return 0;
}

