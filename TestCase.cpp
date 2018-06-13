#include "TestCase.hpp"
using namespace std;

template<class T>
void TestCase::check_equal(T const A, T const B)
{
    testCount++;
    if(A == B) passed++;
    else{
        out << testName << ": Failure in test #" << testCount << ": " << A << " should equal " << B << "!" << endl;
        failed++;
    }  
}

template<class T>
void TestCase::check_different(T const A, T const B)
{
    testCount++;
    if(A != B) passed++;
    else{
        out << testName << ": Failure in test #" << testCount << ": " << A << " should differ from " << B << "!" << endl;
        failed++;
    }  
}

template<class T>
void TestCase::check_output(T const A, const string S)
{
    testCount++;
    ostringstream buf;
    buf << A;
    if(buf.str() == S) passed++;
    else{
        out << testName << ": Failure in test #" << testCount << ": string value should be " << S << " but is " << A << "!" << endl;
        failed++;
    } 
}

template<class T, class V>
void TestCase::check_function(V (*func)(T), T A, V B)
{
    testCount++;
    if(func(A) == B) passed++;
    else{
        out << testName << ": Failure in test #" << testCount << ": function should return " << B << " but returned " << func(A) << "!" << endl;
        failed++;
    } 
}

void TestCase::print()
{
    out << testName << ": " << failed << " failed, " << passed << " passed, " << testCount << " total." << endl;
}
