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
    ios_base::sync_with_stdio(false);

    int n, a, b, c;
	scanf(" %d %d %d %d", &n, &a, &b, &c);
	
	int ans = 0;
	for(int i = 0; i <= 4000; i++) {
		for(int j = 0; j <= 4000; j++) {
			int qt = n-i*a-j*b;
			if(qt >= 0 and qt%c == 0) {
				if(i+j+(qt/c) > ans) ans = i+j+(qt/c);
				//ans = max(ans, i+j+(qt/c));
			}
		}
	}

	printf("%d\n", ans);
    
    return 0;
}

