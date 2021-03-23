#include<bits/stdc++.h>
using namespace std;
struct point{
	int X, Y;
	point(int x, int y): X(x) , Y(y){} // we can simply set X , Y by calling with an argument
};
struct point2{
	int X, Y;      
};
int main(){
	point p1(1, 1); // point2 p2(10, 1); p1.X and p2.Y value has been set 
	point2 p2;
	p2.X = 2;      // setting X the value
	p2.Y = 2;      // setting the Y value
	cout << p1.X << " " << p1.Y << endl;
	cout << p2.X << " " << p2.Y << endl;
}