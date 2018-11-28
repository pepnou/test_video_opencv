#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>

#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	/*char* imageName = argv[1];

	Mat image;
	image = imread( imageName, 1 );

	if( argc != 2 || !image.data )
	{
	printf( " No image data \n " );
	return -1;
	}

	Mat gray_image;
	cvtColor( image, gray_image, CV_BGR2GRAY );

	imwrite( "../../images/Gray_Image.jpg", gray_image );

	namedWindow( imageName, CV_WINDOW_AUTOSIZE );
	namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );

	imshow( imageName, image );
	imshow( "Gray image", gray_image );*/
	
	
	
	
	
	
	
	
	/*//BGR pas RGB
	Mat image(500, 500, CV_8UC3, Scalar(0,255,0));
	
	namedWindow("test image verte", CV_WINDOW_AUTOSIZE);
	imshow("test image verte", image);
	
	//image.at<char>(colone,ligne)
	
	for(int i = 0;i<500;i++)
	{
		for(int j = 0;j<500;j++)
		{
			image.at<char>(j, 3*i    ) = 0;
			image.at<char>(j, 3*i + 1) = 0;
			image.at<char>(j, 3*i + 2) = 255;
		}
	}
	
	namedWindow("test image rouge", CV_WINDOW_AUTOSIZE);
	imshow("test image rouge", image);

	waitKey(0);

	return 0;*/
	
	
	
	
	
	
	
	
	
	/*if (argc != 4)
    {
        cout << "Not enough parameters" << endl;
        return -1;
    }
    const string source      = argv[1];           // the source file name
    const bool askOutputType = argv[3][0] =='Y';  // If false it will use the inputs codec type
    VideoCapture inputVideo(source);              // Open input
    if (!inputVideo.isOpened())
    {
        cout  << "Could not open the input video: " << source << endl;
        return -1;
    }
    string::size_type pAt = source.find_last_of('.');                  // Find extension point
    const string NAME = source.substr(0, pAt) + argv[2][0] + ".avi";   // Form the new name with container
    int ex = static_cast<int>(inputVideo.get(CAP_PROP_FOURCC));     // Get Codec Type- Int form
    // Transform from int to char via Bitwise operators
    char EXT[] = {(char)(ex & 0XFF) , (char)((ex & 0XFF00) >> 8),(char)((ex & 0XFF0000) >> 16),(char)((ex & 0XFF000000) >> 24), 0};
    Size S = Size((int) inputVideo.get(CAP_PROP_FRAME_WIDTH),    // Acquire input size
                  (int) inputVideo.get(CAP_PROP_FRAME_HEIGHT));
    VideoWriter outputVideo;                                        // Open the output
    if (askOutputType)
        outputVideo.open(NAME, ex=-1, inputVideo.get(CAP_PROP_FPS), S, true);
    else
        outputVideo.open(NAME, ex, inputVideo.get(CAP_PROP_FPS), S, true);
    if (!outputVideo.isOpened())
    {
        cout  << "Could not open the output video for write: " << source << endl;
        return -1;
    }
    cout << "Input frame resolution: Width=" << S.width << "  Height=" << S.height
         << " of nr#: " << inputVideo.get(CAP_PROP_FRAME_COUNT) << endl;
    cout << "Input codec type: " << EXT << endl;
    int channel = 2; // Select the channel to save
    switch(argv[2][0])
    {
    case 'R' : channel = 2; break;
    case 'G' : channel = 1; break;
    case 'B' : channel = 0; break;
    }
    Mat src, res;
    vector<Mat> spl;
    for(;;) //Show the image captured in the window and repeat
    {
        inputVideo >> src;              // read
        if (src.empty()) break;         // check if at end
        split(src, spl);                // process - extract only the correct channel
        for (int i =0; i < 3; ++i)
            if (i != channel)
                spl[i] = Mat::zeros(S, spl[0].type());
       merge(spl, res);
       //outputVideo.write(res); //save or
       outputVideo << res;
    }
    cout << "Finished writing" << endl;
    return 0;*/
    
    
    
    
    Size S = Size((int)500, (int)500);
    VideoWriter outputVideo;
    
    int ex = outputVideo.fourcc('H','2','6','4');
    //~ int ex = outputVideo.fourcc('X','V','I','D');
    //~ int ex = outputVideo.fourcc('a','v','c','1');
    
    outputVideo.open("test_video.avi", ex, 2, S, true);
	
	
	
    if (!outputVideo.isOpened())
    {
        cout  << "Could not open the output video for write. " << endl;
        return -1;
    }
    
    Mat rouge(500, 500, CV_8UC3, Scalar(0,0,255));
    Mat vert(500, 500, CV_8UC3, Scalar(0,255,0));
    
    
    for(int i = 0;i<20;i++)
    {
		//outputVideo.write(MAT); //save or
		outputVideo << rouge;
		outputVideo << vert;
	}
    
    
    cout << "Finished writing" << endl;
    return 0;
}
