/* Feito por wxn_ em 07/09/2020*/
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

const int N = 3e5;
string minSupertring[N];
vector<string> perms[N];
vector<string> in;
int cont = 0;
int goal = 0;
int h, w, n;

void createAllPerms(const vector<string> &s, int pos, vector<string> &t) {
	if(pos < 0) {
		perms[cont++] = t;
		return;
	}
	
	createAllPerms(s, pos-1, t);
	t.pb(s[pos]);
	createAllPerms(s, pos-1, t);
	t.pop_back();

	return;
}
 
int findOverlappingPair(string str1, string str2, string &str) {
    int max = INT_MIN;
    int len1 = str1.length();
    int len2 = str2.length();

    for (int i = 1; i <= min(len1, len2); i++) {
        if (str1.compare(len1-i, i, str2, 0, i) == 0) {
            if (max < i) {
                max = i;
                str = str1 + str2.substr(i);
            }
        }
    }

    for (int i = 1; i <= min(len1, len2); i++) {
        if (str1.compare(0, i, str2, len2-i, i) == 0) {
            if (max < i) {
                max = i;
                str = str2 + str1.substr(i);
            }
        }
    }

    return max;
}

string findShortestSuperstring(vector<string> &arr, int len) {
    while(len != 1) {
        int max = INT_MIN;
        int l, r;  
        string resStr;

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                string str;
                int res = findOverlappingPair(arr[i], arr[j], str);
                if (max < res) {
                    max = res;
                    resStr.assign(str);
                    l = i, r = j;
                }
            }
        }

        len--;
        if (max == INT_MIN)
            arr[0] += arr[len];
        else {
            arr[l] = resStr;
            arr[r] = arr[len];
        }
    }
    return arr[0];
}

vector<int> solve(int mask, int currH, vector<int> &carry) {
	if(mask == goal) {
		return carry;
	}
	
	vector<int> ans;
	for(int i = 0; i < in.size(); i++) {
		int nextMask = mask | (1 << i);
		if(mask != nextMask){
			if(minSupertring[nextMask].size() <= w) {
				if(carry.size() > currH) carry[currH] = nextMask;
				else carry.pb(nextMask);
				ans = solve(nextMask, currH, carry);
			} else if(currH+1 < h) {
				carry.pb(1<<i);
				ans = solve(nextMask, currH+1, carry);
				carry.pop_back();
			}
			if(ans.size()) {
				cout <<ans.size() <<endl;
				break;
			}
		}
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

	cin >>h >>w >>n;
	in.resize(n);
	vector<string> vs;
	for(int i = 0; i < n; i++) cin >>in[i];

	createAllPerms(in, in.size()-1, vs); //create perms

	for(int i = 0; i < cont; i++) {
		if(perms[i].size()) {
    		minSupertring[i] = findShortestSuperstring(perms[i], perms[i].size());
		}
	}
	for(int i = 0; i < in.size(); i++) {
		goal |= (1<<i);
	}
	vector<int> carry;
	vector<int> ans = solve(0, h, carry);
	if(ans.size()) {
		ans.resize(h);
		for(int c : ans) {
			string a = minSupertring[c];
			while(a.size() < w) a.pb('X');
			cout <<a <<endl;
		}
	} else {
		cout <<"impossible" <<endl;
	}

	return 0;
}
