/* Name: Ayush Gaurav
   E-mail: b21183@students.iitmandi.ac.in
   Institute: IIT Mandi, India */

/* Breif Overview of the Implementation
The code best runs on an IDE such as VS Code wherein it prompts the use for inputs in order to take arguments.
1. Since the problem statement asks to create a Data class so, I have created a data class which has no members and from it the Vector class is 
inherited. The FourVector class is further derived from the vector class
2. I have created a Reader class which reads and sets the data as an array (vector) whose elements belong to the FourVectoe class
3. I have created a function to serve as the output system
4. The main fmunction first takes the input and the performs further actions
*/


// Imperting header file and specifying namespace
#include<bits/stdc++.h>
#include <math.h>
#include <fstream>
using namespace std;


// Creating class Data from which vector class is inherited
class Data
{  

};

// Creating Vector class which is derived from Data class
class Vector : public Data
{   
    public:
        float x, y, z;

        // Function to set values of x , y and z
        void setVectorData(float a, float b, float c)
        {
            x = a; 
            y = b; 
            z = c;
        }

        // Function which calculates and return the transverse axis of two vectors as a vector
        Vector Transverse_axis(Vector p, Vector q)
        {
            Vector trans_axis;
            trans_axis.x = p.y * q.z - p.z * q.y;
            trans_axis.y = p.z * q.x - p.x * q.z;
            trans_axis.z = p.x * q.y - p.y * q.x;
            return trans_axis;
        }

        // Function which returns the angle between two vectors in radians
        float Angle_btw_axis(Vector p, Vector q)
        {
            float dot_product = p.x * q.x + p.y * q.y + p.z * q.z;
            float value = dot_product/((sqrt(pow(p.x,2) + pow(p.y,2) + pow(p.z,2))) * (sqrt(pow(q.x,2) + pow(q.y,2) + pow(q.z,2))));
            return acos(value);
        }
};

// Creating FourVectror class derived from vector class
class FourVector : public Vector
{
    public: 
        float energy;
        // Function to set the values for the FourVector class
        void setFourVectorData(float a, float b, float c, float d)
        {   
            setVectorData(a,b,c);
            energy = d;
        }

        // Function to calculate mass given the momentum and energy
        float mass(FourVector p)
        {
            float p_square = pow((p.x),2) + pow((p.y),2) + pow((p.z),2);
            return (p_square/(2*p.energy));
        }

        // Function to calculate the total momentum as it is required for distribution of Pt
        float p_total(FourVector p)
        {
            return(sqrt(pow(p.x,2) + pow(p.y,2) + pow(p.z,2)));
        }
};

// Class to read the data and sets the data using the classes formed above
class Reader
{
    public:
        // All the data in the input file is stored in a vector
        vector <FourVector> Data_tuples;

        // Function which given the path of the file sets the data 
        void Readfile(string path)
        {
            ifstream file;
            file.open(path); 

            float data;
            float Px, Py, Pz, E;

            file >> data;
            Px = data;
            file >> data;
            Py = data;
            file >> data;
            Pz = data;
            file >> data;
            E = data; 

            // Setting one row in the input data as an object of FourVector class and further storing it in the array (vector)
            FourVector tuple;
            tuple.setFourVectorData(Px,Py,Pz,E);
            Data_tuples.push_back(tuple);
            
            // Continuing the above process untill the entire file is processed
            while(Pz != E)
            {

                file >> data;
                Px = data;
                file >> data;
                Py = data;
                file >> data;
                Pz = data;
                file >> data;
                E = data; 
                tuple.setFourVectorData(Px,Py,Pz,E);
                Data_tuples.push_back(tuple);          
            }
        }
};

