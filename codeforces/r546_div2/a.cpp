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
 
int main() {
    ios_base::sync_with_stdio(false);
	
	int n;
	cin >>n;
	
	vector<ii> v;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >>a >>b;
		v.eb(a,b);
	}

	int k; cin >>k;
	
	int at = 0;
	while(v[at].sec < k) at++;

	cout <<n-at <<endl;
    
    return 0;
}
