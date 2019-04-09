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

struct node {
	int id;
	double x, y, v;
};

double ax, ay, bx, by, rx, ry;

bool cmp1(node a, node b) {
	return a.v-hypot(a.x-ax,a.y-ay) > b.v-hypot(b.x-ax,b.y-ay);
}
bool cmp2(node a, node b) {
	return a.v-hypot(a.x-bx,a.y-by) > b.v-hypot(b.x-bx,b.y-by);
}

int main() {
    ios_base::sync_with_stdio(false);
	
	cin >>ax >>ay >>bx >>by >>rx >>ry;
	
	vector<node> v;
	int n;
	cin >>n;
	double sum = 0;
	for(int i = 0; i < n; i++) {
		double x, y;
		cin >>x >>y;
		v.pb(node({i, x, y, hypot(x-rx, y-ry)}));
		sum += (2*v[i].v);
	}

	

	vector<node> v_a = v, v_b = v;
	sort(v_a.begin(), v_a.end(), cmp1);
	sort(v_b.begin(), v_b.end(), cmp2);
	
	double ans = sum + hypot(ax-rx, ay-ry);
	ans = min(ans, sum-v_a[0].v+hypot(v_a[0].x-ax, v_a[0].y-ay));
	ans = min(ans, sum-v_b[0].v+hypot(v_b[0].x-bx, v_b[0].y-by));
	if(n > 1) {
		for(int i = 0; i < min(100, n); i++) {
			for(int j = 0; j < min(100, n); j++) {
				if(v_a[i].id == v_b[j].id) continue;
				double sub = sum;
				sub -= v_a[i].v;
				sub += hypot(v_a[i].x-ax, v_a[i].y-ay);
				sub -= v_b[j].v;
				sub += hypot(v_b[j].x-bx, v_b[j].y-by);
				ans = min(ans, sub);
			}
		}
	}
	
	cout <<fixed <<setprecision(10) <<ans <<endl;
    
    return 0;
}

