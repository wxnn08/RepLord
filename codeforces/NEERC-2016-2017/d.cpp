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

const ll MOD = 1e9+7;

int main() {
	ios_base::sync_with_stdio(false);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	string s;
	cin >>s;
	set<string> amb;
	amb.insert("NE");
	amb.insert("NW");
	amb.insert("SE");
	amb.insert("SW");
	
	ll e = 0;
	for(int i = 0; i < (int) s.size()-1; i++) {
		string at = "";
		at += s[i];
		at += s[i+1];
		if(amb.count(at)) e++;
	}

	ll ans = 1;
	while(e > 0) {
		ans *= 2;
		ans %= MOD;
		e--;
	}

	cout <<ans <<endl;
	return 0;
}

