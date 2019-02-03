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

const int N = 30;
int alf[N];

int main(){
    ios_base::sync_with_stdio(false);

    int tc;
	cin >>tc;

	while(tc--) {
		string s;
		cin >>s;
		int dif = 0;
		memset(alf, 0, sizeof alf);
		for(int i = 0; i < s.size(); i++) {
			if(alf[s[i]-'a'] == 0)
				dif++;
			alf[s[i]-'a']++;
		}
		if(dif == 1) {
			cout <<-1 <<endl;
			continue;
		}
		sort(s.begin(), s.end());
		cout <<s <<endl;
	}
    
    return 0;
}

