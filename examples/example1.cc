#include "ctlog.h"
#include <iostream>

CTLog<InfoLogLevel> log(std::cout);

int main() {
        log.debug << "You won't see this message because debug < info" << std::endl;
        log.error << "You will  see this message because error > info" << std::endl;
}

