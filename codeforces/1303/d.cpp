#include<bits/stdc++.h>
using namespace std;
 
const int N = 62;
typedef long long ll;
 
vector<int> calc_goal(ll n) {
    vector<int> ans(N, 0);
    for(int i = 0; i < N; i++) {
        if(n & (1LL<<i)) ans[N-i-1] = 1;
    }
 
    return ans;
}
 
int move_to_left(vector<int> &v, const vector<int> &goal) {
    int pos = N-1;
    while(pos >= 0) {
        if(goal[pos] > v[pos]) break;
       
        if(pos-1 > 0) {
            int tonext = ((v[pos]-goal[pos])/2) * 2;
            v[pos] -= tonext;
            v[pos-1] += (tonext/2);
        }
        pos--;
    }
 
    return pos;
}
 
ll complete_position(vector<int> &v, int pos) {
    int ori = pos;
    pos--;
    ll ans = 0;
    while(pos > 0 and v[pos] == 0) pos--;
    while(pos != ori and v[pos] > 0) {
        v[pos]--;
        v[pos+1] += 2;
        ans++;
        pos++;
    }
    return ans;
}
 
int main() {
   
    int tc; cin >>tc;
    while(tc--) {
 
        ll n, m; cin >>n >>m;
        vector<int> goal = calc_goal(n);
 
        vector<int> v(N, 0);
        ll sum = 0;
        for(int i = 0; i < m; i++) {
            ll a; cin >>a;
            sum += a;
			int pos = 0;
			while(a > 1) a /= 2, pos++;
            v[N-pos-1]++;
        }
 
        if(sum < n) {
            cout <<-1 <<endl;
            continue;
        }
 
        int right = move_to_left(v, goal);
 
        ll ans = 0;
        while(right >= 0) {
            if(goal[right] > v[right]) {
                ans += complete_position(v, right);
            }
            else right--;
        }
 
        cout <<ans <<endl;
    }
 
    return 0;
}

