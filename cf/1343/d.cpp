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

const int K = 2e5 + 5;
 
/* 
 * */

int main() {
    ios_base::sync_with_stdio(false);

	int tc; cin >>tc;

	while(tc--) {
		int n, k; cin >>n >>k;
		vector<int> in(n);
		vector<int> xs(2*k+5, 0);
		vector<int> changes(2*k+5, 0);

		for(int i = 0; i < n; i++) 
			cin >>in[i];
		
		for(int i = 0; i < n/2; i++) {
			int mini = min(in[i]+1, in[n-i-1]+1);
			int maxi = max(in[i]+k, in[n-i-1]+k);
			int curr = in[i]+in[n-i-1];
			xs[mini] += 1;
			xs[maxi+1] -= 1;
			changes[mini] += 1;
			changes[maxi+1] -= 1;
			changes[curr] -= 1;
			changes[curr+1] += 1;
		}

		for(int i = 1; i < xs.size(); i++) {
			xs[i] += xs[i-1];
			changes[i] += changes[i-1];
		}

		int ans = 0;
		for(int i = 0; i < xs.size(); i++) {
			if(((n/2)-xs[i])*2 + changes[i] < ((n/2)-xs[ans])*2 + changes[ans])
				ans = i;
		}
		cout <<((n/2)-xs[ans])*2 + changes[ans] <<endl;
	}

    return 0;
}

