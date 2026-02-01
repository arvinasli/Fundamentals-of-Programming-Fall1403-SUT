// Arvin Baghal Asl
// 403105793

#include "grader.h"
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

#define MAX_SIZE 75

double average(int n, ...) {
    double sum = 0;
    va_list pointer;
    va_start(pointer,n);

    for (int i=0; i<n; i++) {
        sum += va_arg(pointer,double);
    }

    va_end(pointer);

    double average = sum/n;
    return average;
}

double variance(int n, ...) {
    double sum = 0;
    double sum_of_squares = 0;
    va_list pointer;
    va_start(pointer,n);

    double arr[MAX_SIZE];
    for(int i=0; i<n; i++) {
        arr[i] = va_arg(pointer,double);
        sum += arr[i];
    }
    double avg = sum/n;

    for(int i=0; i<n; i++) {
        sum_of_squares += pow((arr[i]-avg),2);
    }

    double variance = sum_of_squares/(n-1);
    return variance;
}

double calculate_a(int n, double average_x, double average_y, double average_xy, double variance_x) {
    double a = (n*(average_xy-(average_x*average_y)))/((n-1)*variance_x);
    return a;
}

double calculate_b(double a, double average_x, double average_y) {
    double b = average_y-(a*average_x);
    return b;
}