/* Feito por wxn_ em 05/09/2020*/
#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

ii solve(const vector<int> &v, const int n) {
	vector<double> time[n];
	for (int i = 0; i < n; i++) {
		inf[i].insert(i);
		for (int j = 0; j < n; j++) {
			if(v[i] == v[j]) {
				time[i].pb(-1);
				continue;
			}
			double t = (double)(-i+j)/(v[i]-v[j]);
			time[i].pb(t);
		}
	}

	ii ans(6, -1);
	for (int i = 0; i < n; i++) {
		set<int> ans;
		for (int j = 0; j < n; j++) {
			for(int k = 0; time[i][j] > 0.0 and k < time[j].size(); k++) {
				if(k == j) continue;
				if(time[j][k] > time[i][j]) {
					ans.insert(k);
				}
			}
		}
		ans.fi = min(ans.fi, (int)inf[i].size());
		ans.se = max(ans.se, (int)inf[i].size());
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	int tc; cin >>tc;
	while(tc--) {
		int n; cin >>n;
		vector<int> v(n);
		for(int i = 0; i < n; i++) 
			cin >>v[i];
		ii ans = solve(v, n);
		cout <<ans.fi <<' ' <<ans.se <<endl;
	}

	return 0;
}
