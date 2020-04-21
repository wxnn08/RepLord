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
 
int main(){
    ios_base::sync_with_stdio(false);
	
	const int N = 5e4+5;
    int c[N];
	int n;
	cin >>n;

	fori(i,0,n) cin >>c[i];
    
	int maior1[N];
	fori(i,1,n) {
		if(maior1[i-1]+1 <= c[i]){
			maior1[i] = maior1[i-1]+1;
		}
		else {
			maior1[i] = c[i];
		}
	}
	
	int maior2[N];
	maior2[n-1] = 1;
	for(int i = n-2; i>=0; i--) {
		if(maior2[i+1]+1 <= c[i]){
			maior2[i] = maior2[i+1]+1;
		}
		else {
			maior2[i] = c[i];
		}
	}

	int res = 1;
	fori(i,0,n){
		res = max(res, min(maior1[i], maior2[i]));
	}

	cout <<res <<endl;
    return 0;
}

