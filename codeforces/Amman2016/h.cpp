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
		int n, q; cin >>n >>q;
		int cont = 0, ans = 0;
		string s;
		cin >>s;
		for(char at:s) {
			if(at == '0') {
				cont++;
			} else {
				cont = 0;
			}
			ans = max(cont, ans);
		}
		if(ans >= q+1) cout <<"yes" <<endl;
		else cout <<"no" <<endl;
	}

	return 0;
}
