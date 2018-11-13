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
 
const int N = 500 + 5;
char c[N][N];
bool invalido(int x, int y, char s) {
	if(s == '.') return false;
	s = (s == 'S'?'W':'S');
	if(x-1 >= 0 and c[x-1][y] == s) return true;
	if(y-1 >= 0 and c[x][y-1] == s) return true;
	return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
	cin >>n >>m;
	fori(i, 0, n) fori(j, 0, m) {
		cin >>c[i][j];
		if(invalido(i, j, c[i][j])) {
			cout <<"No" <<endl;
			return 0;
		}
	}
	cout <<"Yes" <<endl;
	fori(i, 0, n) {
		fori(j, 0, m) {
			if(c[i][j] == '.') cout <<'D';
			else cout <<c[i][j];
		}
		cout <<endl;
	}
    
    return 0;
}

