#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
typedef pair<int,int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int TAM = 1e3+5;

int n;
int s[TAM];
int dp[TAM][TAM];

int solve(int ant, int at){
	if(at>=n or ant>=n) return 0;

	int &r = dp[ant][at];
	if(r != -1) return r;
	
	int L = 0;
	if(s[at]>=s[ant]) L = 1+solve(at, at+1);
	int R = solve(ant, at+1);
	
	return r = max(L,R);
}

int main(){
    ios_base::sync_with_stdio(false);

	cin >>n;
	fori(i,0,n) cin >>s[i];
	
	memset(dp, -1,sizeof dp);
	int res = 0;
	for(int i=0; i<n; i++)
		res = max(res,solve(i, i));
    cout <<res <<endl;
    return 0;
}

