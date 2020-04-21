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


int valor[6] = {2, 5, 10, 20, 50, 100};
int quant[6];
int s;

const int N = 5e3+5;
int dp[N][7][505];

int solve(int din, int idNota) {
	if(din == s) return 1;
	if(din > s) return 0;
	
	int &r = dp[din][idNota][quant[idNota]];
	if(r != -1) {
		return r;
	}
	
	int ans = 0;
	for(int i = idNota; i < 6; i++){ 
		if(quant[i] > 0) {
			quant[i]--;
			ans += solve(din+valor[i], i);
			quant[i]++;
		}
	}
	return r = ans;
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >>s;
	fori(i, 0, 6) cin >>quant[i];
    
	memset(dp, -1, sizeof(dp));
	cout <<solve(0, 0) <<endl;

    return 0;
}

