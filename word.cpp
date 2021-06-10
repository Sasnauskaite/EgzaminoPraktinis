#include "word.h"
bool ltLetter(char a){
    std::string letters = "ąčęėįšųūžĄČĘĖĮŠŲŪŽ";
    int n = letters.length();
    for(int i = 0; i < n; i++)
    {
        if(letters[i]==a) return true;
    }
    return false;
}
void word::setWord(std::string _w){
    w = _w;
}
bool word::checkWord()
{
    int n = w.length();
    for(int i = 0; i < n; i++)
    {
        if(ltLetter(w[i]) || isalpha(w[i])) return true;
    }
    return false;
}
std::string word::trimWord()
{
    int n = w.length();
    std::string temp = "";
    for(int i = 0; i < n; i++)
    {
        if((isalnum(w[i]) || ltLetter(w[i])) || (i != n-1 && i != 0 && ((isalnum(w[i-1]) || ltLetter(w[i]))  && (isalnum(w[i+1]) || ltLetter(w[i]))))) temp+=w[i];
    }
    w = temp;
    return temp;
}
std::string word::getWord() const
{
    return w;
}
int word::getCounter() const
{
    return counter;
}
std::vector <int> word::getLines() const
{
    return lines;
}

std::string word::formatWord()
{
    int n = w.length();
    std::string temp = "";
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
             temp+=toupper(w[i]);
        }
        else{
            if(i!=0 && w[i-1] == '.')
            {
                 temp+=w[i];
                 continue;
            }
            temp+=tolower(w[i]);
        }
    }
    w = temp;
    return temp;
}
void word::updateLines(int line)
{
    lines.push_back(line);
    counter++;
}
bool word::checkUrl()
{
    std::regex url1("^https?:\/\/.*");
    std::regex url2("^www\..*");

    return (regex_match(w, url1) || regex_match(w, url2));
}
