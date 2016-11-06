/**
    Line Segments Intersection.
    Check whether two line segments intersect with each other or not.
**/

/// Include My Code Template
#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
};

/// 0 --> Collinear
/// 1 --> Clockwise
/// 2 --> Counterclockwise

int orientation(Point P, Point Q, Point R) {
	int res = (Q.y - P.y) * (R.x - Q.x) - (Q.x - P.x) * (R.y - Q.y);
	if (res > 0) return 1;
	else if (res < 0) return 2;
	else return 0;
}

bool onSegment(Point P, Point Q, Point R) {
	if (R.x >= min(P.x, Q.x) && R.x <= max(P.x, Q.x) &&
			R.y >= min(P.y, Q.y) && R.y <= max(P.y, Q.y)){
		return true;
	} else {
		return false;
	}
}

bool doIntersect(Point P1, Point P2, Point P3, Point P4) {
	int o1 = orientation(P1, P2, P3);
	int o2 = orientation(P1, P2, P4);
	int o3 = orientation(P3, P4, P1);
	int o4 = orientation(P3, P4, P2);

	if (o1 != o2 && o3 != o4 && o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0){
		return true;
	}

	if (o1 == 0 && onSegment(P1, P2, P3)) return true;
	if (o2 == 0 && onSegment(P1, P2, P4)) return true;
	if (o3 == 0 && onSegment(P3, P4, P1)) return true;
	if (o4 == 0 && onSegment(P3, P4, P2)) return true;
	return false;
}

int main() {
	/// P1 and P2 point create a line segment.
	/// P1 and P4 point create another line segment.
	Point P1, P2, P3, P4;

	/// Take input the coordinate of 4 points.
	P1 = {1,1};
	P2 = {10,1};
	P3 = {1,2};
	P4 = {10,2};
	if (doIntersect(P1, P2, P3, P4)){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
