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
	char c;
	vector<int> v;
	fori(i,0,n) {
		cin >>c;
		v.pb(c-'0');
	}
	
	int s1 = 0;
	for(int i = 0; i < n-1; i++) {
		s1 += v[i];

		int sum = 0;
		int j;
		for(j = i+1; j < n; j++) {
			if(sum + v[j] <= s1){
				sum += v[j];
			}
			else {
				if(sum == s1) {
					sum = v[j];
				} else {
					break;
				}
			}
		}
		if(sum == s1 and j == n) {
			cout <<"YES" <<endl;
			return 0;
		}
	}

	cout <<"NO" <<endl;
    
    return 0;
}

