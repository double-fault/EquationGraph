//
//  gnuplot.h
//  EquationGraph
//
//  Created by Ashish Ahuja on November 19th 2016.
//  Copyright © 2016 Fortunate-MAN (Ashish Ahuja). All rights reserved.
//

#ifndef gnuplot_h
#define gnuplot_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearFile (char *fname);
void writeCoord (FILE *file, double xcoords, double ycoords);
void executePlotCommand (char *command);
void initPlotLine (unsigned serialNum, char *colour);
void initLinePointSpace (unsigned space);
void initGraphTitle (char *title);
void plotGraph (char *fname, unsigned lineNum);

#endif /* gnuplot.h */
