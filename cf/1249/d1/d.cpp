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

const int N = 2e5 + 5;

int main() {
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >>n >>k;
	
	vector<ii> v[N];
	int term[N];
	memset(term, 0, sizeof term);

	for(int i = 0; i < n; i++) {
		int a, b; cin >>a >>b;
		v[a].eb(b, i+1);
		term[b]++;
	}

	int qtd = 0;
	priority_queue<ii, vector<ii>> pq;
	vector<int> ans;
	for(int i = 0; i < N; i++) {
		for(auto seg:v[i]) {
			qtd++;
			pq.push(seg);
		}
		while(qtd > k) {
			ii at = pq.top();
			pq.pop();
			term[at.fi]--;
			qtd--;
			ans.pb(at.se);
		}
		qtd -= term[i];
	}
	
	cout <<ans.size() <<endl;
	sort(ans.begin(), ans.end());
	for(auto at:ans) cout <<at <<' ';
	cout <<endl;
	return 0;
}

