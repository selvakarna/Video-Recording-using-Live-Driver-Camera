/*
 * test.h
 *
 *  Created on: 03-Nov-2022
 *      Author: selva
 */

#ifndef CAMEOPEN_H_
#define CAMEOPEN_H_
#include <iostream>
#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <time.h>

// void test_print(void int argc, char** argv)
int fchnl;
int realTimeValues;
FILE * pFileTXT; 
int Cameopen(char** cam) {
    int ret;
    // if ( argc != 2 ) {
    // printf("no args\n");
    // return -1;
    // }
    cv::Mat frame;
    cv::VideoCapture cap;
    //cap.open(argv[1]);
    cap.open(cam[1]);
    if (!cap.isOpened()) {
        printf("ERROR! Unable to open camera\n");
        return -1;
    }
    cv::Mat output(350,350,CV_8UC1);
   
  
    // cout<<"aver:"<<cap.cv::CAP_PROP_FPS<<endl;
   
    FILE * fp;
    while(true){
        cap.read(frame); 
        // Frame Channel
        
        double rgbchnl=frame.channels();
        if(3==rgbchnl){
           std::cout << "The live stream frame Channel is Equal:.........." << rgbchnl << std::endl;
           fchnl=rgbchnl;
           realTimeValues=rgbchnl;

        }
        
        else if(3!=rgbchnl){
            std::cout << "The live stream frame Channel is Not Equal to RGB :.........." << rgbchnl << std::endl;
        }
        else{
            std::cout << "The live stream frame Channel is Missing :.........." << "Channel Missing" << std::endl;
        }
           // // Frame FPS
        double fps2 = cap.get(cv::CAP_PROP_FPS);
        std::cout << "The fps from live stream............ : " << fps2 << std::endl;
        if(60==fps2){
            std::cout <<"The Live fps stream is Equal to 60"<<fps2<<std::endl;
        }
        else if(60!=fps2){
            std::cout <<"The Live fps stream is Not Equal to 60fps......"<<fps2<<std::endl;
        }
        else{
           std::cout << "The live stream frame FPS is missing:.........." << "FPS Missing" << std::endl; 
        }
        ret=fps2;      
        // Frame Width
        double frmwidt = cap.get(cv::CAP_PROP_FRAME_WIDTH);
        std::cout << "frame width :.........." << frmwidt << std::endl;
        if(1920==frmwidt){
            std::cout << "The live stream frame width is Equal:.........." << frmwidt << std::endl;
        }
        else if(1920!=frmwidt){
            std::cout << "The live stream frame width is Not Equal to 1920 :.........." << frmwidt << std::endl;
        }
        else {
           std::cout << "The live stream frame width is missing:.........." << "Width Missing" << std::endl;

        }
        // Frame Height
        double frmheiht = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
        std::cout << "frame height :........." << frmheiht << std::endl;
        
        if(1080==frmheiht){
            std::cout << "The live stream frame height is Equal:.........." << frmheiht << std::endl;
        }
        
        else if(1080!=frmheiht){
            std::cout << "The live stream frame height is Not Equal to 1080 :.........." << frmheiht << std::endl;
        }
        else {
            std::cout << "The live stream frame height is missing:.........." << "Height Missing" << std::endl;

        }

           

            /* open the file for writing*/
        fp = fopen("TIME.txt","w");
        
        /* write time as text into the file stream*/
        char cur_time[128];
        
        time_t      t;
        struct tm*  ptm;
        
        t = time(NULL);
        ptm = localtime(&t);
        
        strftime(cur_time, 128, "%Y-%m-%d %H:%M:%S", ptm);
        
        //fprintf(fp, "%s\n", cur_time);
        fprintf(fp, "The Channel is %d\n", fchnl);
        fprintf(fp, "The Current time  is %s\n",cur_time);
        
        /* close the file*/  
        fclose(fp);

        pFileTXT = fopen ("realTimeData.txt","a"); // Opening file in append mode
        fprintf (pFileTXT, "Video Channel %d\n",realTimeValues);   // saving values to file
        fprintf (pFileTXT, "Current Time %s\n",cur_time);
        fprintf (pFileTXT, "Video  Frame Widht %d\n",int(frmwidt));
        fprintf (pFileTXT, "Video  Frame Height %d\n",int(frmheiht));
       
        fclose (pFileTXT) ; 
    
        // // Frame FPS
        // double fps2 = cap.get(cv::CAP_PROP_FPS);
        // std::cout << "The fps from live stream............ : " << fps2 << std::endl;
        // if(60==fps2){
        //     std::cout <<"The Live fps stream is Equal to 60"<<fps2<<std::endl;
        // }
        // else if(60!=fps2){
        //     std::cout <<"The Live fps stream is Not Equal to 60fps......"<<fps2<<std::endl;
        // }
        // else{
        //    std::cout << "The live stream frame FPS is missing:.........." << "FPS Missing" << std::endl; 
        // }
        // ret=fps2;
        // // Frame Width
        // double frmwidt = cap.get(cv::CAP_PROP_FRAME_WIDTH);
        // std::cout << "frame width :.........." << frmwidt << std::endl;
        // if(1920==frmwidt){
        //     std::cout << "The live stream frame width is Equal:.........." << frmwidt << std::endl;
        // }
        // else if(1920!=frmwidt){
        //     std::cout << "The live stream frame width is Not Equal to 1920 :.........." << frmwidt << std::endl;
        // }
        // else {
        //    std::cout << "The live stream frame width is missing:.........." << "Width Missing" << std::endl;

        // }
        // // Frame Height
        // double frmheiht = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
        // std::cout << "frame height :........." << frmheiht << std::endl;
        
        // if(1080==frmheiht){
        //     std::cout << "The live stream frame height is Equal:.........." << frmheiht << std::endl;
        // }
        
        // else if(1080!=frmheiht){
        //     std::cout << "The live stream frame height is Not Equal to 1080 :.........." << frmheiht << std::endl;
        // }
        // else {
        //     std::cout << "The live stream frame height is missing:.........." << "Height Missing" << std::endl;

        // }

        
       // // double framsize =frame.size;
       // // std::cout << "frame Size :........." << frame.size()<< std::endl;

       // // std::cout << "frame Channels :........." << frame.channels()<< std::endl;
    }
    
    


}




#endif /* TEST_H_ */
