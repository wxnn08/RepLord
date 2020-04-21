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
 
const int N = 2e5 + 5;
int ac[N];
int qtd[N];

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >>n >>m;
	vector<int> v;

	for(int i = 0; i < m; i++) {
		int a; cin >>a;
		v.pb(a);
		ac[a]++;
		qtd[a]++;
	}

	for(int i = 1; i < N; i++) 
		ac[i] += ac[i-1];

	int vb = 0;
	for(int j = 0; j < m-1; j++) {
		int pos1, pos2;
		if(v[j] == 1) pos1 = 1;
		else pos1 = (v[j] < 1? v[j]+1 : v[j]);
		if(v[j+1] == 1) pos2 = 1;
		else pos2 = (v[j+1] < 1? v[j+1]+1 : v[j+1]);
		vb += abs(pos1-pos2);
	}
	
	cout <<vb <<' ';
	for(int i = 2; i <= n; i++) {
		cout <<vb-(qtd[i]*(i-1))+ac[i-1] <<' ';
	}
	cout <<endl;
	
	return 0;
}

