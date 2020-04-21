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

int main() {
	ios_base::sync_with_stdio(false);

	string s;
	cin >>s;

	map<char, int> last, qtd;
	for(int i = 0; i < s.size(); i++) {
		last[s[i]] = i;
		qtd[s[i]]++;
	}

	string v = {'B', 'G', 'R'};
	do {
		int cont = qtd[v[0]] + qtd[v[2]];
		for(int i = last[v[0]]; i < s.size(); i++) {
			if(s[i] == v[1]) cont++;
		}
		for(int i = 0; i < s.size() and s[i] != v[2]; i++) {
			if(s[i] == v[1]) cont++;
		}
		if(cont == s.size()) {
			cout <<"YES" <<endl;
			return 0;
		}
	} while(next_permutation(v.begin(), v.end()));

	cout <<"NO" <<endl;
	return 0;
}

