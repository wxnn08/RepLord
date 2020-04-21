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

const int T = 1e5 + 5;
int ans[T];
vector<ii> v;
 
int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int x;

	for(int i = 0; i < n; i++) {
		cin >> x;
		v.eb(x,i);
	}

	sort(v.begin(), v.end());

	int k = n;

	for(int i = 0; i < n; i++) ans[v[i].se] = k--;

	for(int i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;

	return 0;
}

