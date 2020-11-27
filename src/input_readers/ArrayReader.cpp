#include"ArrayReader.h"



char **read_char_array(std::string file_name) {
    std::ifstream fin(file_name);
    if (!fin.is_open()) {
        std::cout << "Cannot open file " << file_name << std::endl;
        std::cout << "Terminate execution" << std::endl;
    }
    char **array;
    int w, k;
    char feeder;
    fin >> w >> k;
    array = new char *[k];
    for (int i = 0; i < k; ++i) array[i] = new char[w];

//    std::cout << w << " " << k << std::endl;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < w; ++j) {
            fin >> feeder;
            array[i][j] = feeder;
//            std::cout << array[i][j];
        }
    //std::cout << std::endl;
    }

    return array;

}

void print_char_array(char **array,int w,int k){
	std::cout<<"\n";
	for (int i = 0; i < k; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cout << array[i][j];
        }
        std::cout << std::endl;
    }
    std::cout<<"\n";
}

int **read_int_array(std::string file_name) {
    std::ifstream fin(file_name);
    if (!fin.is_open()) {
        std::cout << "Cannot open file " << file_name << std::endl;
        std::cout << "Terminate execution" << std::endl;
    }
    int **array;
    int w, k;
    int feeder;
    fin >> w >> k;
    array = new int *[k];
    for (int i = 0; i < k; ++i) array[i] = new int[w];

   // std::cout << w << " " << k << std::endl;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < w; ++j) {
            fin >> feeder;
            array[i][j] = feeder;
        //std::cout << array[i][j]<<" ";
        }
        //std::cout << std::endl;
    }

    return array;

}

void print_int_array(int **array,int w,int k){
	std::cout<<"\n";
	for (int i = 0; i < k; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cout << array[i][j];
        }
        std::cout << std::endl;
    }
    std::cout<<"\n";
}
