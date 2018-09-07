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

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e2+5;
string s;
int memo[N][N];
bool pal(int a, int b){
	for(int i=0; i<=((b-a)+1)/2; i++){
		if(s[a+i]!=s[b-i]){
			return false;
		}
	}
	return true;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	cin >>s;
	for(int i=1; i<s.size(); i+=2){
		for(int j=0; j+i<s.size(); j++){
			if(pal(j,j+i)) {
				cout <<"Or not." <<endl;
				return 0;
			}
		}
	}
	cout <<"Odd." <<endl;
    
    return 0;
}

