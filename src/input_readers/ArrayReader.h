#include "../game/misc/Includes.h"
#include <string>
#ifndef __ARRAYREADER_H_
#define __ARRAYREADER_H_

char **read_char_array(std::string file_name);

int **read_int_array(std::string file_name);

void print_char_array(char **array,int w ,int k);

void print_int_array(int**array,int w ,int k);

#endif
