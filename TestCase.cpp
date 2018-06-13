#include "TestCase.hpp"
using namespace std;

void TestCase::print()
{
    out << testName << ": " << failed << " failed, " << passed << " passed, " << testCount << " total." << endl << "---" << endl;
}
