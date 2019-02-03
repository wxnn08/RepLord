#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

    ll n, k, m;
	cin >>n >>k >>m;

	vector<ll> v;
	for(int i = 0; i < n; i++) {
		ll a; cin >>a;
		v.pb(a);
	}

	sort(v.begin(), v.end());
	
	int pos = 0;
	while(pos < v.size()-1 and m > 0 and v[pos] != v[v.size()-1]) {
		pos++;
		m--;
	}
	
	if(pos == v.size()) {
		cout <<fixed <<setprecision(8) <<v[v.size()-1]+min(m, k) <<endl;
	} else {
		ll sum = 0, qtd = 0;
		double ans = 0;
		for(int i = pos; i < v.size(); i++) {
			sum += v[i];
			qtd++;
		}
		if(m == 0) {
			ans = (double)sum/qtd;
		}
		else {
			sum += min(k*qtd, m);
			ans = (double)sum/qtd;
		}
		cout <<fixed <<setprecision(8) <<ans <<endl;
	}

    return 0;
}

