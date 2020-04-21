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

int n, tc;
const int N = 32;
int arr[N];
int dp[1010][N][N];

int add(int tc, int pos, int qtd) {
	if(qtd == n) {
		return 1;
	}
	if(pos >= N) return 0;
	
	int &r = dp[tc][pos][qtd];
	if(r != -1) return r;

	arr[pos] = 0;
	int L = add(tc, pos+1, qtd);
	arr[pos] = 1;
	int R = add(tc, pos+1, qtd+1);
	arr[pos] = 0;
	
	return r = L + R;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	memset(dp, -1, sizeof dp);

	cin >>n;
    cout <<add(0, 0, 0) <<endl;
    
    return 0;
}

