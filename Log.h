//
// Created by Motherflippin on 23/04/2018.
//

#ifndef VONNEUMANNEMULATOR_LOG_H
#define VONNEUMANNEMULATOR_LOG_H

#include "stdio.h"


void Log(char Message[]) {
#ifdef DEBUG
    // char ToPrint[] = "LOG" + Message;
    printf(Message);
#endif
}

#endif //VONNEUMANNEMULATOR_LOG_H
