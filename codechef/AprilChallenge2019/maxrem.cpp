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

    int n;
	cin >>n;
	
	vector<int> v;
	for(int i = 0; i < n; i++) {
		int a; cin >>a;
		v.pb(a);
	}

	sort(v.begin(), v.end(), greater<int>());
    
	int t = v[0];
	for(int at:v) {
		if(at != t) {
			cout <<(at>1?at:0) <<endl;
			return 0;
		}
	}
	
	cout <<0 <<endl;
    return 0;
}

