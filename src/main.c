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

/*int main (int argc, char **argv)
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
}*/

void removeChar (char *str, char toRemove)
{
    for (unsigned i = 0; i < strlen (str); i ++)
    {
        if (str [i] == toRemove)
        {
            for (unsigned j = i; i < strlen (str); j ++)
            {
                str [j] = str [j + 1];
            }
        }
    }
}

int main (int argc, char **argv)
{
   // initGraphTitle ("Speed graph.");
    char *vehicle1 = malloc (sizeof (char) * 64);
    char *vehicle2 = malloc (sizeof (char) * 64);

    puts ("Enter first vehicle: ");
    fgets (vehicle1, sizeof (vehicle1), stdin);
    strtok (vehicle1, "\n");
   // puts (vehicle1);
int c;
while ( (c = getchar()) != EOF && c != '\n') { }
    puts ("Enter second vehicle: ");
    fgets (vehicle2, sizeof (vehicle2), stdin);
    strtok (vehicle2, "\n");
   // puts (vehicle2);

    initPlotLine (1, "red");
    initPlotLine (2, "#0060ad");
    initLinePointSpace (5);

    /*removeChar (vehicle1, '?');
    removeChar (vehicle2, '?');*/

    FILE *vehicleFile = fopen (vehicle1, "w");

    int dist1 [3];
    int time1 [3];
    int time2 [3];
    int dist2 [3];
    unsigned i;
    char *temp = malloc (sizeof (char) * 128);
while ( (c = getchar()) != EOF && c != '\n') { }

    puts ("Enter distances for first vehicle: ");
    for (i = 0; i < 3; i ++)
    {
        fgets (temp, sizeof (temp), stdin);
        dist1 [i] = (int) strtol (temp, NULL, 10);
    }

    puts ("Enter times for first vehicle: ");
    for (i = 0; i < 3; i ++)
    {
        fgets (temp, sizeof (temp), stdin);
        time1 [i] = (int) strtol (temp, NULL, 10);
    }

    puts ("Enter distances for second vehicle: ");
    for (unsigned i = 0; i < 3; i ++)
    {
        fgets (temp, sizeof (temp), stdin);
        dist2 [i] = (int) strtol (temp, NULL, 10);
    }

    puts ("Enter times for second vehicle: ");
    for (i = 0; i < 3; i ++)
    {
        fgets (temp, sizeof (temp), stdin);
        time2 [i] = (int) strtol (temp, NULL, 10);
    }

    free (temp);

    int speed1 [3];
    int speed2 [3];

    //Calculating the speeds for the vehicles
    for (i = 0; i < 3; i ++)
    {
        speed1 [i] = dist1 [i] / time1 [i];
        speed2 [i] = dist2 [i] / time2 [i];
    }

    //Now writing the coordinates of the graph we want to a file
    for (i = 0; i < 3; i ++)
    {
        writeCoord(vehicleFile, dist1 [i], time1 [i]);
    }
    fprintf (vehicleFile, "\n\n");
    for (i = 0; i < 3; i ++)
    {
        writeCoord(vehicleFile, dist2 [i], time2 [i]);
    }

    fclose (vehicleFile);

    /*removeChar (vehicle1, '?');
    removeChar (vehicle2, '?');*/

    //strcat (vehicle1, "?");
    //strcat (vehicle2, "?");
    //plotGraph(vehicle1, 1);
    //plotGraph(vehicle2, 2);

    char *command;
    asprintf (&command, "plot '%s' index 0 with linespoints ls 1, \
                              ''   index 1 with linespoints ls 2", vehicle1);
    executePlotCommand(command);
    free (command);

    free (vehicle1);
    free (vehicle2);

    return 0;
}
