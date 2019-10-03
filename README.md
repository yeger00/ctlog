# CTLog
Compile Time Log in C++

## Getting started
Include the `ctlog.h` header file, and create a CTLog object with a given level.
Only log messages with higher level will be compiled.
In the `examples` directory you can see the following example:
```
#include "ctlog.h"

CTLog<InfoLogLevel> log;

int main() {
	log.debug << "You won't see this message because debug < info" << std::endl;
	log.error << "You will  see this message because error > info" << std::endl;
}
```

You can compile it with:
```
g++ -O3 -I. examples/example1.cc -o example1
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


The second example defines all the `CTLog`s, and calls each log function.
```
g++ -O3 -I. examples/example2.cc -o example2
```
