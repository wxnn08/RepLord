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


int n, m, k;
set<ii> s;
int mov[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int fences(int a, int b) {
	int ans = 4;
	for(int i = 0; i < 4; i++) {
		if(s.count(ii(a+mov[i][0], b+mov[i][1])))
			ans-=2;
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
	cin >>tc;

	while(tc--) {
		cin >>n >>m >>k;
		s.clear();
		int ans = 0;
		for(int i = 0; i < k; i++) {
			int a, b; cin >>a >>b;
			ans += fences(a-1, b-1);
			s.insert(ii(a-1,b-1));
		}
		cout <<ans <<endl;
	}
    return 0;
}

