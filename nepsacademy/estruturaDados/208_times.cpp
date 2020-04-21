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
 
int main() {
    ios_base::sync_with_stdio(false);

	int n, t; cin >>n >>t;
	vector<pair<string, int>> v;
	while(n--) {
		string s; int h; 
		cin >>s >>h;
		v.eb(s,h);
	}
	sort(v.begin(), v.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
		return a.se > b.se;
	});

	vector<vector<string>> ans(t);
	for(int i = 0; i < v.size(); i++) {
		ans[i%t].pb(v[i].fi);
	}

	for(int i = 0; i < ans.size(); i++) {
		sort(ans[i].begin(), ans[i].end());
		cout <<"Time " <<i+1 <<endl;
		for_each(ans[i].begin(), ans[i].end(), 
			[](string &s) {cout <<s <<endl;}
		);
		cout <<endl;
	}

    return 0;
}

