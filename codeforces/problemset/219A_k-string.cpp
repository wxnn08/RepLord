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
 
int let[50];
int main(){
    ios_base::sync_with_stdio(false);

    char c;
	int n; cin >>n;
	while(cin >>c) let[c-'a']++;
    
	string ans = "";
	for(int i = 0; i < 30; i++) {
		if(let[i]%n != 0) {
			cout <<-1 <<endl;
			return 0;
		}
		else {
			for(int j = 0; j < let[i]/n; j++) {
				ans += (char)('a' + i);
			}
		}
	}
	for(int i = 0; i < n; i++) cout <<ans;
	cout <<endl;

    return 0;
}

