/*29/08/2020*/
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
 
const int N = 1e3 + 5;
vector<int> g[N];
void readInput(int n, vector<string> &ss) {
	string s;
	for(int i = 0; i < n; i++) {
		cin >>s;
		ss.pb(s);
	}
}
void createGraph(int n, const vector<string> &ss) {
	for(int i = 0; i < ss.size(); i++) {
		string s = ss[i];
		for(int j = 0; j < s.size(); j++) {
			if(s[j] == '1') g[i].pb(j);
		}
	}
}

vector<int> bfs(int ini, int n) {
	vector<int> ans;
	vector<bool> visited(n, 0);
	queue<int> q;

	q.push(ini);
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		if(visited[curr]) continue;
		visited[curr] = true;
		ans.pb(curr);
		for(int viz : g[curr]) {
			if(!visited[viz]) q.push(viz);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n; cin >>n;
	vector<string> ss;
	readInput(n, ss);
	createGraph(n, ss);
	vector<int> ans = bfs(0, n);
	if(ans.size() == n) {
		for(int i = 0; i < ans.size(); i++) 
			cout <<ans[ans.size()-i-1] <<' ';
		cout <<endl;
	} else {
		cout <<"impossible" <<endl;
	}

	return 0;
}
