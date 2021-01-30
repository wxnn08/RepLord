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
	int id, cap, at;
};
vector<node> cs;

int main() {
	ios_base::sync_with_stdio(false);

	int n, w;
	cin >>n >>w;
	
	int sum = 0;
	for(int i = 0; i < n; i++) {
		int c; cin >>c;
		int half = (c/2)+(c%2);
		cs.pb({i, c, half});
		sum += half;
	}

	if(sum > w) {
		cout <<-1 <<endl;
		return 0;
	}

	sort(cs.begin(), cs.end(), 
		[](const node &a, const node &b) {
			return a.cap > b.cap;
		});
	
	w -= sum;
	for(auto &c:cs) {
		int v = min(c.cap-c.at, w);
		w -= v;
		c.at += v;
	}

	if(w > 0) {
		cout <<-1 <<endl;
		return 0;
	}

	sort(cs.begin(), cs.end(), 
		[](const node &a, const node &b) {
			return a.id < b.id;
		});

	for(auto c:cs) 
		cout <<c.at <<' ';
	cout <<endl;
	return 0;
}

