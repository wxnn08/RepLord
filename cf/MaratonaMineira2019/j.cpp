#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct Vertex {
	map<char, int> next;
	int leaf;
	Vertex() {
		next.clear();
		leaf = -1;
	}
};
vector<Vertex> trie(1);

void add_string(string &s, int id) {
	int v = 0;
	for(char ch:s) {
		if(!trie[v].next.count(ch)) {
			trie[v].next[ch] = trie.size();
			trie.eb();
		}
		v = trie[v].next[ch];
	}
	trie[v].leaf = id;
}

void search(string &s, int pos, vector<int> &vec) {
	int v = 0;
	int ans = -1;
	for(int i = pos; i < s.size(); i++) {
		char ch = s[i];
		if(trie[v].leaf > -1) vec.pb(trie[v].leaf);
		if(!trie[v].next.count(ch)) break;
		v = trie[v].next[ch];
	}
	if(trie[v].leaf > -1) vec.pb(trie[v].leaf);
}

string in;
vector<string> ori, trad;
vector<int> ans;

bool solve(int pos) {
	if(pos >= in.size()) return true;
	vector<int> v;
	search(in, pos, v);
	for(int i = v.size()-1; i >= 0; i--) {
		ans.pb(v[i]);
		bool hAns = solve(pos+ori[v[i]].size());
		if(hAns) return true;
		ans.pop_back();
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n; cin >>n;
	string s, t;
	getline(cin, s);
	for(int i = 0; i < n; i++) {
		getline(cin, s);
		getline(cin, t);
		ori.pb(s);
		trad.pb(t);
		add_string(s, i);
	}

	getline(cin, in);
	int i = 0;
	solve(0);
	for(auto at:ans) cout <<trad[at] <<' ';
	cout <<endl;
	return 0;
}
