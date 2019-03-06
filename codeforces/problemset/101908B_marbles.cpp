#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 110;
int sg[N][N];
int mex[4*N];
void pattern(int n) {
	memset(sg, -1, sizeof(sg));
	sg[1][2] = 0;
	sg[2][1] = 0;

	for(int i = 1; i < n; i++) {
		for(int j = 1; j < n; j++) {
			if(i == j) continue;
			memset(mex, 0, sizeof(mex));
			for(int k = j-1; k >= 0; k--) 
				if(sg[i][k] > -1) 
					mex[sg[i][k]] = 1;
			for(int k = i-1; k >= 0; k--) 
				if(sg[k][j] > -1) 
					mex[sg[k][j]] = 1;
			for(int k = 1; k <= min(i, j); k++) 
				if(sg[i-k][j-k] > -1) 
					mex[sg[i-k][j-k]] = 1;

			int at = 0;
			while(mex[at] != 0) at++;
			sg[i][j] = at;
		}
	}
/*
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 6; j++) {
			printf("%3d ", sg[i][j]);
		}
		printf("\n");
	}
*/

}

int main() {

    pattern(N);
    
	int n; cin >>n;
	int ans = 0;
	while(n--) {
		int x, y;
		cin >>x >>y;
		if(sg[x][y] == -1) {
			ans = 1;
			break;
		}
		ans ^= sg[x][y];
	}

	if(ans) cout <<'Y' <<endl;
	else cout <<'N' <<endl;

    return 0;
}

