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
	
	int val[14] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};
	int qtd[14] = {0,4,4,4,4,4,4,4,4,4,4,4,3,4};
	int ans = 0;
	n -= 10;
	if(n == 0 || n > 11) ans = 0;
    else if(n == 11) ans = 4;
	else {
		fori(i,0,14) {
			if(val[i] == n) {
				ans += qtd[i];
			}
		}
	}

	cout <<ans <<endl;
    return 0;
}

