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

const int L = 30;
const int T = 2e5 + 5;
const int MOD = 1e9 + 7;

vector<int> pos[L];
int pula[T];
int freq[T][L];
ll ans[T]; 

vector<ll> acum;
vector<ll> last;

string quero;
string show;
int k,n;

ll solve(int at) {
	//implementar 
	if(at < 0) {
		ll x = (acum.size()? *acum.rbegin() : 0);
		return x % MOD;
	}

	if(at == quero.size()-1) {
		int qtd = freq[0][quero[at]-'A'];
		for(int i = 1; i <= qtd; i++) acum.pb(i);
		return solve(at-1);
	}

	for(int i = pos[quero[at]-'A'].size()-1; i >= 0; i--) {
		ll prox = freq[pos[quero[at]-'A'][i]+1+pula[quero[at]-'A']][quero[at+1]-'A'];	
		if(prox > 0) last.pb(acum[prox-1]);
		else last.pb(0);
		//cout << at << " " << prox << " " << *last.rbegin() <<  endl;
	}

	reverse(last.begin(), last.end());

	for(int i = 1; i < last.size(); i++) 
		last[i] = (last[i] + last[i-1]) % MOD;

	acum = last;
	last.clear();	
	solve(at-1);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> k >> n;
	
	for(int i = 0; i < n; i++) ans[i] = 1;

	for(int i = 0; i < 26; i++) cin >> pula[i];
	cin >> quero >> show;

	for(int i = show.size() - 1; i >= 0; i--) {	
		freq[i][show[i]-'A']++;
		pos[show[i]-'A'].pb(i);
	}
	
	for(int i = show.size() - 1; i >= 0; i--)	
		for(int j = 0; j < 26; j++)
			freq[i][j] += freq[i+1][j];

	cout << solve(quero.size()-1) << endl;

	return 0;
}

