using namespace std;
void addToList(string w, int line, map <string, word>& words)
{
    if (words.count(w) > 0){words[w].updateLines(line);}
    else
    {
        word temp;
        temp.updateLines(line);
        words.insert(pair <string, word>(w, temp));
    }
}
