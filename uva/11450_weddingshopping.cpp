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
vector <vector<int> > roupa; 
int TC, m, c, k, p;
int dp[210][25];

int backTrack(int din, int lin){

    if(din<0) return INT_MAX;

    if(lin==c) return din;

    if(dp[din][lin] != -1)
	return dp[din][lin]; 
    
    int minVal = INT_MAX;
    for(int i=0; i<roupa[lin].size(); i++){
	minVal = min(minVal, backTrack(din-roupa[lin][i], lin+1));
    }

    return dp[din][lin] = minVal;
}

int main(){
    ios_base::sync_with_stdio(false);

    
    set<int> auxS;

    cin >>TC;
    while(TC--){
	cin >>m >>c;

	memset(dp, -1, sizeof(dp));
	roupa.clear();
	for(int i=0; i<c; i++){
	    cin >>k;
	    auxS.clear();

	    while(k--){
		cin >>p;
		auxS.insert(p);
	    }
	    vector<int> auxV (auxS.begin(), auxS.end());
	    roupa.pb(auxV);
	}
	int res = backTrack(m, 0);
	if(m-res<0) cout <<"no solution" <<endl;
	else cout <<m-res <<endl;
    }

    
    return 0;
}
