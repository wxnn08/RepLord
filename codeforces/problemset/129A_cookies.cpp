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
	
	const int N = 100 + 5;
	int sum = 0, v[N];
	fori(i,0,n) {
		cin >>v[i];
		sum += v[i];
	}
	
	int ans = 0;
	fori(i,0,n) {
		if((sum-v[i])%2 == 0) ans++;
	}
	cout <<ans <<endl;
    
    return 0;
}

