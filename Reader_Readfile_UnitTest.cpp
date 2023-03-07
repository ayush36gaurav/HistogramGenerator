#include<bits/stdc++.h>
#include <string>
#include <fstream>
# include "UnitTestHeader.h"
using namespace std;

void test_Readfile(vector <FourVector> expected, vector <FourVector> actual, string testName)
{
    if ((expected[0].x == actual[0].x) && (expected[0].y == actual[0].y) && (expected[0].z == actual[0].z) && (expected[0].energy == actual[0].energy))
    {
        cout<<testName<<" PASSED! "<<endl;
    }
    else
    {
        cout<<testName<<" FAILED!!!"<<endl;
    }
}

void test_Readfile_function()
{
    vector <FourVector> expected;
    Reader actual;
    FourVector expected_tuple;
    expected_tuple.setFourVectorData(1,2,3,4);
    expected.push_back(expected_tuple);
    actual.Readfile("Reader_test.txt");
    test_Readfile(expected,actual.Data_tuples,"Readfile Function Test");
}

int main()
{
    test_Readfile_function();
    return 0;
}