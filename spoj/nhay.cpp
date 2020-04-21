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

const int N = 1e6 + 10;
string s, t; 

struct Hash {
	ll B, MOD;
	ll* memoHash;
	ll* memoB;
	ll bInv;

	Hash(ll B, ll MOD) : B(B), MOD(MOD) {
		memoHash = new ll[N];
		memoB = new ll[N];
		calcBInv();
		memoB[0] = 1LL;
		for(int i = 1; i < N; i++) 
			memoB[i] = (memoB[i-1] * bInv) % MOD;
	}

	ll fast_exp(ll base, ll e) {
		ll ans = 1LL;
		while(e > 0) {
			if(e&1LL) 
				ans = (ans * base) % MOD;
			base = (base*base) % MOD;
			e >>= 1LL;
		}
		return ans;
	}

	void calcBInv() {
		bInv = fast_exp(B, MOD-2);
	}

	void generatePreHash() {
		ll p = 1;
		ll ans = 0;
		for(int i = 0; i < t.size(); i++) {
			ans += (p * (ll)(t[i])) % MOD;
			ans %= MOD;
			memoHash[i+1] = ans;
			p = (p * B) % MOD;
		}
	}

	ll hashKey() {
		ll p = 1;
		ll ans = 0;
		for(int i = 0; i < s.size(); i++) {
			ans += (p * (ll)(s[i])) % MOD;
			ans %= MOD;
			p = (p * B) % MOD;
		}
		return ans;
	}

	ll intervalHash(int l, int r) {
		return (((memoHash[r+1] - memoHash[l] + MOD)%MOD) * memoB[l])%MOD;
	}
};

int main() {
	Hash h1 = Hash(359, 1e9 + 7);
	Hash h2 = Hash(359, 1e9 + 9);

	int n;
	h1.calcBInv();
	h2.calcBInv();

	while(cin >>n) {
		getchar();
		getline(cin, s);
		getline(cin, t);
		h1.generatePreHash();
		h2.generatePreHash();

		int goal1 = h1.hashKey();
		int goal2 = h2.hashKey();

		vector<int> ans;
		int i = 0, j = s.size()-1;
		while(j < t.size()) {
			ll v1 = h1.intervalHash(i, j);
			ll v2 = h2.intervalHash(i, j);
			if(v1 == goal1 and v2 == goal2) ans.pb(i);
			i++, j++;
		}
		if(ans.size()) for(auto curr:ans) cout <<curr <<endl;
		else cout <<endl;
	}

	return 0;
}

