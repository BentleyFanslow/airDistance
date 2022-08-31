/**
 * Author: Bentley Fanslow
 *         bfanslow@unomaha.edu
 * Date: 2022/09/06
 *
 * Try to find the distance between two points on the earth without a tape measure.
 *
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

// declare some variables and constant

    const int RADIUS = 6371;

    double startLatDeg = 0;
    double startLongDeg = 0;
    double finishLatDeg = 0;
    double finishLongDeg = 0;
    double startLatRad = 0;
    double startLongRad = 0;
    double finishLatRad = 0;
    double finishLongRad = 0;
    double distance = 0;

// I need to prompt the user for the lat and long of the two points
// todo.. accept deg/min/sec and NESW inputs, maybe some sort of verification.

    printf("Please make all entries in signed decimal degrees. use (-) for west or south\n");
    printf("What is the latitude of the first point?: \n");
    scanf("%lf", &startLatDeg);

    printf("What is the longitude of the first point?: \n");
    scanf("%lf", &startLongDeg);

    printf("What is the latitude of the second point?: \n");
    scanf("%lf,", &finishLatDeg);

    printf("What is the longitude of the second point?: \n");
    scanf("%lf", &finishLongDeg);

// convert to radians

    startLatRad = (startLatDeg/180) * M_PI;
    startLongRad = (startLongDeg/180) * M_PI;
    finishLatRad = (finishLatDeg/180) * M_PI;
    finishLongRad = (finishLongDeg/180) * M_PI;

// math the crap out of them

    distance = acos((sin(startLatRad) * sin(finishLatRad)) + (cos(startLatRad) * cos(finishLatRad) * cos(startLongRad - finishLongRad))) * RADIUS;

// Make it output

    printf("\n\nLocation Distance \n======================== \n");
    printf("Origin:      (%lf, %lf)\nDestination: (%lf, %lf) \n", startLatDeg, startLongDeg, finishLatDeg, finishLongDeg);
    printf("Air distance is %lf kms \n\n\n", distance);

return 0;
}