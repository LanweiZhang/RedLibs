//
//  logfile.cpp
//  RedLibsMPI
//
//  Updated on 25/07/2016
//
//  This software is free software, licensed under the GNU GPL license v3.0.
//  Copyright (c) ETH Zurich, D-BSSE, BPL, Daniel Gerngross 2015. All rights reserved.
//  See http://www.bsse.ethz.ch/bpl/software/redlibs for updates, documentation, questions, and answers.
//  Please cite M. Jeschek, D. Gerngross, S. Panke, Nature Communications, 2016
//

#include "logfile.h"
#include <fstream>
#include <time.h>

//function to create a log file
void writelog ( std::string output, std::string message , int t ) {
    std::string logfilepath = "log.txt";
    logfilepath = output + logfilepath;
    
    std::string timestring;
    if ( t == 1){
        char timechars[25];
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        strftime ( timechars, 20, "%F %T%t", timeinfo );
        timestring = timechars;
        
    } else timestring = "";

    
    std::ofstream logfile;
    logfile.open ( logfilepath.c_str() , std::ios::app);
    logfile << timestring;
    logfile << message;
    logfile.close();
}
