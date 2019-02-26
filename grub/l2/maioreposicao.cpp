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
	
	int maior = -1, val, pos;
    for(int i = 0; i < 100; i++) {
		scanf(" %d", &val);
		if(val > maior) {
			maior = val;
			pos = i+1;
		}
	}

	printf("%d\n%d\n", maior, pos);
    
    return 0;
}

