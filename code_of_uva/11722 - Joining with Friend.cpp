#include<bits/stdc++.h>
using namespace std;
double t1, t2, s1, s2, w, height, width;
double get_area(double w){
	double ly = t1 + w;
	double ry = t2 + w;
	double tx = s2 - w;
	double bx = s1 - w;
	bool on_left = ly >= s1 && ly <= s2;
	bool on_right = ry >= s1 && ry <= s2;
	bool on_top = tx >= t1 && tx <= t2;
	bool on_bottom = bx >= t1 && bx <= t2;
	if(on_left && on_right) return (s2 - ry + s2 - ly) * width * 0.5;
	if(on_left && on_top) return (tx - t1) * (s2 - ly) * 0.5;
	if(on_right && on_bottom) return width * height - (t2 - bx) * (ry - s1) * 0.5;
	if(on_top && on_bottom) return (tx - t1 + bx - t1) * height * 0.5;
	else{
		if(ly <= s1) return width * height;
		else return 0;
	}
}
int main(int argc, char const *argv[])
{	
	int cases;
	cin >> cases;
	for(int c = 1 ; c<=cases ; c++){
		printf("Case #%d: ", c);
		cin >> t1 >> t2 >> s1 >> s2 >> w;
		height = s2 - s1;
		width = t2 - t1;
		double area1 = get_area(w);
		double area2 = get_area(-w);
		double ans = (area2 - area1) / (width * height);
		printf("%.6lf\n", ans);
	}

	return 0;
}