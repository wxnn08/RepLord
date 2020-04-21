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

	int n, m, k;
	cin >>n >>m >>k;
	
	vector<int> v;
	for(int i = 0; i < n; i++) {
		int t; cin >>t;
		v.pb(t);
	}
	vector<int> q;
	for(int i = 1; i < n; i++) {
		q.pb(v[i]-v[i-1]-1);
	}
	
	int ans = v[n-1]-v[0]+1;
	sort(q.begin(), q.end(), greater<int>());

	for(int i = 0; i < min((int)q.size(), k-1); i++) 
		ans -= q[i];

	cout <<ans <<endl;

	return 0;
}
