#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

int orientation( Point p, Point q, Point r ){
    // basic geomatrix formula
    int val = (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    
    if ( val == 0 ) return 0; // if 0 then all line are in 1 line
    return ( val>0 ) ? 1:2; // if point is left then 1 else right 2 
} 

void convexHull( Point points[], int n ){
    // if 2 then straight line 
    // if 3 the triangle
    if ( n < 3 ) return;
     
    vector<Point> hull;
    int l = 0;
    for ( int i = 1; i < n; i++ ){ // take the left most point
        if ( points[i].x < points[l].x ){
            l = i;
        }
    }
    
    int p = l, q;
    do { 
        hull.push_back(points[p]); // pushing back the left most point
        q = ( p+1 ) % n; // rotating throught the array to get the next point
        for ( int i = 0; i < n; i++ ){
            // if = 2 then it will consider hull as it is at the right
            if ( orientation(points[p],points[i],points[q]) == 2 ){
                q = i;
            }
        }   
        p = q;
    } while ( p != l ); // while start != end
    
    // priting all the points 
    for ( int i = 0; i < hull.size(); i++ ){
        cout << "(" << hull[i].x << "," << hull[i].y<< ")\n";
    }
}

int main(){
    Point points[] = {{0,3},{2,2},{2,1},{3,0},{0,0},{3,3}};
    
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points,n);
    return 0;
}