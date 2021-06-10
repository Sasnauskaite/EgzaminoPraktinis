#include "readFile.h"

void readFile(std::string fileName, std::map <std::string, word>& words, std::vector<std::string> &urls)
{
    std::ifstream fd(fileName.c_str());

    int line = 0;

    while (!fd.eof())
    {
        line++;
        std::string row;
        getline(fd, row);

        std::stringstream ss(row);
        std::string w;
        while (ss >> w)
        {
            word temp;
            temp.setWord(w);
            if(temp.checkUrl()){
                urls.push_back(w);
                continue;
            }
            if(temp.checkWord())
            {
                 temp.trimWord();
                 temp.formatWord();
                 addToList(temp.getWord(),line,words);
            }

        }

    }
    fd.close();
}
