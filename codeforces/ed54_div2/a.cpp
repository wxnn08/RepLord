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
	
	int n; cin >>n;
    string s;
	cin >>s;
	
	int id = n-1;
	for(int i = 0; i < s.size()-1; i++) {
		if(s[i] > s[i+1]) id = min(i, id);
	}
	
	string t = "";
	for(int i = 0; i < s.size(); i++)
		if(i != id) t += s[i];

	cout <<t <<endl;
    return 0;
}

