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

const int N = 105;
int arr[N];
 
int available(int t, int k, int d, int n) {
	
	int qt = k;
	for(int i = 1; i <= n; i++) 
		if(arr[i] <= t) qt--;
	if(qt > 0) return -1;

	int ans = 0;
	for(int i = 1; i <= n and k > 0; i++) {
		if(arr[i] <= t) {
			arr[i] = t+d;
			k--;
			ans += i;
		}
	}

	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

	int n, q; cin >>n >>q;
	while(q--) {
		int t, k, d;
		cin >>t >>k >>d;
		cout <<available(t, k, d, n) <<endl;
	}

    return 0;
}

