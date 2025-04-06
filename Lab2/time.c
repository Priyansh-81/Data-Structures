#include <stdio.h>
typedef struct {
    int hour;
    int min;
    int sec;
} Time;
Time addTimes(Time t1, Time t2);
Time subtractTimes(Time t1, Time t2);
void readTime(Time *t);
void displayTime(Time t);

int main() {
    Time t1, t2, sum, diff;
    printf("Enter the first time (hh mm ss): ");
    readTime(&t1);
    printf("Enter the second time (hh mm ss): ");
    readTime(&t2);

    sum = addTimes(t1, t2);

    diff = subtractTimes(t1, t2);

    printf("\nFirst Time: ");
    displayTime(t1);
    printf("Second Time: ");
    displayTime(t2);
    printf("Sum of Times: ");
    displayTime(sum);
    printf("Difference of Times: ");
    displayTime(diff);

    return 0;
}

// Function to add two time objects
Time addTimes(Time t1, Time t2) {
    Time result;
    result.sec = t1.sec + t2.sec;
    result.min = t1.min + t2.min + result.sec / 60;
    result.hour = t1.hour + t2.hour + result.min / 60;
    result.min %= 60;
    result.sec %= 60;
    return result;
}

// Function to subtract two time objects
Time subtractTimes(Time t1, Time t2) {
    Time result;
    int totalSec1 = t1.hour * 3600 + t1.min * 60 + t1.sec;
    int totalSec2 = t2.hour * 3600 + t2.min * 60 + t2.sec;
    int totalSecDiff = totalSec1 - totalSec2;

    if (totalSecDiff < 0) {
        totalSecDiff = -totalSecDiff;
    }

    result.hour = totalSecDiff / 3600;
    totalSecDiff %= 3600;
    result.min = totalSecDiff / 60;
    result.sec = totalSecDiff % 60;

    return result;
}

void readTime(Time *t) {
    scanf("%d %d %d", &t->hour, &t->min, &t->sec);
}

void displayTime(Time t) {
    printf("%02d:%02d:%02d\n", t.hour, t.min, t.sec);
}
