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
	// C'tor
	CTLog(std::ostream& stream) :
		debug(stream),
		info(stream),
		warning(stream),
		error(stream) { }
	
	// Inner struct that defines the operator << for a specific log level 
	// in compile time.
	template<typename L>
	struct CTLogLevel {
		// C'tor
		CTLogLevel(std::ostream& stream) : stream_(stream) { }

		// operator << (and its overloads) in case the log level is higher.
		template<typename Q, typename U = L>
		typename std::enable_if< U::value >= T::value, CTLogLevel<U> >::type&
		operator << (const Q& x) {
			stream_ << x;
  			return *this;
		}

		template<typename U = L>
		typename std::enable_if< U::value >= T::value, CTLogLevel<U> >::type&
		operator << (std::ostream& (*f)(std::ostream &)) {
			f(stream_);
  			return *this;
		}

		template<typename U = L>
		typename std::enable_if< U::value >= T::value, CTLogLevel<U> >::type&
		operator << (std::ostream& (*f)(std::ios &)) {
			f(stream_);
  			return *this;
		}

		template<typename U = L>
		typename std::enable_if< U::value >= T::value, CTLogLevel<U> >::type&
		operator << (std::ostream& (*f)(std::ios_base &)) {
			f(stream_);
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
		private:
		std::ostream& stream_; // The output stream of the log
	};

	// The specific logs members.
	CTLogLevel<DebugLogLevel> debug;
	CTLogLevel<InfoLogLevel> info;
	CTLogLevel<WarningLogLevel> warning;
	CTLogLevel<ErrorLogLevel> error;
};

#endif // __CTLOG_H__
