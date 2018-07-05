#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int n;
const int N= 4e3+5;
int dp[N][4], v[4];

int lul(int len, int pos){
	if(len==0) return 0;
	if(len<0) return -INF;
	if(pos>=3) return -INF;
	
	int &r = dp[len][pos];
	if(r!=INF) return r;
	//return r = max(lul(len-v[pos], pos)+1, max(lul(len-v[pos], pos+1)+1, lul(len, pos+1)));
	return r = max(lul(len-v[pos], pos)+1, lul(len, pos+1));
	
}

int main(){
    ios_base::sync_with_stdio(false);
	
	cin >>n;
	fori(i,0,3) cin>>v[i];
	
	memset(dp, INF, sizeof(dp));
	cout <<lul(n, 0) <<endl;

    
    return 0;
}

