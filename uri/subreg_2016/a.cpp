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

    int a, b, c;
	cin >>a >>b >>c;
	
	bool res = false;
	if(a == b || a == c || b == c) res = true;
	if(a+b == c || a+c == b || b+c == a) res = true;

	cout <<(res?'S':'N') <<endl;
    
    return 0;
}

