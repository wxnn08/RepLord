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
 
struct node {
	int v, op, id;

	bool operator < (const node &t) const {
		if(v != t.v) return v < t.v;
		return op < t.op;
	}
};

vector<node> v;

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	
	vector<node> v;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >>a >>b;
		v.pb(node({a, 0, i}));
		v.pb(node({b, 1, i}));
	}

	sort(v.begin(), v.end());
	
	vector<int> ans;
	set<int> s;
	stack<int> st;
	for(int i = 0; i < v.size(); i++) {
		if(v[i].op == 0) st.push(v[i].id);
		if(v[i].op == 1 and !s.count(v[i].id)) {
			ans.pb(v[i].v);
			while(!st.empty()) {
				s.insert(st.top());
				st.pop();
			}
		}
	}
    
	cout <<ans.size() <<endl;
	for(int at:ans) cout <<at <<' ';
	cout <<endl;
	return 0;
}

