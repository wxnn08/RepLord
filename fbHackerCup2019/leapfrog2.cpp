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

	int tcs;
	cin >>tcs;
	
	for(int tc = 1; tc <= tcs; tc++) {
		string s;
		cin >>s;
		int qtdB = 0;
		int qtdDot = 0;
		for(char at:s) {
			if(at == 'B') qtdB++;
			if(at == '.') qtdDot++;
		}
		
		int tam = (int) s.size();
		int qtMax = tam-2;
		int qtMin = (qtMax/2)+1;
		
		cout <<"Case #" <<tc <<": ";
		if(qtdB <= qtMax and qtdB >= qtMin) cout <<'Y' <<endl;
		else if(qtdDot > 0 and qtdB >= 2) cout <<'Y' <<endl;
		else cout <<'N' <<endl;
	}

	return 0;
}

