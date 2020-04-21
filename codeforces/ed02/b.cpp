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
	
	vector<int> a, b;
    int n, m;
	cin >>n >>m;
	
	fori(i, 0, n) {
		int t; cin >>t;
		a.pb(t);
	}
	fori(i, 0, m) {
		int t; cin >>t;
		b.pb(t);
	}
    
	sort(a.begin(), a.end());
	for(int i = 0 ; i < m; i++) {
		cout <<upper_bound(a.begin(), a.end(), b[i]) - a.begin() <<' ';
	}
	cout <<endl;

    return 0;
}

