#include "Data.h"
#include <ctime>

void teste() {

tm *d1 = new tm();

d1->tm_hour = 10;
d1->tm_min = 0;
d1->tm_sec = 0;
d1->tm_isdst = 0;
d1->tm_mday = 21;
d1->tm_mon = 10 - 1;
d1->tm_year = 2024 - 1900;

    
}