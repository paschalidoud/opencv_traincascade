Opencv Traincascade
===================

1. Create a list of positive images:

**find data/Positive_Images -iname "*.jpg" > positives.txt**

2. Create a list of negative images:

**find data/Negative_Images -iname "*.jpg" > negatives.txt** 

**Create samples first way**
                                          
3. Create positive samples with the bin/createsamples.pl script and save them to the ./samples folder:

**perl bin/createsamples.pl positives.txt negatives.txt samples 1000 "opencv_createsamples -bgcolor 0 -bgthresh 0 -maxxangle 1.1 -maxyangle 1.1 maxzangle 0.5 -maxidev 40 -w 80 -h 40"**   

***Pay attention to the number of created samples!!!***

4. Use the compiled executable mergevec to merge the samples in ./samples into one file:

**find ./samples -name '*.vec' > samples.txt**

**./mergevec samples.txt samples.vec**

***Create samples second way***

3. Compile and run **rectangle.cpp** to create positives.dat

4. Create positive samples with opencv_createsamples

**./opencv_createsamples -info positives.dat -vec positives.vec -bg negatives.txt -num 1000 -bgcolor 0 -bgthresh 0 -maxxangle 1.1 -maxyangle 1.1 maxzangle 0.5 -maxidev 40 -w 80 -h 40**

***Pay attention to the number of created samples!!!***

5. Start training the classifier with opencv_traincascade, which comes with OpenCV, and save the results to ./classifier:

**./opencv_traincascade -data classifier -vec samples.vec -bg negatives.txt -numStages 20 -minHitRate 0.999 -maxFalseAlarmRate 0.5 -numPos 227 -numNeg 3019 -w 80 -h 40 -mode ALL -precalcValBufSize 1024 -precalcIdxBufSize 1024**
          

***Notes:***

***1. Compile mergevec.cpp***

cp src/mergevec.cpp ~/opencv-2.4.6.1/apps/haartraining

cd ~/opencv-2.4.6.1/apps/haartraining

g++ `pkg-config --libs --cflags opencv` -I. -o mergevec mergevec.cpp cvboost.cpp cvcommon.cpp cvsamples.cpp cvhaarclassifier.cpp cvhaartraining.cpp -lopencv_core -lopencv_calib3d -lopencv_imgproc -lopencv_highgui -lopencv_objdetect
               
mv mergevec ~/folder of opencv_traincascade
