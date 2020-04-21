#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int k, l, m;
const int N = 1e6+10;
bool solve(int n) {
	bool p[N];
	p[0] = 0;
	for(int i = 1; i <= n; i++) {
		p[i] = !p[i-1];
		if(i >= k) p[i] |= !p[i-k];
		if(i >= l) p[i] |= !p[i-l];
	}
	return p[n];
}

int main() {
    ios_base::sync_with_stdio(false);

	cin >>k >>l >>m;
	
	while(m--) {
		int t; cin >>t;
		if(solve(t)) cout <<'A';
		else cout <<'B';
	}
	cout <<endl;
    
    return 0;
}

