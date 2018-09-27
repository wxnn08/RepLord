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
	
	string s;
	int ans = 0;
	fori(i,0,n) {
		cin >>s;
		fori(i,0,3) {
			if(s[i] == '+') {
				ans++;
				break;
			}
			if(s[i] == '-') {
				ans--;
				break;
			}
		}
	}
    
	cout <<ans <<endl;

    return 0;
}

