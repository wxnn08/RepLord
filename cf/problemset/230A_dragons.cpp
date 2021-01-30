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
 
int main(){
    ios_base::sync_with_stdio(false);

    int s, n;
	cin >>s >>n;
	
	vector<ii> v;
	fori(i, 0, n) {
		int x, y;
		cin >>x >>y;
		v.pb(ii(x,y));
	}
    sort(v.begin(), v.end());
	
	bool ans = false;
	for(int i = 0; i < n; i++) {
		if(v[i].fi < s) s += v[i].sec;
		else {
			cout <<"NO" <<endl;
			return 0;
		}
	}
	
	cout <<"YES" <<endl;
    return 0;
}

