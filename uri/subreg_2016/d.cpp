#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int A,B,C,D;
bool solve(int n){
	if((n%A == 0) and (n%B != 0) and (C%n == 0) and (D%n != 0))
		return true;
	return false;
}

int main(){
    ios_base::sync_with_stdio(false);

	cin >>A >>B >>C >>D;
	
	const int tam = 1e9;
	int i = 1;
	int res = C+1;
	while(i*i <= C) {
		if(solve(i)) {
			res = min(res, i);
		}
		if(solve(C/i)) {
			res = min(res, C/i);
		}
		i++;
	}

	if (res == C+1) res = -1;
	cout <<res <<endl;
    return 0;
}

