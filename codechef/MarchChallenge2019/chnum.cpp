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
 
int main() {

    int tc;
	scanf(" %d", &tc);
	while(tc--) {
		int n, l = 0, r = 0;
		scanf(" %d", &n);
		for(int i = 0; i < n; i++) {
			int at;
			scanf(" %d", &at);
			if(at > 0) r++;
			else l++;
		}
		if(l == 0 or r == 0) {
			l = max(l, r);
			r = max(l, r);
		}
		printf("%d %d\n", max(l,r), min(l,r));
	}
    
    return 0;
}

