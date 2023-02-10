#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;
int main(int argc, char** argv){
//

    
    char** fac;
    int ret;
    
    if ( argc != 2 ) {
    printf("no args\n");
    return -1;
    }
    
    fac=argv;
    cv::Mat frame;
    cv::VideoCapture cap;
    //cap.open(argv[1]);
    cap.open(fac[1]);
    if (!cap.isOpened()) {
        printf("ERROR! Unable to open camera\n");
        return -1;
    }

  // Create a VideoCapture object and use camera to capture the video
  //VideoCapture cap(0);
  cap.set(CAP_PROP_FRAME_WIDTH, 1920);//Setting the width of the video
    cap.set(CAP_PROP_FRAME_HEIGHT, 1080);//Setting the height of the video//
  // Check if camera opened successfully
  if(!cap.isOpened()){
   	cout << "Error opening video stream" << endl;
        return -1;
  }

  // Default resolutions of the frame are obtained.The default resolutions are system dependent.
//  int frame_width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
//  int frame_height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
  int frame_width = 1920;
  int frame_height =1080;

  // Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file.
  VideoWriter video("video_1.mp4", cv::VideoWriter::fourcc('M','J','P','G'), 60, Size(frame_width,frame_height));

//  while(1)
  //for(int i=0; i<120;i++) //300
  for(;;)
  {

    Mat frame;

    // Capture frame-by-frame
    cap.read (frame);

    // If the frame is empty, break immediately
    if (frame.empty())
      break;

    // Write the frame into the file 'outcpp.avi'

    resize(frame, frame, Size(1920, 1080), INTER_LINEAR);
    video.write(frame);

    // Display the resulting frame
  //  imshow( "Frame", frame );

  //   // Press  ESC on keyboard to  exit
  //  char c = (char)waitKey(1);
  //  if( c == 27 )
  //    break;
  }

  // When everything done, release the video capture and write object
  cap.release();
  video.release();

  // Closes all the frames
  destroyAllWindows();
  return 0;
}





