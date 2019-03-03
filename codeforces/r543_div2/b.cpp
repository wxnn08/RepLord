#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;

	for(int i = 0; i < n; i++) {
		int a; cin >>a;
		v.pb(a);
	}
	
	map<int, int> m;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			m[v[i]+v[j]]++;
			ans = max(ans, m[v[i]+v[j]]);
		}
	}
    
	cout <<ans <<endl;
    return 0;
}

