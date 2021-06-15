#include <string.h>
#include <iostream>
#include "HiScoreManager.h"

using namespace std;

HiScoreManager::HiScoreManager()
{
}
void HiScoreManager::load(string hiscore, string name)
{

  hiscoreFilePath = hiscore;
  char buffer[14];
  int index = 0;
  cout << "HEre0" << endl;
  ifstream input(hiscore, ios::binary);
  while (input.read(buffer, ELEMENT_BYTES))
  {
    char *name = new char(11);
    strncpy(name, buffer, 10);
    name[10] = 0;
    int value;
    memcpy(&value, &buffer[10], sizeof(int));

    HiScore *score = new HiScore(name, value);
    // cout<<buffer<<endl;
    // for(int i = 0;i<14;i++)
    cout << score->getName() << endl;
    cout << score->getScore() << endl;
    hi[index++].push_back(*score);
  }
  input.close();
  cout << "Stopped reading" << endl;
}

void HiScoreManager::writeToFile()
{

  ofstream output(hiscoreFilePath, ios::binary);

  for (int i = 0; i < hi->size(); i++)
  {
    output.write(hi->at(i).getName(), 10);
    char arrayOfByte[4];
    int score = hi->at(i).getScore();
    score++;
    memcpy(arrayOfByte, &score, sizeof 4);

    output.write(arrayOfByte, 4);
    cout<<"\n\n aaaaaaaaa"<<endl;
    // hi->at(i).getScore();
  }
  output.close();
}