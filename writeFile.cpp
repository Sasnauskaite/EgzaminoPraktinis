#include "writeFile.h"

void writeFile(std::string outputName, std::map <std::string, word> words)
{
    std:: ofstream fr(outputName.c_str());

    const char separator    = ' ';
    const int nameWidth     = 30;


    fr << left << std::setw(nameWidth) << setfill(separator) << "|Žodis" << left << std::setw(nameWidth) << setfill(separator) << "|Kiek pasikartojo" << left << std::setw(nameWidth)<< setfill(separator)<< "|Kuriuose eilutėse kartojosi" << std::endl;
    for ( std::map<std::string, word>::const_iterator it = words.begin(); it != words.end(); ++it)
    {
        if(it->second.getCounter()>1)
        {
            fr << left << std::setw(nameWidth) << setfill(separator) << it->first;
            fr << left << std::setw(nameWidth) << setfill(separator) << it->second.getCounter();
            std::vector<int> temp = it->second.getLines();
            for (std::vector<int>::const_iterator i = temp.begin(); i != temp.end(); ++i) fr << *i << ' ';
            fr << std::endl;
        }
    }

    fr.close();
}
