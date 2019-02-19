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

    int n, v;
	cin >>n >>v;
	
	int total = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(total < n-i) {
			int val = min(n-i, v-total);
			total += val;
			ans += val*i;
		}
		total--;
	}
	cout <<ans <<endl;
    
    return 0;
}

