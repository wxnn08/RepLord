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

struct Hash {
	int MOD;
	string s;
	vector<ll> prefix, suffix, p_pow;

	Hash(const string &s, int MOD) : MOD(MOD), s(s) {
		prefix.resize(s.size()+1, 0);
		suffix.resize(s.size()+1, 0);
		p_pow.resize(s.size()+1);
		calcFixes();
	}

	void calcPow() {
		p_pow[0] = 1;
		for(int i = 1; i < p_pow.size(); i++) 
			p_pow[i] = (p_pow[i-1] * P) % MOD;
	}

	void calcFixes() {
		for(int i = 0; i < s.size(); i++) 
			prefix[i+1] = (prefix[i] + (s[i]-'a'+1) * p_pow[i]) % MOD;
	}

};
 
int main() {
    ios_base::sync_with_stdio(false);
	const ll P = 31;
	const ll MOD = 1e9 + 7;

	string s; cin >>s;
	int S = s.size();
    return 0;
}

