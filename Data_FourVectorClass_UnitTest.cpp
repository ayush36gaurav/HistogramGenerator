#include<bits/stdc++.h>
# include <string>
#include <math.h>
#include "UnitTestHeader.h"
using namespace std;

void test_setFourVectorData(float *expected_arr, float *actual_arr, string testName)
{
    if ((expected_arr[0] == actual_arr[0]) && (expected_arr[1] == actual_arr[1]) && (expected_arr[2] == actual_arr[2]) && (expected_arr[3] == actual_arr[3]))
    {
        cout<<testName<<" PASSED! "<<endl;
    }
    else
    {
        cout<<testName<<" FAILED!!!"<<endl;
    }
}

void test_mass_or_p_total(float expected, float actual, string testName)
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

void test_setFourVectorData_function()
{
    FourVector v;
    v.setFourVectorData(1,2,3,4);
    float expected_array[4] = {1,2,3,4};
    float actual_array[4] = {v.x,v.y,v.z,v.energy};
    test_setFourVectorData(expected_array,actual_array, "SetFourVectorData Function Test");
}

void test_mass_function()
{
    FourVector tuple;
    tuple.setFourVectorData(0,0,0,10);
    test_mass_or_p_total(0,tuple.mass(tuple),"mass Function Test");
}

void test_p_total()
{
    FourVector tuple;
    tuple.setFourVectorData(0,6,8,20);
    test_mass_or_p_total(10,tuple.p_total(tuple),"p_total Function Test");
}

int main()
{
    test_setFourVectorData_function();
    test_mass_function();
    test_p_total();
    return 0;
}