For complete detail about the purpose of this repository and the functionalities I have tried to implement in it, please read both parts of the Readme file.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

PART A (General Highlights about the code)

The main code for the 1D Histogram Generator is in the file "OneD_HistogramGenerator.cpp".

The code best runs on an IDE such as VS Code wherein it prompts the user for inputs in order to take arguments.

Details about Unit Testing of the code:-
1. I have performed unit testing for all functions in the Data and Reader class.
2. The header file used in both the cases is the same named "UnitTestHeader.h".
3. Since Data class has two classes Vector and FourVector classes, I have made separate files named "Data_VectorClass_UnitTest.cpp" and "Data_FourVectorClass_UnitTest.cpp".
4. Reader class has only one function 'Readfile' within it which requires a .txt file to function. Hence, I have made a .txt file named "Reader_test.txt" to perform unit testing.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

PART B (Detailed Description of the work done)

In this repository, I have tried to perform the following task based on the dataset:

Write a C++ code using the attached data file. In this file, each data line is a four-vector where the first three columns are the momentum vector's x,y, and z directions, and the last is energy. All data is given in the units of MeV. The code should contain a reader, a data class and an output system.

 - The reader class should be able to read the data file, and prepare the appropriate data class.
 - The data class should have two layers. The first layer is the vector which takes x,y, and z input. This vector class should be able to compute basic vector operations, such as extracting the transverse axis or calculating the angle between two axes depending on the requested output. The second layer is the FourVector class which should inherit the vector class and include additional capabilities. For instance, the FourVector class can access the energy to compute the associated mass when the vector represents the four-momentum of a particle.
 -  The output system should generate 1D histogram data for a given distribution. The histogram's x-axis corresponds to the bins of the requested distribution, and the y-axis is the probability of each bin. The output should be a two-column text file that one can use to draw a histogram later on, where the first column is the x-axis and the second column is the y-axis of the histogram. 
 - The main program should be able to take the following arguments: the data file location, the distribution name, the number of bins of the requested histogram, the minimum value for the x-axis, and the maximum value for the x-axis. The code should be able to output distributions in the variables pT, pX, pY, pZ, energy, and mass. If users require any other distribution, the programme should not crash but return an error message saying that the requested distribution is unavailable. The output should be scaled to the appropriate units.

It is essential that the code is designed with extensive documentation within the code. Moreover, it should be designed so that it is easy to extend it. For instance, when users want to add a new function to the four-vector class, it should take almost no effort to implement it and to get a histogram. Additionally, the code should be uploaded to GitHub with an appropriate unit test and workflow.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------


                                                                             


