#include <iostream>
#include "ctlog.h"

// Example function that to show the usage of log in a give T level.
template <typename T>
void test_function() {
	std::cout << "Starting log level: " << T::value << std::endl;
	CTLog<T> ctlog;
	ctlog.debug << "debug" << std::endl;
	ctlog.info<< "info" << std::endl;
	ctlog.warning << "warning" << std::endl;
	ctlog.error << "error" << std::endl;
	std::cout << "----" << std::endl;
}

int main() {
    test_function<DebugLogLevel>();
    test_function<InfoLogLevel>();
    test_function<WarningLogLevel>();
    test_function<ErrorLogLevel>();
}

