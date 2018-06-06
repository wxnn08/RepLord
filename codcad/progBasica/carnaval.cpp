#include <bits/stdc++.h>
using namespace std;

int main (){

	float a,b,c,d,e, a1,b1,c1,d1,e1;
	cin >>a >>b >>c >>d >>e;
	a1=a; b1=b; c1=c; d1=d; e1=e;

	if(a>=b && a>=c && a>=d && a>=e) a1=0;
	else if(b>=a && b>=c && b>=d && b>=e) b1=0;
	else if(c>=a && c>=b && c>=d && c>=e) c1=0;
	else if(d>=a && d>=b && d>=c && d>=e) d1=0;
	else if(e>=a && e>=b && e>=c && e>=d) e1=0;
	
	if(a<=b && a<=c && a<=d && a<=e) a1=0;
	else if(b<=a && b<=c && b<=d && b<=e && b!=0) b1=0;
	else if(c<=a && c<=b && c<=d && c<=e && c!=0) c1=0;
	else if(d<=a && d<=b && d<=c && d<=e && d!=0) d1=0;
	else if(e<=a && e<=b && e<=c && e<=d && e!=0) e1=0;
	
	a=a1+b1+c1+d1+e1;
	cout <<fixed <<setprecision(1) <<a;

return 0;
}
