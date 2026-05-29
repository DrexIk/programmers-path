#include <stdio.h>
#include "split.h"

int on_work() {
    struct Time on;
    on.hour = 8;
    on.minute = 20;
    int include_min = on.hour * 60 + on.minute;
    return include_min;
}

int off_work() {
    struct Time off;
    off.hour = 16;
    off.minute = 50;
    int off_min = off.hour * 60 + off.minute;
    return off_min;
}