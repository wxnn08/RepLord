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
	
	int step = 0;
	int ini = -1, fim = -1;
	for(int i = 0; i < s.size(); i++) {
		if(step == 0 and s[i] == '[')
			step++;
		if(step == 1 and s[i] == ':') {
			ini = i;
			break;
		}
	}
	
	step = 0;
 	for(int i = s.size()-1; i >= 0; i--) {
		if(step == 0 and s[i] == ']')
			step++;
		if(step == 1 and s[i] == ':') {
			fim = i;
			break;
		}
	}   

	if(ini >= fim or ini == -1 or fim == -1) {
		cout <<-1 <<endl;
		return 0;
	}
	int ans = 4;
	for(int i = ini; i < fim; i++) {
		if(s[i] == '|')
			ans++;
	}

	cout <<ans <<endl;
    return 0;
}

