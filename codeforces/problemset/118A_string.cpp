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
	
	char c;
	
    while(cin >>c) {
		if(c >= 'A' and c <= 'Z') c = 'a' + (c - 'A');
		if(c !='a' and c !='e' and c !='i' and c !='o' and c !='u' and c != 'y')
			cout <<'.'<<c;
	}
    
    return 0;
}

