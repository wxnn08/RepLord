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

	int n, h;
	cin >> n >> h;
	vector<ii> w;
	int x, y;
	for (int i = 0;i < n;i++) {
		cin >> x >> y;
		w.emplace_back(x, y);
	}
	vector<int> dist(n, 0);
	for (int i = 1;i < n;i++) {
		dist[i] = dist[i - 1] + w[i].first - w[i - 1].second;
	}
	int ans = 0;
	bool p = true;
	for (int i = 0;i < n and p;i++) {
		int st = w[i].first;
		auto it = lower_bound(dist.begin(), dist.end(), dist[i] + h);
		if (it == dist.end()) {
			p = false;
		}
		if (it == dist.end() || *it > dist[i] + h) it--;
		int j = it - dist.begin();
		int aux = w[j].second - st + dist[i] + h - *it;
		ans = max(ans, aux);
	}
	cout << ans << endl;

	return 0;
}

