#include <string>
#include <iostream>
#include <sstream>
using namespace std;
#pragma once

class TestCase {
    private:
        ostream& out;
        int passed, failed, testCount;
        string testName;
        
    public:
        TestCase(string S, ostream& O) : out(O), testName(S), passed(0), failed(0), testCount(0) {}
        template<class T>
        TestCase& check_equal(T const A, T const B);
        template<class T>
        TestCase& check_different(T const A, T const B);
        template<class T, class V>
        TestCase& check_function(V (*func)(T const), T const A, V const B);
        template<class T>
        TestCase& check_output(T const A, const string S);
        void print();
};

template<class T>
TestCase& TestCase::check_equal(T const A, T const B)
{
    testCount++;
    if(A == B) passed++;
    else{
        out << testName << ": Failure in test #" << testCount << ": " << A << " should equal " << B << "!" << endl;
        failed++;
    } 
    return *this;
}

template<class T>
TestCase& TestCase::check_different(T const A, T const B)
{
    testCount++;
    if(A != B) passed++;
    else{
        out << testName << ": Failure in test #" << testCount << ": " << A << " should differ from " << B << "!" << endl;
        failed++;
    }  
    return *this;
}

template<class T>
TestCase& TestCase::check_output(T const A, const string S)
{
    testCount++;
    ostringstream buf;
    buf << A;
    if(buf.str() == S) passed++;
    else{
        out << testName << ": Failure in test #" << testCount << ": string value should be " << S << " but is " << A << "!" << endl;
        failed++;
    } 
    return *this;
}

template<class T, class V>
TestCase& TestCase::check_function(V (*func)(T const), T const A, V const B)
{
    testCount++;
    if(func(A) == B) passed++;
    else{
        out << testName << ": Failure in test #" << testCount << ": function should return " << B << " but returned " << func(A) << "!" << endl;
        failed++;
    } 
    return *this;
}

