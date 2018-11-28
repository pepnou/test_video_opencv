#ifndef CIRCLE_H
#define CIRCLE_H

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

class Pos {
	public:
		int x,y;
		Pos(int x_, int y_);
		~Pos(){};
};

class Color {
	public:
		char r,g,b;
		Color(int r_, int g_, int b_);
		~Color(){};
};

class Circle {
	private:
		Pos pos;
		Color color;
		float r;
		float growing_speed;
	
	public:
		static const int initial_radius = 1;
		Circle(int x_, int y_, int r_, int g_, int b_);
		~Circle(){};
		void grow();
		void setGrowSpeed(float s);
		double distance(int x_, int y_);
		double distance(Pos pos_);
		double distance(Circle c);
		float getRadius();
		Pos getPos();
		bool border(int width, int height);
		void draw(cv::Mat image);
		float getGrowSpeed();
};


#endif

