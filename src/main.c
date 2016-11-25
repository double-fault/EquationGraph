//
//  main.c
//  EquationGraph
//
//  Created by Ashish Ahuja on November 19th 2016.
//  Copyright © 2016 Fortunate-MAN (Ashish Ahuja). All rights reserved.
//

#define NUM_POINTS 3
#define LHS 0
#define RHS 1
#define POSITIVE '+'
#define NEGATIVE '-'
#define MAX_RAND 9

#include "gnuplot.h"

/*int main (int argc, char **argv)
{
    double xvals [NUM_POINTS] = {2.3, 3.5, 4.1};
    double yvals [NUM_POINTS] = {3.7, 3.8, 4};

    srand(time(NULL)); //Getting a distinct seed time
    initPlotLine (1, "red");
    initLinePointSpace (3);
    initGraphTitle ("Example Graph 1");
    clearFile ("data");
    FILE *file = fopen ("data", "w");
    writeCoord (file, xvals, yvals, NUM_POINTS);
    plotGraph ("data", 1);
    fclose (file);
    return 0;
}*/

int main (int argc, char **argv)
{
    char y, x;
    unsigned res;
    char operation;
    char temp;

    puts ("Enter first variable: ");
    scanf ("%c", &x);

    puts ("Enter second variable: ");
    scanf (" %c", &y);

    puts ("Enter result: ");
    scanf ("%d", &res);

    puts ("Enter operation: ");
    scanf (" %c", &operation);

   // y *= -1;

    FILE *file = fopen ("x", "w");

    if (operation == POSITIVE)
    {
        for (unsigned i = 0; i < NUM_POINTS; i ++)
        {
            int random = rand () % MAX_RAND;
            writeCoord (file, res - random, random);
        }
    }
    else if (operation == NEGATIVE)
    {
        for (unsigned i = 0; i < NUM_POINTS; i ++)
        {
            int random = rand () % MAX_RAND;
            writeCoord (file, res + random, random);
        }
    }

    initPlotLine (1, "red");
    initLinePointSpace (3);
    initGraphTitle ("EquationGraph");
    fclose (file);
    FILE *f = fopen ("x", "r");

    plotGraph ("x", 1);
    fclose (f);
    return 0;
}
