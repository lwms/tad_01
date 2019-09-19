#include <stdlib.h>
#include <time.h>
#include "timestamp.hpp"

char * get_timestamp() {

    time_t rawtime;
    struct tm * timeinfo;
    char * buffer = (char *) malloc( sizeof(char) * 80);

    if(buffer == NULL) {
        return NULL;
    }

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,80,"%Y-%m-%d %H:%M:%S", timeinfo);

    return buffer;
}
