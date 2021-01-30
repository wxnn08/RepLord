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

	unordered_set<int> s;
	int n, k;
	cin >>n >>k;
	queue<int> q;

	for(int i = 0; i < n; i++) {
		int a; cin >>a;
		if(!s.count(a) and (int)q.size() == k) {
			s.erase(q.front());
			q.pop();
		}
		if(!s.count(a)) {
			q.push(a);
			s.insert(a);
		}
	}

	vector<int> ans;
	while(!q.empty()) {
		ans.pb(q.front());
		q.pop();
	}

	cout <<ans.size() <<endl;
	reverse(ans.begin(), ans.end());
	for(auto at:ans) cout <<at <<' ';
	cout <<endl;
	
	return 0;
}

