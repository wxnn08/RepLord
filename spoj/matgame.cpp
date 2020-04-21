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

const int N = 55;
int g[N][N];
int n, m;

int SG(int t) {
	int ant = -1;
	for(int i = 0; i < m; i++) {
		if(g[t][m-i-1] > ant) ant = g[t][m-i-1];
		else ant = g[t][m-i-1]-1;
	}
	return ant;
}

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
	cin >>tc;

	while(tc--) {
		cin >>n >>m;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >>g[i][j];
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			ans ^= SG(i);
		}
		cout <<(ans?"FIRST":"SECOND") <<endl;
	}
    
    return 0;
}

