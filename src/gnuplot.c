//
//  gnuplot.c
//  EquationGraph
//
//  Created by Ashish Ahuja on November 19th 2016.
//  Copyright © 2016 Fortunate-MAN (Ashish Ahuja). All rights reserved.
//

#include "gnuplot.h"

void clearFile (char *fname)
{
    FILE *file = fopen (fname, "w");
    fclose (file);
}

void writeCoord (FILE *file, double xcoords, double ycoords)
{
        fprintf (file, "%lf %lf \n", xcoords , ycoords ); //Write the coordinates to the file pointer passed
}

void executePlotCommand (char *command)
{
    FILE *plotPipe = popen ("gnuplot -persistent", "w");

    fprintf (plotPipe, "%s \n", command);
}

void initPlotLine (unsigned serialNum, char *colour)
{
    char *command;
    asprintf (&command, "set style line %u lc rgb '%s' lt 1 lw 2 pt 5 pi -1 ps 4.0", serialNum, colour);
    executePlotCommand (command);
    free (command);
    return;
}

void initLinePointSpace (unsigned space)
{
    char *command;
    asprintf (&command, "set pointintervalbox %u", space);
    executePlotCommand (command);
    free (command);
    return;
}

void initGraphTitle (char *title)
{
    char *command;
    asprintf (&command, "set title \"%s\"", title);
    executePlotCommand (command);
    free (command);
    return;
}

void plotGraph (char *fname, unsigned lineNum)
{
    char *command;
    asprintf (&command, "plot '%s' with linespoints ls %u", fname, lineNum);
    puts (command);
    executePlotCommand (command);
    free (command);
    return;
}
