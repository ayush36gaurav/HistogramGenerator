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