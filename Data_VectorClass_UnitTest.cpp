#include<bits/stdc++.h>
# include <string>
#include <math.h>
#include "DataClass.h"
using namespace std;

void test_setVectorData(float *expected_arr, float *actual_arr, string testName)
{
    if ((expected_arr[0] == actual_arr[0]) && (expected_arr[1] == actual_arr[1]) && (expected_arr[2] == actual_arr[2]))
    {
        cout<<testName<<" PASSED! "<<endl;
    }
    else
    {
        cout<<testName<<" FAILED!!!"<<endl;
    }
}

void test_Transverse_axis(Vector expected, Vector actual, string testName)
{
    if ((expected.x == actual.x) && (expected.y== actual.y) && (expected.z == actual.z))
    {
        cout<<testName<<" PASSED! "<<endl;
    }
    else
    {
        cout<<testName<<" FAILED!!!"<<endl;
    }
}

void test_Angle_btw_axis(float expected, float actual, string testName)
{
    if (expected == actual)
    {
        cout<<testName<<" PASSED! "<<endl;
    }
    else
    {
        cout<<testName<<" FAILED!!!"<<endl;
    }
}

void test_setVectorData_function()
{
    Vector v;
    v.setVectorData(1,2,3);
    float expected_array[3] = {1,2,3};
    float actual_array[3] = {v.x,v.y,v.z};
    test_setVectorData(expected_array,actual_array, "SetVectorData Function Test");
}

void test_Transverse_axis()
{
    Vector tuple1, tuple2, expected;
    tuple1.setVectorData(1,2,3);
    tuple2.setVectorData(1,2,3);
    expected.setVectorData(0,0,0);
    test_Transverse_axis(expected,tuple1.Transverse_axis(tuple1,tuple2), "Transverse_axis Function Test");
}

void test_Angle_btw_axis_function()
{
    Vector tuple1, tuple2;
    tuple1.setVectorData(10,-13,30);
    tuple2.setVectorData(5,-26,15);
    float expected = acos((5*10+13*26+30*15)/((sqrt(pow(10,2) + pow(-13,2) + pow(30,2))) * (sqrt(pow(5,2) + pow(-26,2) + pow(15,2)))));
    test_Angle_btw_axis(expected, tuple1.Angle_btw_axis(tuple1,tuple2), "Angle between Axis Function Test");
     
}

int main()
{
    test_setVectorData_function();
    test_Transverse_axis();
    test_Angle_btw_axis_function();
    return 0;
}