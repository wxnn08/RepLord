#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;

	string s; 
	cin >>s;
	
	char v[] = {'A', 'C', 'T', 'G'};
	int ans = INF;
	for(int i = 0; i < s.size()-3; i++) {
		int cont = 0;
		for(int j = 0; j < 4; j++) {
			if(v[j] == s[j+i]) continue;
			if(v[j] > s[j+i]) cont += min(v[j]-s[j+i], s[j+i]-'A'+'Z'-v[j]+1);
			else cont += min(s[j+i]-v[j], 'Z'-s[i+j]+v[j]-'A'+1);
		}
		ans = min(cont, ans);
	}
	cout <<ans <<endl;
    
    return 0;
}

