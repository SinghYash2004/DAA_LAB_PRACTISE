#include <iostream>
#include <vector>

using namespace std;

/**
 * Convex Hull Problem - Jarvis March Algorithm (Gift Wrapping)
 * 
 * Logic:
 * 1. Find the leftmost point.
 * 2. Keep moving in counter-clockwise direction to find the next point on the hull.
 * 3. To find the next point, check all points and pick the one that is most counter-clockwise.
 * 
 * Time Complexity: O(nh) where n is the number of points and h is the number of points on the hull.
 */

struct Point {
    int x, y;
};

// To find orientation of triplet (p, q, r).
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock
}

void convexHull(vector<Point> points) {
    int n = points.size();
    if (n < 3) return;

    vector<Point> hull;

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    // Start from leftmost point, keep moving counter-clockwise until reach the start point
    int p = l, q;
    do {
        hull.push_back(points[p]);

        // Search for a point 'q' such that orientation(p, q, x) is counterclockwise for all points 'x'
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        p = q;

    } while (p != l);

    // Print Result
    cout << "Points in the Convex Hull:\n";
    for (auto temp : hull)
        cout << "(" << temp.x << ", " << temp.y << ")\n";
}

int main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    convexHull(points);
    return 0;
}
