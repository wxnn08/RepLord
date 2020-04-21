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

void impossible() {
	cout <<"===" <<endl;
	exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);

	int n; cin >>n;
	string s; cin >>s;

	if(n%4 != 0) impossible(); 
	char let[4] = {'A', 'C', 'G', 'T'};
	vector<int> qt(4, 0);

	for(auto c:s) {
		if(c == '?') continue;
		int pos = lower_bound(let, let+4, c) - let;
		qt[pos]++;
	}

	int id = 0;
	for(auto &at:s) {
		if(at != '?') continue;
		while(qt[id] >= n/4) id++;
		at = let[id];
		qt[id]++;
	}
	for(int i = 0; i < 4; i++)
		if(qt[i] < n/4) impossible();

	cout <<s <<endl;

	return 0;
}

