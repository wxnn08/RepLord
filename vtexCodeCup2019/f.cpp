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

struct box {
	int v[3];

	box(int a, int b, int c) {
		v[0] = a;
		v[1] = b;
		v[2] = c;
	}

	bool operator < (const box &t) const {
		return v[0] < t.v[0];
	}
};

vector<box> v;

int main() {
    ios_base::sync_with_stdio(false);

    int n; //2e5
	cin >>n;
    
	int d[3];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			cin >>d[j];
		}
		sort(d, d+3);
		v.pb(box(d[0],d[1],d[2]));
	}
	
	sort(v.begin(), v.end());

	for(int i = 0; i < 3; i++) {
		for(int j = 1; j < n; j++) {
			if(v[j].v[i] <= v[j-1].v[i]) {
				cout <<'N' <<endl;
				return 0;
			}
		}
	}

	cout <<'S' <<endl;
	return 0;

    return 0;
}

