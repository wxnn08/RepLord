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

const int N = 2e6 + 5;
int l[N], r[N];

int main(){
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	
	int mid, contL = 0, contR = 0;
	bool first = true;
	while(n--) {
		char c;
		int v;
		cin >>c >>v;
		if(first){
			mid = v;
			first = false;
		}
		else {
			if(c == 'L') {
				l[v] = ++contL;
			}
			if(c == 'R') {
				r[v] = ++contR;
			}
			if(c == '?') {
				if(v == mid) {
					cout <<min(contL, contR) <<endl;
				}
				else {
					if(l[v] != 0){
						cout <<min(contL-l[v], contR+l[v]) <<endl;
					}
					else {
						cout <<min(contR-r[v], contL+r[v]) <<endl;
					}
				}
			}
		}
	}
    
    return 0;
}

