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

bool isOpen(char c) {
	if(c == '[' or c == '<' or c == '{' or c == '(') return true;
	return false;
}

bool areEq(char a, char b) {
	if(a == '<' and b == '>') return true;
	if(a == '[' and b == ']') return true;
	if(a == '{' and b == '}') return true;
	if(a == '(' and b == ')') return true;
	return false;
}

int main() {
    ios_base::sync_with_stdio(false);
	
	stack<char> s;
	string q;
	cin >>q;
	
	int ans = 0;
	for(char at:q) {
		if(isOpen(at)) s.push(at);
		else {
			if(s.size() == 0) {
				cout <<"Impossible" <<endl;
				return 0;
			}
			if(!areEq(s.top(), at)){
				ans ++;
			}
			s.pop();
		}
	}

	if(s.size() > 0) {
		cout <<"Impossible" <<endl;
		return 0;
	}
	
	cout <<ans <<endl;
    return 0;
}

