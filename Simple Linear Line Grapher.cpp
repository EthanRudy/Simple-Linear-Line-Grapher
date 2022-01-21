/**
	Simple Linear Line Grapher: Graphs a rough linear line on a 10x10 Grid
	@file Simple Linear Line Grapher.cpp
	@author Ethan Rudy
	@version 1/20/21
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


////\\\\ STRUCTURES ////\\\\
// Structure for holding xy coordinates
struct point {
	int x, y;
};

// Structure for holding our equation data
struct equation {
	double m;
	int b;
};


////////\\\\\\\\ FUNCTION DECLARATIONS ////////\\\\\\\\


////\\\\ USER INPUT ////\\\\

/*
	Prompts the user to input
	the slope(m) and y - intercept(b) of an equation
	@param NULL
	@return A completed equation object : "e"
*/
equation getEquation();


////\\\\ LINE LOGIC ////\\\\

/*
	Generates a set of points
	based off passed equation
	@param An equation : "e";
	@return A vector full of point objects : "points"
*/
vector<point> fillPoints(equation e);

/*
	Generates a grid and then draws points
	using the passed vector or points
	@param A vector of point objects "points"
	@return 2D vector of strings represting the graph
*/
vector<vector<string>> genGrid(vector<point> points);

/*
	Draws the points on a 2D vector
	@param A vector of points (points)
	@param A 2D vector of strings (grid>
	@return A filled and drawn 2D vector
			of strings
*/
vector<vector<string>> calcGrid(vector<point> points, vector<vector<string>> grid);


////\\\\ PRINTER FUNCTIONS ////\\\\

/*
	Prints a vector of points
	@param A vector of point objects
*/
void printPoints(vector<point> points);

/*
	Prints a grid
	@param A 2D vector of strings
		represting said grid
*/
void printGrid(vector<vector<string>> grid);


////\\\\ MAIN FUNCTION ////\\\\
// Contains the main operations for the program
int main()
{
	cout << "NOTICE: Graphing window is (0, 0) -> (10, 10)" << endl
		<< "Until more code is wirtten, each square unit"	<< endl
		<< "will be represented by three consecutive"		<< endl
		<< "spaces.This makes the output less accurate"		<< endl
		<< "than individual spaces but looks more like"		<< endl
		<< "a square rather than a rectangle.More info"		<< endl
		<< "can be found at listed GitHub repository :"		<< endl
		<< "INSERT LINK" << endl;
	system("pause");
	system("CLS");
	equation e = getEquation();
	vector<point> points = fillPoints(e);
	printPoints(points);
	vector<vector<string>> grid = genGrid(points);
	printGrid(grid);
}


////\\\\ FUNCTION INITIALIZATIONS ////\\\\
// Prompts the user to input the slope(m) and y - intercept(b) of an equation
equation getEquation() {
	equation e;
	cout << "Equations are taken in the form: y = m(x) + b" << endl;
	cout << "Enter slope(m): ";
	cin >> e.m;
	cout << "Enter y-int(b): ";
	cin >> e.b;
	return e;
}

// Generates a set of points 
vector<point> fillPoints(equation e) {
	vector<point> points;
	for (int i = 1; i < 11; i++) {
		point p;
		p.x = i;
		p.y = (i * e.m) + e.b;
		points.push_back(p);
	}
	return points;
}

// Generates a grid and then draws points 
vector<vector<string>> genGrid(vector<point> points) {
	vector<vector<string>> grid;
	for (int y = 10; y > 0; y--) {
		vector<string> row;
		y == 10 ? row.push_back(to_string(y) + "-|") : row.push_back(" " + to_string(y) + "-|");
		for (int x = 1; x < 11; x++) {
			row.push_back("   ");
		}
		grid.push_back(row);
	}
	vector<string> xAxis;
	xAxis.push_back("   -");
	for (int i = 1; i < 11; i++) {
		xAxis.push_back("-" + to_string(i) + "-");
	}
	grid.push_back(xAxis);
	grid = calcGrid(points, grid);
	return grid;
}

// Draws the points on a 2D vector
vector<vector<string>> calcGrid(vector<point> points, vector<vector<string>> grid) {
	for (int i = 0; i < points.size(); i++) {
		if (points[i].x > 0 && points[i].x < 11) {
			if (points[i].y > 0 && points[i].y < 11) {
				grid[10 - points[i].y][points[i].x] = "---";
			}
		}
	}
	return grid;
}

// Prints a vector of points
void printPoints(vector<point> points) {
	int count = 0;
	for (int i = 0; i < 10; i++) {
		cout << "(" << points[i].x << ", " << points[i].y << "), ";
		count++;
		if (count % 4 == 0) {
			cout << endl;
		}

	}
	cout << endl;
}

// Prints a grid
void printGrid(vector<vector<string>> grid) {
	for (int i = 0; i < grid.size(); i++) {
		for (int ii = 0; ii < grid[i].size(); ii++) {
			cout << grid[i][ii];
		}
		cout << endl;
	}
}
