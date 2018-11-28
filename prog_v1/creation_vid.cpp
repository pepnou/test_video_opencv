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

#include "Circle.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	srand(time(NULL));
	
    char* imageName = argv[1];

	Mat image;
	image = imread( imageName, 1 );

	if( argc != 2 || !image.data ) {
	cout  << "No image data \n" << endl;
	return -1;
	}
    
    char videoName[strlen(imageName)];
    strcpy(videoName, imageName);
    strcpy(&(videoName[strlen(imageName)-3]), "avi");
    
    cout  << videoName << endl;
    
    Size S = Size(image.cols, image.rows);
    VideoWriter outputVideo;
    
    int ex = outputVideo.fourcc('H','2','6','4');
    //~ int ex = outputVideo.fourcc('X','V','I','D');
    //~ int ex = outputVideo.fourcc('a','v','c','1');
    
    outputVideo.open(videoName, ex, 60, S, true);
	
    if (!outputVideo.isOpened()) {
        cout  << "Could not open the output video for write. " << endl;
        return -1;
    }
    
	vector<Circle*> circles;
	Circle* c;
	
	int total = 20, count, attemps, x, y, i, j, k;
	bool valid;
		
	Mat frame(image.rows, image.cols, CV_8UC3, Scalar(0, 0, 0));

    for(;;) {
		//cout << circles.size() << "circles" << endl;
		count = 0;
		attemps = 0;
		
		while(count < total) {
			y = rand()%image.rows;
			x = rand()%image.cols;
			
			valid = true;
			
			for(i=0;i<circles.size();i++) {
				if(circles[i]->distance(x,y) < circles[i]->getRadius() + Circle::initial_radius) {
					valid = false;
					attemps++;
					//cout << attemps << " attemps" << endl;
					break;
				}
			}
			
			if(attemps > 50000) {
				cout << "Finished" << endl;
				cout << circles.size() << "circles" << endl;
				
				for(i=0;i<200;i++)
					outputVideo << frame;
				
				return 0;
			}
			if(valid) {
				c = new Circle(x,y,image.at<char>(y, x*3 + 2),image.at<char>(y, x*3 + 1),image.at<char>(y, x*3));
				circles.push_back(c);
				count++;
			}
		}
		
		for(i=0;i<circles.size();i++) {
			if(circles[i]->getGrowSpeed() > 0) {
				for(j=0;j<circles.size();j++) {
					if((circles[i]->distance(*circles[j]) > 0 && circles[i]->distance(*circles[j]) <= (circles[i]->getRadius() + circles[j]->getRadius())) ||  circles[i]->border(image.cols, image.rows)) {
						circles[i]->setGrowSpeed(0.0);
						break;
					}
				}
				if(circles[i]->getGrowSpeed() > 0) {
					circles[i]->grow();
					circles[i]->draw(frame);
				}
			}
		}
		
		outputVideo << frame;
		
		/*if(circles.size()>=5000)
			return 0;*/
	}
    
    return 0;
}
