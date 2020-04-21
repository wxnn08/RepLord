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

int N = 22;

int comp(int x) {
	int ans = 0;
	for(int i = 0; i < N; i++) 
		if((x & (1<<i)) == 0) ans |= (1<<i);
	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);

	int n; cin >>n;
	vector<int> in(n);
	vector<int> ans(n, -1);
	vector<int> v((1<<N), -1);

	for(int i = 0; i < n; i++) {
		cin >>in[i];
		v[in[i]] = in[i];
	}

	for(int i = 0; i < N; i++) 
		for(int mask = 0; mask < (1<<N); mask++){
			if(mask & (1<<i))
				v[mask] = max(v[mask], v[mask^(1<<i)]);
		}

	for(int i = 0; i < n; i++) {
		cout <<v[comp(in[i])] <<' ';
	}
	cout <<endl;

	return 0;
}

