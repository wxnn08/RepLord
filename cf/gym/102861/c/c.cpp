#include <iostream>
#include <vector>
#include <map>
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
const ll MOD = 1e9 + 9;

class Hash {
private:
	ll MOD;
	const ll P = 31;
	vector<string> a, b;
	int n, m;

public:
	Hash(vector<string> a_in, vector<string> b_in, ll MOD_in) {
		MOD = MOD_in;
		a = a_in;
		b = b_in;
		n = a.size();
		m = b.size();
	}

	ll hashing(const string &s, int l, int r) {
		ll hash_value = 0;
		ll p_pow = 1;
		for (int i = l; i < r; i++) {
			char c = s[i];
			hash_value = (hash_value + (c - 'a' + 1) * p_pow) % MOD;
			p_pow = (p_pow * P) % MOD;
		}
		return hash_value;
	}

	void vecHash(map<ll,int> &hashes, const vector<string> &v, int n) {
		for(int i = 0; i < n; i++) {
			string s = v[i];
			hashes[hashing(s, 0, s.size())] = i;
		}
	}

	vector<bool> solve() {
		map<ll,int> hashA, hashB;
		vecHash(hashA, a, n);
		vecHash(hashB, b, m);

		map<ll,ii> sufix;

		for(int i = 0; i < n; i++) {
			string s = a[i];
			ll hash_value = 0;
			ll p_pow = 1;
			for (int j = 0; j < s.size()-1; j++) {
				char c = s[j];
				hash_value = (hash_value + (c - 'a' + 1) * p_pow) % MOD;
				p_pow = (p_pow * P) % MOD;
				if(hashA.count(hash_value)) {
					sufix[hashing(s, j+1, s.size())] = mk(i, hashA[hash_value]);
				}
			}
		}

		vector<bool> ans(n+m, true);
		for(int i = 0; i < m; i++) {
			string s = b[i];
			ll hash_value = 0;
			ll p_pow = 1;
			for (int j = 0; j < s.size()-1; j++) {
				char c = s[j];
				hash_value = (hash_value + (c - 'a' + 1) * p_pow) % MOD;
				p_pow = (p_pow * P) % MOD;
				if(sufix.count(hash_value)) {
					ll h = hashing(s, j+1, s.size());
					if(hashB.count(h)) {
						ans[sufix[hash_value].fi] = false;
						ans[sufix[hash_value].se] = false;
						ans[n+i] = false;
						ans[n+hashB[h]] = false;
					}
				}
			}
		}

		return ans;
	}
};


int main() {
	ios_base::sync_with_stdio(false);

	int n, m; cin >>n >>m;
	vector<string> a, b;
	for(int i = 0; i < n; i++) cin >>a[i];
	for(int i = 0; i < m; i++) cin >>b[i];

	Hash* h1 = new Hash(a, b, 1e9);
	Hash* h2 = new Hash(a, b, 1e7);

	auto ans1 = h1->solve();
	auto ans2 = h2->solve();

	return 0;
}
