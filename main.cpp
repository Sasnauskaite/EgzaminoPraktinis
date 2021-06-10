#include <iostream>
#include "word.cpp"
#include "config.h"


int main()
{

    UINT default_console_output_cp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    std::map <string, word> words;
    std::vector<string> urls ;


    readFile(fileName,words,urls);
    writeFile(outputName,words);


    int n = urls.size();
    for(int i = 0; i < n; i++)
    {
        std::cout<<urls[i]<<std::endl;
    }


    SetConsoleOutputCP(default_console_output_cp);
    return 0;
}

