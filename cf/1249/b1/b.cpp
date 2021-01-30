#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 2e5 + 5;
int v[N];
int ans[N];

int calc(int at, int cont) {
	if(ans[at] != -1) return ans[at] = cont;
	ans[at] = 1;
	return ans[at] = calc(v[at], cont+1);
}

int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >>tc;
	while(tc--) {
		int n; cin >>n;
		for(int i = 1; i <= n; i++) {
			cin >>v[i];
			ans[i] = -1;
		}

		for(int i = 1; i <= n; i++) 
			if(ans[i] == -1) calc(i, 0);

		for(int i = 1; i <= n; i++) 
			cout <<ans[i] <<' ';
		cout <<endl;

	}
	
	return 0;
}

