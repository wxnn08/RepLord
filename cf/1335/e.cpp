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

const int N = 205;
const int M = 2e5 + 5;
int sum[N][M];

void init(const vector<int> &v) {

	for(int j = 0; j < N; j++) sum[j][0] = 0;

	for(int i = 0; i < v.size(); i++) 
		for(int j = 0; j < N; j++) 
			sum[j][i+1] = sum[j][i] + (v[i] == j? 1 : 0);
}
 
int maxElem(int l, int r) {
	int ans = 0;
	for(int i = 0; i < N; i++) {
		ans = max(ans, sum[i][r] - sum[i][l-1]);
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

	int tc; cin >>tc;
	while(tc--) {
		int n; cin >>n;
		vector<int> in;
		vector<vector<int>> v(N);
		for(int i = 1; i <= n; i++) {
			int a; cin >>a;
			in.pb(a);
			v[a].pb(i);
		}

		init(in);

		int ans = maxElem(1, n);
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < v[i].size()/2; j++) {
				int l = v[i][j]+1;
				int r = v[i][v[i].size()-1-j]-1;
				ans = max(ans, 2*(j+1) + maxElem(l, r));
			}
		}
		cout <<ans <<endl;
	}

    return 0;
}

