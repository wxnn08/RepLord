#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);

    int tc;
	cin >>tc;
	while(tc--) {
		int n;
		cin >>n;
		vector<int> v;
		int ans = 0;
		int sum = 0;
		for(int i = 0; i < n; i++) {
			int a; cin >>a;
			v.pb(a);
			ans ^= a;
			sum += a;
		}
		if(sum == n) {
			if(sum%2 == 0) cout <<"John" <<endl;
			else cout <<"Brother" <<endl;
			continue;	
		}
		if(ans) cout <<"John" <<endl;
		else cout <<"Brother" <<endl;
	}
    
    return 0;
}

