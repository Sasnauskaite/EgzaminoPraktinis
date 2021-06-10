#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED
#include <vector>
#include <string>
#include <map>
#include <regex>
using std::vector;
using std::string;
class word
{
private:
    string w;
    int counter;
    vector <int> lines;
public:
    word(){
        counter = 0;
        lines = {};
    }
    string getWord() const;
    int getCounter() const;
    vector <int> getLines() const;
    void setWord(string _w);
    bool checkWord();
    string trimWord();
    string formatWord();
    void updateLines(int line);
    bool checkUrl();
};
#endif // WORD_H_INCLUDED
