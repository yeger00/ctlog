#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <sstream>
#include "catch.hpp"
#include "ctlog.h"

// Example function that to show the usage of log in a give T level.
template <typename T>
void test_function(std::stringstream& sstream) {
        CTLog<T> ctlog(sstream);
        ctlog.debug << "debug";
        ctlog.info<< "info";
        ctlog.warning << "warning";
        ctlog.error << "error";
}

TEST_CASE( "debug log", "[ctlog]" ) {
        std::stringstream sstream;
	test_function<DebugLogLevel>(sstream);
	REQUIRE( sstream.str() == "debug" "info" "warning" "error" );
}

TEST_CASE( "info log", "[ctlog]" ) {
        std::stringstream sstream;
	test_function<InfoLogLevel>(sstream);
	REQUIRE( sstream.str() == "info" "warning" "error" );
}

TEST_CASE( "warning log", "[ctlog]" ) {
        std::stringstream sstream;
	test_function<WarningLogLevel>(sstream);
	REQUIRE( sstream.str() == "warning" "error" );
}

TEST_CASE( "error log", "[ctlog]" ) {
        std::stringstream sstream;
	test_function<ErrorLogLevel>(sstream);
	REQUIRE( sstream.str() == "error" );
}
