#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int n;
const int N = 1e6 + 5;
ii v[N];

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

bool cmp(ii a, ii b) {
	return a > b;
}

int preenche(int at, int sum, int cont) {
	if(at > n) return cont;
	int val = preenche(at+sum, sum, cont+1);
	v[at].fi += val;
	return val;
}

int main() {
    ios_base::sync_with_stdio(false);

	cin >>n;
	for(int i = 1; i <= n; i++) {
		v[i] = mk(0, i);
	}

	for(int i = 1; i <= n; i++) {
		preenche(i, i, 0);
	}

	sort(v+1, v+n+1, cmp);

	vector<int> ans;
	int mdc = v[1].sec;
	ans.pb(v[1].sec);
	for(int i = 2; i <= n ; i++) {
		mdc = gcd(mdc, v[i].sec);
		ans.pb(mdc);
	}
	
	for(int i = ans.size()-1; i >= 0; i--) cout <<ans[i] <<' ';
	cout <<endl;

    return 0;
}

