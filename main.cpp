#include <cctype>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include "brainfork_executor.h"

int main(int argc, char *argv[]) {
    if(argc != 3 || !isdigit((int)(*argv[2]))) {
        std::cout << "Legal command is \"" << argv[0]
                  << " {script_path}" << " {optimize}" << "\" where {optimize} is 0 or 1";
        return 1;
    }
    BrainforkExecutor{}.Execute(argv[1], *argv[2] - '0');
    auto time = clock();
    std::cout << "Script finished in " << time / 1000 << " seconds " << time % 1000 << " ms" << std::endl;
    return 0;
}
