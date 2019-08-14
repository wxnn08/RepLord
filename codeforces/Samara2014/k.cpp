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

const int N = 1e6;
int ans[N][2];

int main() {
	ios_base::sync_with_stdio(false);
	
	vector<int> va, vb, q, bag;
	int n, m;
	cin >>n;

	for(int i = 0; i < n; i++) {
		int x;
		cin >>x;
		va.pb(x);
		bag.pb(x);
	}
	for(int i = 0; i < n; i++) {
		int x;
		cin >>x;
		vb.pb(x);
		bag.pb(x);
	}
	cin >>m;
	for(int i = 0; i < 2*m; i++){
		int x;
		cin >>x;
		q.pb(x);
		bag.pb(x);
	}
	sort(bag.begin(), bag.end());
	bag.resize(unique(bag.begin(), bag.end()) - bag.begin());
	map<int, int> tf;
	int ini;
	for(int i = 0; i < bag.size(); i++) {
		tf[bag[i]] = i;
		ini = i;
	}
	
	memset(ans, INF, sizeof(ans));
	for(int i = 0; i < n; i++) ans[tf[va[i]]][0] = min(i, ans[tf[va[i]]][0]);
	for(int i = 0; i < n; i++) ans[tf[vb[i]]][1] = min(i, ans[tf[vb[i]]][1]);
	
	for(int i = ini-1; i >= 0; i--) {
		ans[i][0] = min(ans[i][0], ans[i+1][0]);
		ans[i][1] = min(ans[i][1], ans[i+1][1]);
	}
	
	for(int i = 0; i < m; i++) {
		int x = ans[tf[q[i]]+1][0];
		int y = ans[tf[q[m+i]]+1][1];
		if(x < y) cout <<"Mike" <<endl;
		if(x > y) cout <<"Constantine" <<endl;
		if(x == y) cout <<"Draw" <<endl;
	}

	return 0;
}

