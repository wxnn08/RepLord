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

    int n, ans = 0;
	scanf(" %d", &n);
	
	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = 0; j < 3; j++) {
			int at;
			scanf(" %d", &at);
			sum += at;
		}
		if(sum > 1) ans++;
	}

	printf("%d\n", ans);
    
    return 0;
}

