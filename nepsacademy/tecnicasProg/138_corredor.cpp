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
 
int n;
const int N = 5e4+5;
int p[N];
int dp[N];

int solve(int pos){
	if(pos>n) return 0;
	int &r = dp[pos];
	if(r!=-1) return r;
	return r = max(p[pos]+solve(pos+1), p[pos]);
}	


int main(){
    ios_base::sync_with_stdio(false);

	cin >>n;
	fori(i,0,n) cin >>p[i];

	int res = 0;
	memset(dp, -1, sizeof(dp));
	for(int i=n-1; i>=0; i--) res = max(res, solve(i));
	cout <<res <<endl;

    
    return 0;
}

