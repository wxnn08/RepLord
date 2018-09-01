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
 
int main(){
    ios_base::sync_with_stdio(false);

	string s;
	cin >>s;
	int p = 0, l = 0;
	for(char c:s){
		if(c=='o') p++;
		else l++;
	}

	if(p!=0 && l%p!=0) cout <<"NO" <<endl;
	else cout <<"YES" <<endl;
    
    return 0;
}

