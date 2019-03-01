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

const int N = 30;
int sg[N][N];
int mex[N];
void pattern(int n) {
	sg[0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			memset(mex, 0, sizeof(mex));
			for(int k = j-1; k >= 0; k--) mex[sg[i][k]] = 1;
			for(int k = i-1; k >= 0; k--) mex[sg[k][j]] = 1;
			if(j < i) for(int k = 1; k <= j; k++) mex[sg[i-k][j-k]] = 1;
			else for(int k = 1; k <= i; k++) mex[sg[i-k][j-k]] = 1;
			int at = 0;
			while(mex[at] != 0) at++;
			sg[i][j] = at;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%3d ", sg[i][j]);
		}
		printf("\n");
	}
}

int main() {

    pattern(10);
    
    return 0;
}

