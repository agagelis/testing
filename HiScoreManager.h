#ifndef HiScoreManager_h
#define HiScoreManager_h

#include <string>
#include <vector>
#include <fstream>
#include "HiScore.h"

using namespace std;

class HiScoreManager
{
private:
    vector <HiScore> hi[5];
    const int ELEMENT_BYTES = 14;
    string hiscoreFilePath;

public:
    HiScoreManager();
    void load(string hiscore,string name);
    void print();
    void writeToFile();
};

#endif