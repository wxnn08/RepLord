/* Feito por wxn_ em 06/09/2020*/
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
 
vector<int> subDividers(int x, int y) {
	int sub = abs(x-y);
	vector<int> ans;
	for(int i = 1; i <= sub; i++) {
		if(sub%i == 0) ans.pb(i);
	}
	return ans;
}

int maxValue(int n, int x, int y, int step) {
	int l = min(x, y);
	int r = max(x, y);
	int qtd = 2, curr;

	curr = l;
	while(curr != r) {
		curr += step;
		qtd += (curr != r);
		if(qtd > n) return INF;
	}
	if(qtd == n) return r;

	curr = l;
	while(curr > 0) {
		curr -= step;
		qtd += (curr > 0);
		if(qtd == n) return r;
	}

	while(qtd < n) {
		r += step;
		qtd++;
	}
	return r;
}

int main() {
    ios_base::sync_with_stdio(false);

	int tc; cin >>tc;
	while(tc--) {
		int n, x, y; cin >>n >>x >>y;
		vector<int> divs = subDividers(x, y);
		int ans = INF;
		int step;
		for(auto div : divs) {
			int curr = maxValue(n, x, y, div);
			if(curr < ans) {
				ans = curr;
				step = div;
			}
		}
		while(n) {
			cout <<ans <<' ';
			ans -= step;
			n--;
		}
		cout <<endl;
	}

    return 0;
}
