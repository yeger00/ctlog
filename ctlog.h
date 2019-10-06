#ifndef __CTLOG_H__
#define __CTLOG_H__

#include <iostream>
#include <type_traits>

// Define the different log levels
enum LogLevelEnum {
	DebugLogLevelEnum = 1,
	InfoLogLevelEnum = 2,
	WarningLogLevelEnum = 3,
	ErrorLogLevelEnum = 4,
};

typedef std::integral_constant<int, DebugLogLevelEnum> DebugLogLevel;
typedef std::integral_constant<int, InfoLogLevelEnum> InfoLogLevel;
typedef std::integral_constant<int, WarningLogLevelEnum> WarningLogLevel;
typedef std::integral_constant<int, ErrorLogLevelEnum> ErrorLogLevel;

// Compile time log.
template<typename T>
struct CTLog {
	template<typename L>
	
	// Inner struct that defines the operator << for a specific log level 
	// in compile time.
	struct CTLogLevel {
		// operator << (and its overloads) in case the log level is higher.
		template<typename Q, typename U = L>
		typename std::enable_if< U::value >= T::value, CTLogLevel<U> >::type&
		operator << (const Q& x) {
			std::cout << x;
  			return *this;
		}

		template<typename U = L>
		typename std::enable_if< U::value >= T::value, CTLogLevel<U> >::type&
		operator << (std::ostream& (*f)(std::ostream &)) {
			f(std::cout);
  			return *this;
		}

		template<typename U = L>
		typename std::enable_if< U::value >= T::value, CTLogLevel<U> >::type&
		operator << (std::ostream& (*f)(std::ios &)) {
			f(std::cout);
  			return *this;
		}

		template<typename U = L>
		typename std::enable_if< U::value >= T::value, CTLogLevel<U> >::type&
		operator << (std::ostream& (*f)(std::ios_base &)) {
			f(std::cout);
  			return *this;
		}
	
		// operator << (and its overloads) in case the log level is lower.
		// These should be removed in compile time.
		template<typename Q, typename U = L>
		typename std::enable_if< not (U::value >= T::value), CTLogLevel<U> >::type&
		operator << (const Q& x) {
  			return *this;
		}
		
		template<typename U = L>
		typename std::enable_if< not (U::value >= T::value), CTLogLevel<U> >::type&
		operator << (std::ostream& (*f)(std::ostream &)) {
  			return *this;
		}

		template<typename U = L>
		typename std::enable_if< not (U::value >= T::value), CTLogLevel<U> >::type&
		operator << (std::ostream& (*f)(std::ios &)) {
  			return *this;
		}

		template<typename U = L>
		typename std::enable_if< not (U::value >= T::value), CTLogLevel<U> >::type&
		operator << (std::ostream& (*f)(std::ios_base &)) {
  			return *this;
		}
	};

	// The specific logs members.
	CTLogLevel<DebugLogLevel> debug;
	CTLogLevel<InfoLogLevel> info;
	CTLogLevel<WarningLogLevel> warning;
	CTLogLevel<ErrorLogLevel> error;
};

#endif // __CTLOG_H__
