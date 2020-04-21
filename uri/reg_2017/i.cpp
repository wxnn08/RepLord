#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int n = s.length();
	s += s;
	int cnt = 0, d = 0;
	for (char c : s) {
		if (c == 'P') cnt++;
		else {
			d = max(d, cnt);
			cnt = 0;
		}
	}
	d = max(d, cnt);
	d++;
	int ans = 0;
	for (int i = d;i < n;i++) {
		if (__gcd(n, i) >= d) ans++;
	}
	cout << ans << endl;
	return 0;
}

