#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);
	
	int cx = 0, cy = 0;
	string s;
	cin >>s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'x') cx++;
		if(s[i] == 'y') cy++;
	}
	for(int i = 0; i < cx-cy; i++) 
		cout <<'x';
	for(int i = 0; i < cy-cx; i++) 
		cout <<'y';
	cout <<endl;
    return 0;
}

