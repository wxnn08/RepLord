/* Feito por wxn_ em 05/09/2020*/
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
 
const int N = 70;
int mat[N][N];

int solve(int n) {
	int ans = 0;
	int curr = n-1;
	int t = 0;
	while(curr > 0) {
		int pre = (t ? mat[curr-1][curr] : mat[curr][curr-1]);
		if(pre != (mat[curr][curr]-1)) {
			t = 1-t;
			ans++;
		}
		curr--;
	}
	return ans;
}

int main() {
	int tc;
	scanf(" %d", &tc);
	while(tc--) {
		int n; cin >>n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
			    scanf(" %d", &mat[i][j]);
			}
		}
		printf("%d\n", solve(n));
	}

	return 0;
}

