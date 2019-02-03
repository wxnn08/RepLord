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

    int n, m;
	cin >>n >>m;
	
	vector<int> g, w;
	for(int i = 0; i < n; i++) {
		int a; cin >>a;
		g.pb(a);
	}

	for(int i = 0; i < m; i++) {
		int a; cin >>a;
		w.pb(a);
	}
    
	int j = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		if(j < m and g[i] <= w[j]) {
			j++;
			ans++;
		}
	}

	cout <<ans <<endl;
    return 0;
}

