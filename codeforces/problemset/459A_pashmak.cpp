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

    int x1, x2, y1, y2;
	cin >>x1 >>y1 >>x2 >>y2;
	
    if(abs(x1-x2) != 0 and abs(y1-y2) != 0 and abs(x1-x2) != abs(y1-y2)) {
		cout <<-1 <<endl;
		return 0;
	}

	int l = max(abs(x1-x2), abs(y1-y2));
	int ans[2][2];
	
	int lim = 1e3;
	if(abs(x1-x2) == 0) {
		if(x1+l <= lim) {
			ans[0][0] = x1+l;
			ans[1][0] = x2+l;
		} else {
			ans[0][0] = x1-l;
			ans[1][0] = x2-l;
		}
		ans[0][1] = y1;
		ans[1][1] = y2;

	} else if(abs(y1-y2) == 0) {
		if(y1+l <= lim) {
			ans[0][1] = y1+l;
			ans[1][1] = y2+l;
		} else {
			ans[0][1] = y2-l;
			ans[1][1] = y2-l;
		}
		ans[0][0] = x1;
		ans[1][0] = x2;
	} else {
		if(x1+l == x2) {
			ans[0][0] = x1+l;
		} else {
			ans[0][0] = x1-l;
		}
		if(y1+l == y2) {
			ans[1][1] = y1+l;
		} else {
			ans[1][1] = y1-l;
		}
		ans[0][1] = y1;
		ans[1][0] = x1;
	}
	
	for(int i = 0; i < 2; i++) {
		cout <<ans[i][0] <<' ' <<ans[i][1] <<' ';
	}
	cout <<endl;
    return 0;
}

