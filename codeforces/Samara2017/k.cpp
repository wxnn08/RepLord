#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;
const int N = 2e5 + 5;

struct cs {
	int a, b, c, d;
	
	bool operator < (const cs &t) const {
		return (a != t.a? a < t.a : b < t.b);
	}
};

int prox[N];
int n;
vector<cs> v;
vector<int> q;
ii dp[N];

ii winx(ii a, ii b) {
	if(a.second != b.second)
		return (a.second > b.second? a:b);
	return (a.first < b.first? a:b);
}

ii solve(int at) {
	if(at >= n) return ii(0, 0LL);
	
	ii &r = dp[at];
	if(r != ii(-1, -1LL)) {
		return r;
	}

	ii L = solve(at+1);
	ii R = solve(prox[at]);
	R.first += (v[at].b-v[at].a);
	R.second += v[at].c;

	return r = winx(L, R);
}

void print(int at) {
	if(at >= n) return;
	
	if(dp[at] != dp[at+1]) {
		q.push_back(v[at].d);
		print(prox[at]);
		return;
	}
	print(at+1);

	return;
}

int main() {
	
	cin >>n;

	for(int i = 0; i < n; i++) {
		int a, b, c;
		cin >>a >>b >>c;
		v.push_back(cs({a, b, c, i+1}));
	}
	
	for(int i = 0; i < N; i++) dp[i] = ii(-1, -1LL);
	sort(v.begin(), v.end());

	for(int i = 0; i < n; i++) {
		prox[i] = lower_bound(v.begin(), v.end(), cs({v[i].b, 1, 1, 1})) - v.begin();
	}

	ii ans = solve(0);
	print(0);
	
	cout <<q.size() <<' ' <<ans.second <<' ' <<ans.first <<endl;
	for(int at:q) cout <<at <<' ';
	cout <<endl;

}
