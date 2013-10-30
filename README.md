opencv_traincascade
===================
1.Put your positive images in the `./Positive_images` folder and create a list
of them:

find Positive_Images -iname "*.jpg" > positives.txt

2. Put the negative images in the `./Negative_images` folder and create a list of them:

find Negative_Images -iname "*.jpg" > negatives.txt 

/***create samples first way*****
3. Create positive samples with the `bin/createsamples.pl` script and save them to the `./samples` folder:

perl bin/createsamples.pl positives.txt negatives.txt samples 1000 "opencv_createsamples -bgcolor 0 -bgthresh 0 -maxxangle 1.1 -maxyangle 1.1 maxzangle 0.5 -maxidev 40 -w 80 -h 40"   
!!!Pay attention to the number of created samples!!!

4. Use the compiled executable `mergevec` to merge the samples in `./samples` into one file:

find ./samples -name '*.vec' > samples.txt
./mergevec samples.txt samples.vec


5. Start training the classifier with `opencv_traincascade`, which comes with OpenCV, and save the results to `./classifier`:

opencv_traincascade -data classifier -vec samples.vec -bg negatives.txt -numStages 20 -minHitRate 0.999 -maxFalseAlarmRate 0.5 -numPos 227 -numNeg 3019 -w 80 -h 40 -mode ALL -precalcValBufSize 1024 -precalcIdxBufSize 1024
          

Notes:
1.Install OpenCV & get OpenCV source in ubuntu
a.Download opencv-2.4.6.1 from http://sourceforge.net/projects/opencvlibrary/ and extract files in your desired installation directory
b.Follow the commands below
 mkdir build
 cd build
 make
 sudo make install
 

2.How compile mergevec.cpp
cp src/mergevec.cpp ~/opencv-2.4.6.1/apps/haartraining
cd ~/opencv-2.4.6.1/apps/haartraining
g++ `pkg-config --libs --cflags opencv` -I. -o mergevec mergevec.cpp cvboost.cpp cvcommon.cpp cvsamples.cpp cvhaarclassifier.cpp cvhaartraining.cpp -lopencv_core -lopencv_calib3d -lopencv_imgproc -lopencv_highgui -lopencv_objdetect
               
        
