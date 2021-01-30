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

const int N = 1e5 + 5;
const int M = 30;

ll l[N][M];
ll c[M][M];
ll ocur[M];
 
int main() {
    ios_base::sync_with_stdio(false);

	string s; cin >>s;
	for(int i = s.size()-2; i >= 0; i--) {
		for(int j = 0; j < M; j++) l[i][j] = l[i+1][j];
		l[i][s[i+1]-'a']++;
	}

	ll ans = 0;
	for(int i = 0; i < s.size(); i++) {
		ocur[s[i]-'a']++;
		ans = max(ans, ocur[s[i]-'a']);
		for(int j = 0; j < M; j++) {
			c[s[i]-'a'][j] += l[i][j];
		}
	}

	for(int i = 0; i < M; i++) {
		for(int j = 0; j < M; j++) {
			ans = max(ans, c[i][j]);
		}
	}
	cout <<ans <<endl;

    return 0;
}

