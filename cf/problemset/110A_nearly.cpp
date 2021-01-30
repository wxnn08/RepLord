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

    string s;
	cin >>s;

	int qtd = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '4' or s[i] == '7') qtd++;
	}
    
	if(qtd == 4 or qtd == 7) cout <<"YES" <<endl;
	else cout <<"NO" <<endl;
    return 0;
}

