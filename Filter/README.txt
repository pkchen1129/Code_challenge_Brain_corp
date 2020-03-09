Command instructions:
1.The command for running the makefile should be: “make” and then “./run”. You could "make clean" to clean up the .o files.
2.The inputs when running the code are as following:
 - Whether generated numbers automatically or not?: (y or n)
  If yes, it'll generate the number automatically, however since it's too big, it won't be printed. 
  If no, it'll be printed and you have to enter the number N, D, T.
   (i) Input Dimension: (N) You could try an integer under 10 that it'll be easier to see
   (ii) Window size: (D)     
   (iii) Number of Iteration: T (time length)
          (N, D, and T could be created randomly for that I've implemented the random generator)




Description:
1. The folder contains main.cpp and Filter.hpp. Filter.hpp contains the #define, the #includes, and the class structure of range filter and temporal median filter. 

2. For printing format, I printed the range filter first, and temporal median filter. It contains Time, Input, and Output. 

3. I checked for the correctness at last and will be printed as Success when it is correct.

4. For range filter, I simply use the condition to decide whether it is out of bound and replace with the maximum or the minimum. As for the temporal median filter, I created a class structure and use vectors to store the sensor data. Every time when gaining new data, I'll first sort the vector and find the median of it. 