# CTLog
Compile Time Log in C++

## Getting started
Include the `ctlog.h` header file, and create a CTLog object with a given level.
Only log messages with higher level will be compiled.
```
#include "ctlog.h"

CTLog<InfoLogLevel> log;

int main() {
	log.debug << "You won't see this message because debug < info" << std::endl;
	log.error << " You will see this message becasue error > info" << std::endl;
}
```

## Run the example
```
g++ main.cc -o ctlog-tester
```
