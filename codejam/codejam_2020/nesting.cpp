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

string insert_parentheses(string &s) {
	string ans = "";
	int par = 0;
	for(auto curr:s) {
		int n = curr-'0';
		while(par < n) ans += '(', par++;
		while(par > n) ans += ')', par--;
		ans += curr;
	}
	while(par > 0) ans += ')', par--;
	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);

	int tcs; cin >>tcs;
	for(int tc = 1; tc <= tcs; tc++) {
		string s; cin >>s;
		cout <<"Case #" <<tc <<": ";
		cout <<insert_parentheses(s) <<endl;
	}

    return 0;
}

