#include "ctlog.h"

CTLog<InfoLogLevel> log;

int main() {
        log.debug << "You won't see this message because debug < info" << std::endl;
        log.error << "You will  see this message because error > info" << std::endl;
}

