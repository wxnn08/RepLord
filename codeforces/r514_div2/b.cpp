#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

    int n, m;
	cin >>n >>m;
	
	const int N = 1e3+5;
	char mat[N][N];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >>mat[i][j];
		}
	}
    
	int p[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
	for(int i = 1; i < n-1; i++) {
		for(int j = 1; j < m-1; j++) {
			bool col = true;
			for(int k = 0; k < 8; k++) {
				if(mat[i+p[k][0]][j+p[k][1]] == '.') col = false;
			}
			for(int k = 0;col and k < 8; k++) {
				if(mat[i+p[k][0]][j+p[k][1]] == '#') mat[i+p[k][0]][j+p[k][1]] = '-';
			}
		}
	}

	bool ans = true;
	for(int i = 0;ans and i < n; i++) {
		for(int j = 0;ans and j < m; j++) {
			if(mat[i][j] == '#') ans = false;
		}
	}

	cout <<(ans?"YES":"NO") <<endl;

    return 0;
}

