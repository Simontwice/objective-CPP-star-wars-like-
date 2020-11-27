#include"ParamReader.h"


std::unordered_map<std::string, int> read_params(std::string file_name) {
    std::ifstream fin(file_name);
    if (!fin.is_open()) {
        std::cout << "Cannot open file " << file_name << std::endl;
        std::cout << "Terminate execution" << std::endl;
    }
    std::unordered_map<std::string, int> m;
    std::string par_name;
    int par_value;
    while (fin >> par_name >> par_value)
        m[par_name] = par_value;
    return m;
}

void print_params(std::unordered_map<std::string, int> m) {
    for (auto par: m)
        std::cout << par.first << ": " << par.second << std::endl;
}

