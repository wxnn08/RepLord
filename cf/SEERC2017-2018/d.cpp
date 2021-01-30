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
 
int gauss(vector<bitset<N>> a, int n, int m) {
	vector<int> where(m, -1);
	for (int col = 0, row = 0;col < m && row < n;col++) {
		for (int i = row;i < n;i++) {
			if (a[i][col]) {
				swap(a[i], a[row]);
				break;
			}
		}
		if (!a[row][col]) continue;
		where[col] = row;

		for (int i = 0;i < n;i++) {
			if (i != row && a[i][col]) {
				a[i] ^= a[row];
			}
		}
		++row;
	}
	int ans = 0;
	for (int i = 0;i < n;i++) {
		if (where[i] != -1) {
			ans++;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;
	int k, c;
	vector<bitset<N>> a;
	for (int i = 0;i < n;i++) {
		bitset<N> v;
		cin >> k;
	
	return 0;
}

