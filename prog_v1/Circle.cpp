#include <math.h>

#include "Circle.hpp"

using namespace cv;
using namespace std;

Pos::Pos(int x_, int y_) : x(x_), y(y_) {
	
}

Color::Color(int r_, int g_, int b_) : r(r_), g(g_), b(b_) {
	
}

Circle::Circle(int x_, int y_, int r_, int g_, int b_) : r(Circle::initial_radius), growing_speed(0.15), color(r_, g_, b_), pos(x_, y_) {
	
}

void Circle::grow() {
	r += growing_speed;
}

void Circle::setGrowSpeed(float s) {
	growing_speed = s;
}

double Circle::distance(int x_, int y_) {
	return sqrt(pow(pos.x-x_,2)+pow(pos.y-y_,2));
}

double Circle::distance(Pos pos_) {
	return distance(pos_.x, pos_.y);
}

double Circle::distance(Circle c) {
	return c.distance(pos.x, pos.y);
}

float Circle::getRadius() {
	return r;
}

Pos Circle::getPos() {
	return pos;
}

bool Circle::border(int width, int height) {
	return 	(pos.x - r <= 0) 	||
			(pos.x + r >= width)||
			(pos.y - r <= 0)	||
			(pos.y + r >= height);
}

void Circle::draw(Mat image) {
	for(int i=pos.x-r;i<pos.x+r;i++) {
		for(int j=pos.y-r;j<pos.y+r;j++) {
			if(distance(i,j) < r) {
				image.at<char>(j, i*3) = color.b;
				image.at<char>(j, i*3 + 1) = color.g;
				image.at<char>(j, i*3 + 2) = color.r;
			}
		}
	}
}

float Circle::getGrowSpeed() {
	return growing_speed;
}



















