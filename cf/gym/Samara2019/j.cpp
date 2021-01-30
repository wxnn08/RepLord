#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef tuple<ll, ll, ll> tiii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<ll> sum;
int search(int ini, int fim, ll v) {
	int ans = -1;
	while(ini <= fim) {
		int mid = (ini+fim)>>1;
		if(sum[mid] <= v) ans = mid, ini = mid+1;
		else fim = mid-1;
	}
	return ans+1;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int n; cin >>n;
	vector<tiii> jedi;
	for(int i = 0; i < n; i++) {
		ll a, b, c;
		cin >>a >>b >>c;
		jedi.eb(min({a, b, c}), (a+b+c)-min({a, b, c})-max({a, b, c}), max({a, b, c}));
		sum.pb(get<0>(jedi.back())+get<1>(jedi.back())+2);
	}

	sort(sum.begin(), sum.end());

	for(int i = 0; i < n; i++) {
		ll a, b, c;
		tie(a, b, c) = jedi[i];
		ll pos = search(0, sum.size()-1, a+b+c);
		cout <<pos-(c>=2) <<' ';
	}
	cout <<endl;

	return 0;
}

