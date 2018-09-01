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

    int x, y;
	cin >>x >>y;
	bool res = true;
	if(y == 0) res = false;
	if(y == 1 and x>0) res = false;
	if(y-1 > x) res = false;
	x -= (y-1);
	if(x%2 != 0) res = false;

	cout <<(res?"Yes":"No") <<endl;
    
    return 0;
}

