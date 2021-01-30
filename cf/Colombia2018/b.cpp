#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 5123;
bitset<T> ok;
bitset<T> nok;
vector<bool> v;
string s,t;
int n;

int test() {
	int ans = 0;
	vector<bool> z = v;

	for(int i = 0; i < n; i++) {
		if(z[i] != ok[i]) {
			if(i == n-1) ans = INF;
			else z[i+1] = !z[i+1];
			ans++;
		}
	}

	z = v;
	int ans2 = 0;

	for(int i = n-1; i >= 0; i--) {
		if(z[i] != ok[i]) {
			if(i == 0) ans2 = INF;
			else z[i-1] = !z[i-1];
			ans2++;
		}
	}

	return min(ans,ans2);
}

int sextou() {
	int ans = 0;
	vector<bool> z = v;

	for(int i = 0; i < n; i++) {
		if(z[i] != nok[i]) {
			if(i == n-1) ans = INF;
			else z[i+1] = !z[i+1];
			ans++;
		}
	}

	//z = v;
	//int ans2 = 0;

	//for(int i = n-1; i >= 0; i--) {
	//	if(z[i] != nok[i]) {
	//		if(i == 0) ans2 = INF;
	//		else z[i-1] = !z[i-1];
	//		ans2++;
	//	}
	//}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s >> t;

	for(int i = 0; i < s.size(); i++) {
		v.pb(s[i] == '1');
		ok[i] = (t[i] == '1');
		nok[i+1] = ok[i];
	}

	nok[0] = nok[s.size()];

	n = s.size();
	if(n == 1) {
		cout << (s == t? 0 : -1) << endl;
		return 0;
	}

	int ans = INF;

	for(int i = 0; i < n; i++) {
		ans = min(ans,test());	
		ans = min(ans,sextou());	
		bool x = v.back();
		v.pop_back();
		v.insert(v.begin(),x);
	}

	cout << (ans == INF? -1 : ans) << endl;
	
	return 0;
}

