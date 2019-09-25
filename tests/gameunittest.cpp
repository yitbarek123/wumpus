/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_gametest_init = false;
#include "gameunittest.cxxtest"

static gametest suite_gametest;

static CxxTest::List Tests_gametest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_gametest( "gameunittest.cxxtest", 7, "gametest", suite_gametest, Tests_gametest );

static class TestDescription_suite_gametest_testgamefailled : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_gametest_testgamefailled() : CxxTest::RealTestDescription( Tests_gametest, suiteDescription_gametest, 12, "testgamefailled" ) {}
 void runTest() { suite_gametest.testgamefailled(); }
} testDescription_suite_gametest_testgamefailled;

static class TestDescription_suite_gametest_test_pit : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_gametest_test_pit() : CxxTest::RealTestDescription( Tests_gametest, suiteDescription_gametest, 16, "test_pit" ) {}
 void runTest() { suite_gametest.test_pit(); }
} testDescription_suite_gametest_test_pit;

static class TestDescription_suite_gametest_test_gold : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_gametest_test_gold() : CxxTest::RealTestDescription( Tests_gametest, suiteDescription_gametest, 21, "test_gold" ) {}
 void runTest() { suite_gametest.test_gold(); }
} testDescription_suite_gametest_test_gold;

static class TestDescription_suite_gametest_test_wumpus : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_gametest_test_wumpus() : CxxTest::RealTestDescription( Tests_gametest, suiteDescription_gametest, 26, "test_wumpus" ) {}
 void runTest() { suite_gametest.test_wumpus(); }
} testDescription_suite_gametest_test_wumpus;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
