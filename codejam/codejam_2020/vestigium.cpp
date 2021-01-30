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
int mat[N][N];

void read_matrix(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >>mat[i][j];
		}
	}
}

int trace(int n) {
	int ans = 0;
	for(int i = 0; i < n; i++) ans += mat[i][i];
	return ans;
}

int repeated_rows(int n) {
	int repeat[N];
	int ans = 0;
	for(int i = 0; i < n; i++) {
		memset(repeat, 0, sizeof repeat);
		for(int j = 0; j < n; j++) {
			if(repeat[mat[i][j]]) {
				ans++;
				break;
			}
			repeat[mat[i][j]]++;
		}
	}
	return ans;
}

int repeated_columns(int n) {
	int repeat[N];
	int ans = 0;
	for(int i = 0; i < n; i++) {
		memset(repeat, 0, sizeof repeat);
		for(int j = 0; j < n; j++) {
			if(repeat[mat[j][i]]) {
				ans++;
				break;
			}
			repeat[mat[j][i]]++;
		}
	}
	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);

	int tcs; cin >>tcs;
	for(int tc = 1; tc <= tcs; tc++) {
		int n; cin >>n;
		read_matrix(n);
		cout <<"Case #" <<tc <<": ";
		cout <<trace(n) <<' ';
		cout <<repeated_rows(n) <<' ';
		cout <<repeated_columns(n) <<endl;
	}

    return 0;
}

