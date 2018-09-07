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

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

	int n, k;
	cin >>n >>k;
	
	int a[27];
	memset(a, 0, sizeof a);
	fori(i,0,n){
		char c;
		cin >>c;
		a[c-'A']++;
	}
    
	int menor = INF;
	fori(i,0,k){
		menor = min(menor, a[i]);
	}

	cout <<k*menor <<endl;

    return 0;
}

