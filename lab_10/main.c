#include <stdio.h>
#include "split.h"

int main() {
    int start_minutes = on_work();
    int end_minutes = off_work();
    
    int min_day = end_minutes - start_minutes;
    
    int week_minutes = min_day * 7;
    int hours = week_minutes / 60;
    int minutes = week_minutes % 60;

    struct Time {
        int hour;
        int minute;
    };


    struct Time opo[3];
    opo[2].hour = 1;


    for (int i = 0; i <= 2; i++) {
        opo[i].hour = i;
        opo[i].minute = i * 60;
    }


    printf("Часы: %d минуты: %d\n",opo[0].hour, opo[0].minute);

    printf("Работа в неделю: %d часов %d минут\n", hours, minutes);
    
    return 0;
}