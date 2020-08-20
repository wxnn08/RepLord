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
	int P = 31;
	ll MOD;
	string s;
	vector<ll> prefix, p_pow;

	Hash(const string &s, ll MOD) : s(s), MOD(MOD) {
		prefix.resize(s.size()+1, 0);
		p_pow.resize(s.size()+1);
		calcPow();
		calcFixes();
	}

	void calcPow() {
		p_pow[0] = 1;
		for(int i = 1; i < p_pow.size(); i++) 
			p_pow[i] = (p_pow[i-1] * P) % MOD;
	}

	void calcFixes() {
		prefix[0] = 0;
		for(int i = 0; i < s.size(); i++) 
			prefix[i+1] = (prefix[i] + (s[i]-'a'+1) * p_pow[i]) % MOD;
	}

	bool isPrefixEqualSuffix(int lastPrefix, int firstSuffix) {
		return ((prefix[lastPrefix+1] * p_pow[firstSuffix])%MOD) == ((MOD+prefix[s.size()]-prefix[firstSuffix]) % MOD);
	}

	bool hasStringBetween(int sEnd, int left, int right) {
		ll hs = prefix[sEnd+1];
		int T = sEnd+1;
		for(int i = left; i <= right-T+1; i++) {
			if(((hs * p_pow[i])%MOD) == ((MOD+prefix[i+T]-prefix[i])%MOD)) 
				return true;
		}
		return false;
	}

};
 
int main() {
    ios_base::sync_with_stdio(false);
	const ll P = 31;
	const ll MOD = 1e9 + 7;

	string s; cin >>s;
	Hash h1(s, MOD);

	int S = s.size();
	int ans = -1;
	for(int i = S-1; i >= 0; i--) { // |s|
		if(h1.isPrefixEqualSuffix(i, S-i-1))  { // <------- 
			if(h1.hasStringBetween(i, 1, S-2)) { // |s|
				ans = i;
				break;
			}
		}
	}

	if(~ans) for(int i = 0; i <= ans; i++) cout <<s[i];
	else cout <<"Just a legend";
	cout <<endl;
	
    return 0;
}

