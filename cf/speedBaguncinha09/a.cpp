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

const int N = 1e3 + 5;
vector<int> primes;
bool visit[N];
int pai[N];
int qtd[N];

int find(int x) {
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void join(int x, int y) {
	int a = find(x);
	int b = find(y);
	
	if(a == b) return;
	if(qtd[a] > qtd[b]) swap(a, b);
	pai[a] = b;
	qtd[b] += qtd[a];
}

void sieve(int n) {
	for(int i = 2; i <= n; i++) {
		if(visit[i]) continue;
		primes.pb(i);
		for(int j = i+i; j <= n; j += i) 
			visit[j] = true;
	}
}

int mmc(int a, int b) {
	return (a*b)/__gcd(a,b);
}

void init(int n) {
	for(int i = 0; i <= n; i++) {
		pai[i] = i;
		qtd[i] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	string s; cin >>s;

	init(s.size());
	sieve(s.size());

	for(int i = 0; i < primes.size(); i++) {
		for(int j = i+1; j < primes.size(); j++) {
			if(mmc(primes[i], primes[j]) <= s.size()) 
				join(primes[i], primes[j]);
		}
	}
	
	vector<int> groups;
	set<int> g[N];
	for(int i = 0; i < primes.size(); i++) {
		for(int j = 1; j*primes[i] <= s.size(); j++) 
			g[primes[i]].insert(j*primes[i]);

		groups.pb(find(primes[i]));
	}
	sort(groups.begin(), groups.end());
	groups.resize(unique(groups.begin(), groups.end()) - groups.begin());


	return 0;
}