// Function to generate the required output text file based on arguments given
void Output_system(vector<FourVector> input_data, string distribution, int no_of_bins, int min_value, int max_value )
{
    // Calculte the bin size
    float bin_size;
    bin_size = (max_value-min_value)/(no_of_bins);

    // Find number of samples or data points in the input file
    int no_of_samples = input_data.size();

    // Initialize an array which stores the values on y-axis i.e. probabilities (initially all are set to zero)
    float probability[no_of_bins] = {0};

    /* Initialize an array which stores the values on x-axis i.e. bins. The first probability in the array above (probablity) corresponds to the 
       bin from minimum value to first value stored in the array */
    int bins[no_of_bins];

    // Check for the distribution required and generate the corresponding distribution
    if (distribution == "pX" || distribution == "Px" || distribution == "PX")
    {   
        // Run a loop through the input data stored in a vector and count the number of times values fall in a particular bin
        for (int i = 0; i<input_data.size(); i++)
        {
            // Check for all bins whether the value for given sample falls in its range
            for (int j = 0; j<no_of_bins; j++)
            {
                // Increase the count if a value falls in the range of a particular bin
                if (((min_value+j*bin_size) <= input_data[i].x) && (input_data[i].x < (min_value+(j+1)*bin_size)))
                {
                    probability[j]++;
                }
            }      
        }
    }

    // Repeat the above process for each distribution asked after checking the requirement of a particular distribution
    // For Py
    // Check for the distribution required and generate the corresponding distribution
    else if (distribution == "pY" || distribution == "Py" || distribution == "PY")
    {
        // Run a loop through the input data stored in a vector and count the number of times values fall in a particular bin
        for (int i = 0; i<input_data.size(); i++)
        {
            // Check for all bins whether the value for given sample falls in its range
            for (int j = 0; j<no_of_bins; j++)
            {
                // Increase the count if a value falls in the range of a particular bin
                if (((min_value+j*bin_size) <= input_data[i].y) && (input_data[i].y < (min_value+(j+1)*bin_size)))
                {
                    probability[j]++;
                }
            }      
        }
    }

    // For Pz
    // Check for the distribution required and generate the corresponding distribution
    else if (distribution == "pZ" || distribution == "Pz" || distribution == "PZ")
    {
        // Run a loop through the input data stored in a vector and count the number of times values fall in a particular bin
        for (int i = 0; i<input_data.size(); i++)
        {
            // Check for all bins whether the value for given sample falls in its range
            for (int j = 0; j<no_of_bins; j++)
            {
                // Increase the count if a value falls in the range of a particular bin
                if (((min_value+j*bin_size) <= input_data[i].z) && (input_data[i].z < (min_value+(j+1)*bin_size)))
                {
                    probability[j]++;
                }
            }      
        }
    }

    // For Pt
    // Check for the distribution required and generate the corresponding distribution
    else if (distribution == "pT" || distribution == "Pt" || distribution == "PT")
    {
        // Run a loop through the input data stored in a vector and count the number of times values fall in a particular bin
        for (int i = 0; i<input_data.size(); i++)
        {
            // Check for all bins whether the value for given sample falls in its range
            for (int j = 0; j<no_of_bins; j++)
            {
                // Increase the count if a value falls in the range of a particular bin
                if (((min_value+j*bin_size) <= input_data[i].p_total(input_data[i])) && (input_data[i].p_total(input_data[i]) < (min_value+(j+1)*bin_size)))
                {
                    probability[j]++;
                }
            }      
        }
    }

    // For energy
    // Check for the distribution required and generate the corresponding distribution
    else if (distribution == "energy" || distribution == "Energy")
    {
        // Run a loop through the input data stored in a vector and count the number of times values fall in a particular bin
        for (int i = 0; i<input_data.size(); i++)
        {
            // Check for all bins whether the value for given sample falls in its range
            for (int j = 0; j<no_of_bins; j++)
            {
                // Increase the count if a value falls in the range of a particular bin
                if (((min_value+j*bin_size) <= input_data[i].energy) && (input_data[i].energy < (min_value+(j+1)*bin_size)))
                {
                    probability[j]++;
                }
            }      
        }
    }

    // For mass
    // Check for the distribution required and generate the corresponding distribution
    else if (distribution == "mass" || distribution == "Mass")
    {
        // Run a loop through the input data stored in a vector and count the number of times values fall in a particular bin
        for (int i = 0; i<input_data.size(); i++)
        {
            // Check for all bins whether the value for given sample falls in its range
            for (int j = 0; j<no_of_bins; j++)
            {
                // Increase the count if a value falls in the range of a particular bin
                if (((min_value+j*bin_size) <= input_data[i].mass(input_data[i])) && (input_data[i].mass(input_data[i]) < (min_value+(j+1)*bin_size)))
                {
                    probability[j]++;
                }
            }      
        }
    }

    // If any other distribution is required by the user, output the appropriate message
    else
    {
        cout<<"Requested distribution is unavailable."<<endl;
    }


    // Set the value for the bins in the array storing it and compute the probability for each bin from the count generate above for each bin
    for (int k=0; k<no_of_bins; k++)
    {
        // Compute the value for the bins
        bins[k] = min_value + (k+1) * (bin_size);
        // Find the probability for the corresponding bin from the count
        probability[k] = probability[k]/no_of_samples;
    }
    
    // Make a .txt file to write the output in it
    ofstream OutputFile("histogram.txt");
    // Lopp through the values and write it in the output file 
    for (int l = 0; l<no_of_bins; l++)
    {
        OutputFile<<bins[l]<<"     "<<probability[l]<<endl;
    }
    // Close the file
    OutputFile.close();
}

int main()
{
    // Make variables for the required argumemts
    string datafile, distribution_name;
    int number_of_bins, min_x_axes, max_x_axes;

    // Prompt and take input from the user
    cout<<"Enter the file path: "<<endl;
    cin>>datafile;
    cout<<"Enter the distribution name: "<<endl;
    cin>>distribution_name;
    cout<<"Enter the number of bins: "<<endl;
    cin>>number_of_bins;
    cout<<"Enter the minimum value for the x-axis: "<<endl;
    cin>>min_x_axes;
    cout<<"Enter the maximum value for x-axis: "<<endl;
    cin>>max_x_axes;

    // Create a reader class object and read the input data into it
    Reader R1;
    R1.Readfile(datafile);
    
    // Call the output function and write the corresponding output file for the given set of input arguments
    Output_system(R1.Data_tuples,distribution_name,number_of_bins,min_x_axes,max_x_axes);

    return 0;
}


/*
Details about Unit Testing of the code:-
1. I have performed unit testing for all functions in the Data and Reader class
2. The header file used in both the cases is the same named "UnitTestHeader.h"
3. Since Data class has two classes Vector and FourVector classes, I have made separate files named "Data_VectorClass_UnitTest.cpp" and "Data_FourVectorClass_UnitTest.cpp"
4. Reader class has only one function 'Readfile' within it which requires a .txt file to function. Hence, I have made a .txt file named "Reader_test.txt" to perform unit
testing
*/