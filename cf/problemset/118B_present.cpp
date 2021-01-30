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

    int n;
	cin >>n;
	
	for(int i = 0; i <= 2*n; i++) {
		int k = min(i, (2*n)-i);
		int m = max(n-i, i-n);
		for(int j = 0; j < 2*m; j++) cout <<' ';
		for(int j = 0; j <= 2*k; j++) {
				cout <<min(j, (2*k)-j) <<(j < 2*k?' ':'\n');
		}
	}

    return 0;
}

