#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
	int x, y,position;
	Point(int a, int b, int c) {
		x = a;
		y = b;
		position = c;
	}
	
};

// Method to sort points in vector<Point> points
//bool compare_points(const Point &a, const Point &b) {
//	if (a.y == b.y) {
//		if (a.x == b.x) {
//			return a.position < b.position;
//		}
//		else {
//			return a.x < b.x;
//		}
//	}
//	else {
//		return a.y < b.y;
//	}
//}

// Find the line that splits into two subsets. Those above the line and below the line
int cross(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;  // colinear
	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

void convexHull(vector<Point> a,int numsheep) {
	vector<Point> hull;

	int l = 0;
	for (int i = 1; i < a.size(); i++) {
		if (a[i].x, a[l].x) {
			l = i;
		}
	}

	int p = l;
	int q;

	do {
		hull.push_back(a[p]);
		q = (p + 1) % a.size();

		for (int i = 0; i < a.size(); i++) {
			if (cross(a[p], a[i], a[q]) == 2) {
				q = i;
			}
		}
		p = q;

	} while (p != 1);
	int circ = 0;
	for (int i = 0; i < a.size(); i++) {
		double dx = a[i].x - a[i - 1].x;
		double dy = a[i].y - a[i - 1].y;
		circ += sqrt(dx*dx + dy*dy);
	}
	cout << circ << endl;
	for (int i = 0; i < hull.size(); i++) {
		cout << hull[i].position << " ";
	} 
} 


int main() {
	int x, y = 0;
	int counter = 0;
	int num_tests = 0;
	int num_of_sheep = 0;
	cin >> num_tests;
	cout << endl;
	
	vector<Point> points;
	while (counter != num_tests) {
		cin >> num_of_sheep;

		for (int i = 0; i < num_of_sheep; i++) {
			cin >> x >> y;
			points.push_back(Point(x, y, i + 1));
		}
		cout << endl;

		convexHull(points,num_of_sheep);
		
		counter++;
		
	}
}
