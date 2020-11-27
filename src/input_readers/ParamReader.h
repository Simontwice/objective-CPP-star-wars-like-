
#ifndef __PARAMREADER_H_
#define __PARAMREADER_H_

#include "../game/misc/Includes.h"

std::unordered_map<std::string, int> read_params(std::string file_name);

void print_params(std::unordered_map<std::string, int> m);

#endif

