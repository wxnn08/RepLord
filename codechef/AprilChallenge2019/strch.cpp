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

const int N = 1e6+5;

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
	cin >>tc;
	ll last[N];

	while(tc--) {
		int n;
		cin >>n;

		for(int i = 0; i < n; i++) last[i] = 0;

		string s;
		char c;
		cin >>s >>c;
		ll ls = -1;
		for(int i = s.size()-1; i >= 0; i--) {
			if(s[i] == c) ls = i;
			last[i] = ls;
		}
		
		ll ans = 0;
		for(int i = 0; i < n; i++) {
			if(last[i] < i) break;
			ans += (n-last[i]);
		}
		cout <<ans <<endl;
	}
    
    return 0;
}

