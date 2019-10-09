# CTLog
Compile Time Log in C++


## Getting started
Include the `ctlog.h` header file, and create a CTLog object with a given level.
Only log messages with higher level will be compiled.
For example:
```
#include "ctlog.h"
#include <iostream>

CTLog<InfoLogLevel> log(std::cout);

int main() {
	log.debug << "You won't see this message because debug < info" << std::endl;
	log.error << "You will  see this message because error > info" << std::endl;
}
```

You can compile it with:
```
g++ -O3 -I/path/to/ctlog/include /path/to/example1.cc -o example1
```

When running, only the second messasge is shown:
```
$ ./example1
You will  see this message because error > info
```

When running strings, only the second message exists:
```
$ strings example1 | grep because
You will  see this message because error > info
```
This example can also be found in the `./examples` directory.


## Compiling the examples
You can compile the examples with cmake:
```
mkdir build
cd build
cmake ..
make
```
Then all the compiled examples will be in the `build/examples` directory.
