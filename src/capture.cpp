#include <iostream>
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <unistd.h>

int main()
{
  //!< In this variable the current frame is stored
  cv::Mat frame;
  
  cv::VideoCapture camera(1);
  if ( !camera.isOpened() )  
  {
    std::cout << "Cannot open the video file" << std::endl;
    return -1;
  }
  int KeyPressed=255; 
  int i=0;
  std::cout<<"Press esc if you want to stop the process"<<std::endl;
  std::cout<<"Press s to save snapshot"<<std::endl;
  while(1)
  {
    camera.grab();
    camera.retrieve(frame);
    imshow("Current",frame);
    KeyPressed=cvWaitKey(10) & 255; //!< wait for 'esc' key press for 10 ms
    while(KeyPressed==115) //!< KeyPressed==s
    {
     camera.grab();
     camera.retrieve(frame);
     imshow("Current",frame);
     cv::waitKey(10);

     char temp_name[50];
     sprintf(temp_name,"frame%d.jpg",i+1);
     cv::imwrite(temp_name,frame);
     std::cout<<"Image "<<temp_name<<" saved"<<std::endl;
     i++;
     usleep(500000);
    }
      
  }  
}
