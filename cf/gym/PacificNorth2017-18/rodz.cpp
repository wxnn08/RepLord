#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
 
using namespace std;
 
typedef pair<int, int> ii;
typedef long long ll;
 
vector<pair<int, double> > sw;
int n, x;
double v;
const double PI = acos(-1.0);
 
double final_y(double theta)
{
	double y = x * tan(theta);
 
	for (int i = 0; i < n; i++)
	{
		int l = sw[i].fi;
		double vs = sw[i].se;
 
		double h = l / cos(theta);
		double t = h / v;
		
		y += vs * t;
	}
	return y;
}
 
double total_time(double theta)
{
	double h = x/cos(theta);
	return h / v;
}
 
int main()
{
	cin >> n >> x >> v;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		double vi;
		cin >> l >> r >> vi;
		sw.eb(r-l, vi);
	}
	double lo = -PI/3.0, hi = PI/3.0;
	int iter = 10000;
	while (iter--)
	{
		double mid = 0.5*(lo+hi);
		if (final_y(mid) > 0.0)
			hi = mid;
		else
			lo = mid;
	}
	double theta = (lo+hi)/2.0;
	cout <<"Theta: " <<theta <<endl;
	if (abs(final_y(theta)) > 1e-9)
	{
		printf("Too hard\n");
		return 0;
	}
	printf("%.3lf\n", total_time(theta));
	return 0;
}
