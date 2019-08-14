#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 12;
int m[N][N];

int searchH(int ii, int jj) {
	int ans = 0;
	while(jj > 0 and m[ii][jj-1] == 'X') jj--;
	while(jj < 10 and m[ii][jj] == 'X') ans++, jj++;
	return ans;
}
int searchV(int ii, int jj) {
	int ans = 0;
	while(ii > 0 and m[ii-1][jj] == 'X') ii--;
	while(ii < 10 and m[ii][jj] == 'X') ans++, ii++;
	return ans;
}

int searchD1(int ii, int jj) {
	int ans = 0;
	while(ii > 0 and jj > 0 and m[ii-1][jj-1] == 'X') ii--, jj--;
	while(ii < 10 and jj < 10 and m[ii][jj] == 'X') ans++, ii++, jj++;
	return ans;
}

int searchD2(int ii, int jj) {
	int ans = 0;
	while(ii > 0 and jj < 10 and m[ii-1][jj+1] == 'X') ii--, jj++;
	while(ii < 10 and jj >= 0 and m[ii][jj] == 'X') ans++, ii++, jj--;
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

	string s[10];
	for(int i = 0; i < 10; i++) {
		cin >>s[i];
	}

	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			m[i][j] = s[i][j];
		}
	}

	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(m[i][j] == '.') {
				m[i][j] = 'X';
				int t = max({searchH(i, j), searchV(i, j), searchD1(i, j), searchD2(i, j)});
				m[i][j] = '.';
				if(t >= 5) {
					cout <<"YES" <<endl;
					return 0;
				}
			}
		}
	}

	cout <<"NO" <<endl;

    return 0;
}

