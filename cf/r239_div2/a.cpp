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

	int n; cin >>n;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		int a; cin >>a;
		v.pb(a);
	}
	
	int ans = INF, at;
	for(int i = 0; i < v.size(); i++) {
		at = 0;
		for(int j = 0; j < v[i]; j++) {
			int k; cin >>k;
			at += (15+5*k);
		}
		ans = min(at, ans);
	}

	cout <<ans <<endl;

	return 0;
}
