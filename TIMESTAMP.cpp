
#include <time.h>
#include "TIMESTAMP.hpp"

char * get_timestamp() {

    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,80,"%F %T",timeinfo);

    return buffer;
}
