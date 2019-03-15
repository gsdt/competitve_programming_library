#include <bits/stdc++.h>
using namespace std;

const double epsilon = 1e-8;
bool equal(double a, double b) {
	a = b-a;
	return fabs(a) <= epsilon;
}

struct Point{
    int x;
    int y;

    double distanceTo(Point other) {
        double xx = (x-other.x); xx *= xx;
        double yy = (y-other.y); yy *= yy;
        return sqrt(xx+yy);
    }
};


//Circle class supporting 3 point form of a circle
class Circle {
public:
	double getRadius();
	Point getCenter();
	Circle(Point p1, Point p2, Point p3);
	Circle();
	double CalcCircle(Point p1, Point p2, Point p3);
	bool isPerp(Point p1, Point p2, Point p3);
    void show();
private:
	double m_rad;
	Point m_cent;
};

Circle::Circle() {
	this->m_rad = -1;
}

Circle::Circle(Point p1, Point p2, Point p3) {
	this->m_rad = -1;
	Point pt1, pt2, pt3;
	pt1 = p1, pt2 = p2, pt3 = p3;
	if(!this->isPerp(pt1, pt2, pt3)) this->CalcCircle(pt1, pt2, pt3);
	else if(!this->isPerp(pt1, pt3, pt2)) this->CalcCircle(pt1, pt3, pt2);
	else if(!this->isPerp(pt2, pt1, pt3)) this->CalcCircle(pt2, pt1, pt3);
	else if(!this->isPerp(pt2, pt3, pt1)) this->CalcCircle(pt2, pt3, pt1);
	else if(!this->isPerp(pt3, pt2, pt1)) this->CalcCircle(pt3, pt2, pt1);
	else if(!this->isPerp(pt3, pt1, pt2)) this->CalcCircle(pt3, pt1, pt2);
	else {
		this->m_rad = -1;
	}
	return;
}

bool Circle::isPerp(Point pt1, Point pt2, Point pt3) {
	double yda = pt2.y - pt1.y;
	double xda = pt2.x - pt1.x;
	double ydb = pt3.y - pt2.y;
	double xdb = pt3.x - pt2.x;
	if(equal(xda, 0.0) && equal(ydb,0.0)) return false;
	else if(equal(yda, 0.0)) return true;
	else if(equal(ydb, 0.0)) return true;
	else if(equal(xda, 0.0)) return true;
	else if(equal(xdb, 0.0)) return true;
	else return false;
}

double Circle::CalcCircle(Point pt1, Point pt2, Point pt3) {
	double yda = pt2.y - pt1.y;
	double xda = pt2.x - pt1.x;
	double ydb = pt3.y - pt2.y;
	double xdb = pt3.x - pt2.x;
	if(equal(xda, 0.0) && equal(ydb,0.0)) {
		this->m_cent.x = 0.5*(pt2.x + pt3.x);
		this->m_cent.y = 0.5*(pt1.y + pt2.y);
		this->m_rad = m_cent.distanceTo(pt1);
		return this->m_rad;
	}
	double aS = yda/xda;
	double bS = ydb/xdb;
	if(equal(aS-bS, 0.0)) {
		//collinear
		return -1;
	}
	Point p;
	p.x = (aS*bS*(pt1.y-pt3.y) + bS*(pt1.x+pt2.x)
			- aS*(pt2.x+pt3.x))/(2 * (bS - aS) );
	p.y = -1*(p.x - (pt1.x+pt2.x)/2)/aS + (pt1.y+pt2.y)/2;
	this->m_cent = p;
	this->m_rad = m_cent.distanceTo(pt1);
	return this->m_rad;
}

Point Circle::getCenter() {
	return this->m_cent;
}

double Circle::getRadius() {
	return this->m_rad;
}

void Circle::show() {
	cerr<<"Center: " << this->m_cent.x << ", " << this->m_cent.y <<endl;
    cerr<<"Radius: " << this->m_rad << endl;
}

int main() {
    // https://discuss.codechef.com/questions/17515/cirkill-editorial
}