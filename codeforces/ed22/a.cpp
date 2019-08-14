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

	int n; cin >>n;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		int val; cin >>val;
		sum += val;
	}
	
	vector<ii> t;

	int m; cin >>m;
	int a, b;
	for(int i = 0; i < m; i++) {
		cin >>a >>b;
		t.eb(a, 0);
		t.eb(b, 1);
	}
	
	if(m == 0 or sum > t[t.size()-1].fi) {
		cout <<-1 <<endl;
		return 0;
	}
	
	int ans = -1;
	auto at = lower_bound(t.begin(), t.end(), ii(sum, 0));
	if((*at).fi == sum) ans = sum;
	else if((*at).se == 1) ans = sum;
	else ans = (*at).fi;
	
	cout <<ans <<endl;
    return 0;
}

