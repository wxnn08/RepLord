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

    int m, s;
	cin >>m >>s;

	vector<int> v;
	v.pb(1);
	for(int i = 1; i < m; i++) v.pb(0);

	int i = 0, cont = 1;
	while(cont < s and i < m) {
		if(v[i] < 9) {
			cont++;
			v[i]++;
		} else {
			i++;
		}
	}

	if(cont != s) {
		cout <<-1 <<' ' <<-1 <<endl;
		return 0;
	}

	reverse(v.begin(), v.end());
	for(int at:v) 
		cout <<at;
	cout <<' ';

	reverse(v.begin(), v.end());
	for(int at:v) 
		cout <<at;
	cout <<endl;

    
    return 0;
}

