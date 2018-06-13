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
        void check_equal(T const A, T const B);
        template<class T>
        void check_different(T const A, T const B);
        template<class T, class V>
        void check_function(V (*func)(T const), T const A, V const B);
        template<class T>
        void check_output(T const A, const string S);
        void print();
};
