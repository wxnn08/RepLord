/* Feito por wxn_ em 06/09/2020*/
#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int sumDig(const string &s) {
	int ans = 0;
	for(auto c : s) ans += (int)(c-'0');
	return ans;
}

int findIdLess(const string &s, int n) {
	int id = -1;
	int ans = 0;
	for(int i = 0; i < s.size(); i++) {
		ans += (int)(s[i]-'0');
		if(ans < n) id = i;
	}
	return id;
}

ll nextOk(int id, const string &s) {
	if(id == -1) {
		ll ans = 1;
		for(int i = 0; i < s.size(); i++) 
			ans *= 10;
		return ans;
	}

	ll ans = 0;
	for(int i = 0; i <= id; i++) {
		ans *= 10;
		ans += (int)(s[i]-'0');
	}
	ans += 1;
	while(id < s.size()-1) {
		ans *= 10;
		id++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	int tc; cin >>tc;
	while(tc--) {
		string s; cin >>s;
		int n; cin >>n;

		if(sumDig(s) <= n) {
			cout <<0 <<endl;
			continue;
		}
		
		int id = findIdLess(s, n);
		ll obj = nextOk(id, s);
		cout <<obj-stoll(s) <<endl;
	}
    return 0;
}
