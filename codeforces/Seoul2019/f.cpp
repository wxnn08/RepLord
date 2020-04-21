#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

bool isOperator(char c) {
	return c == '+' or c == '-' or c == '/' or c == '*' or c == '%';
}

bool isParenthesis(char c) {
	return c == '(' or c == ')';
}

bool isVar(char c) {
	return !isOperator(c) and !isParenthesis(c);
}

bool isValidExp(const string &s) {
	stack<char> st;
	bool lastOp = true;
	for(auto c : s) {
		if(isParenthesis(c)) {
			if(c == '(') st.push(c);
			else {
				if(st.empty()) return false;
				st.pop();
			}
		}

		else if(isVar(c) and lastOp) lastOp = false;
		else if(isOperator(c) and !lastOp) lastOp = true;
		else return false;
	}
	
	if(st.size() or lastOp == true) return false;

	for(int i = 0; i < s.size()-1; i++) {
		if((isOperator(s[i]) and s[i+1] == ')') or (s[i] == '(' and isOperator(s[i+1]))) return false;
	}

	return true;
	
}

bool isProper(const string &s) {

	bool change = true;

	string t = "";
	for(auto c : s) {
		if(isVar(c)) t += 'v';
		if(isParenthesis(c)) t += c;
	}

	string invalid = "(vv)";
	while(change and t != invalid) {
		string tt = "";
		change = false;
		for(int i = 0; i < t.size(); i++) {
			if(i+3 < t.size() and t[i] == '(' and t[i+1] == 'v' and t[i+2] == 'v' and t[i+3] == ')') {
				tt += 'v';
				i += 3;
				change = true;
			}
			else
				tt += t[i];
		}

		t = tt;
	}

	if(t == "v" or t == "vv") return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);

	char c;
	string in = "";
	while(cin >>c) in += c;

	if(!isValidExp(in)) {
		cout <<"error" <<endl;
		return 0;
	}

	cout <<(isProper(in)? "proper" : "improper") <<endl;

    return 0;
}

