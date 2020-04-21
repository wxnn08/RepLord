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
	
	bool ans = true;
    int a, b, c, d;
	cin >>a >>b >>c >>d;
	
	if(abs(c-d) > 1) ans = false;
	
	string s1 = "474";
	string s2 = "747";
	if(ans) {
		for(int i = 1; i < min(c, d); i++)
			s1 += "74";
		if(c > d) 
			s1 += "7";
		if(d > c) {
			string t = "7";
			t += s1;
			s1 = t;
		}

		for(int i = 1; i < min(c, d); i++)
			s2 += "47";
		if(d > c) 
			s2 += "4";
		if(c > d) {
			string t = "4";
			t += s2;
			s2 = t;
		}

		int cont4 = 0, cont7 = 0;
		int id4 = (int)s1.size(), id7 = 0;
		for(int i = 0; i < s1.size(); i++) {
			if(s1[i] == '4') {
				cont4++;
				id4 = min(i, id4);
			}
			if(s1[i] == '7') {
				id7 = max(i, id7);
				cont7++;
			}
		}

		int cont42 = 0, cont72 = 0;
		int id42 = (int)s2.size(), id72 = 0;
		for(int i = 0; i < s2.size(); i++) {
			if(s2[i] == '4') {
				cont42++;
				id42 = min(i, id42);
			}
			if(s2[i] == '7') {
				id72 = max(i, id72);
				cont72++;
			}
		}
		
		if(cont4 > a or cont7 > b) s1 = "-1";
		if(cont42 > a or cont72 > b) s2 = "-1";
		
		if(s1 == "-1" and s2 == "-1") ans = false;

		int a1 = a - cont4, a2 = a - cont42;
		int b1 = b - cont7, b2 = b - cont72;

		if(s1 != "-1") {
			string t = "";
			for(int i = 0; i < id4; i++) t += s1[i];
			for(int i = 0; i < a1; i++) t += '4';
			for(int i = id4; i < id7; i++) t += s1[i];
			for(int i = 0; i < b1; i++) t += '7';
			for(int i = id7; i < s1.size(); i++) t += s1[i];
			s1 = t;
		}
		
		if(s2 != "-1") {
			string t = "";
			for(int i = 0; i < id42; i++) t += s2[i];
			for(int i = 0; i < a2; i++) t += '4';
			for(int i = id42; i < id72; i++) t += s2[i];
			for(int i = 0; i < b2; i++) t += '7';
			for(int i = id72; i < s2.size(); i++) t += s2[i];
			s2 = t;
		}
	}
	if(!ans) cout <<-1 <<endl;
	else if(s1 != "-1" and s2 != "-1") cout <<min(s1, s2) <<endl;
	else if(s1 == "-1") cout <<s2 <<endl;
	else cout <<s1 <<endl;
    return 0;
}

