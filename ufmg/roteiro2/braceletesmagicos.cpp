#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >>n;

    for(int i=0; i<n; i++){
	string s, p;
	cin >>p >>s;
	s += s;
	int pos = s.find(p);
	reverse(s.begin(), s.end());
	pos += s.find(p);
	if(pos != -2) cout <<"S";
	else cout <<"N";
	cout <<endl;
    }
    
    return 0;
}

