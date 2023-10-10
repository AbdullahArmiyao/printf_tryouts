/**
 * This contains all the header files we'll be working with as well as
 * predefined functions and array size
*/

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256

void _fork();
void shell();

#endif
