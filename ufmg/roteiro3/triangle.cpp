#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int ehTriangulo(pair <int,int> a, pair <int,int> b, pair <int,int> c){
    
}

int main(){
    ios_base::sync_with_stdio(false);

    pair <int,int> a,b,c;
    cin >>a.fi >>a.sec >>b.fi >>b.sec >>c.fi >>c.sec;
    
    /*	1- eh triangulo
	2- quase triangulo
   	3- nao é triangulo */
    
    int val = ehTriangulo(a,b,c);
    if(val == 1) cout <<"RIGHT";
    else if(val == 2) cout <<"ALMOST";
    else cout <<"RIGHT";

    
    return 0;
}

