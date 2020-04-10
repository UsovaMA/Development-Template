#ifndef TASK3_DICTIONARYCLASS_H
#define TASK3_DICTIONARYCLASS_H

#include <string>
#include <vector>

using namespace std;
class Word {
public:
  Word();
  Word(string eng, string translation);
  Word(string eng, vector<string> translations);
  Word(string eng, vector<string> translations, int _id);
  void setTranslation(string translation);
  void setTranslation(vector<string> translations);
  void addTranslation(string translation);
  void addTranslation(vector<string> translations);
  void setWord(string word);
  void setId(int _id);
  bool haveTranslation(string translation);
  string getWord();
  int getId();
  vector<string> getTranslations();
private:
  int id;
  string word;
  vector<string> translations;
  static bool parser(string word);
  static bool parser(vector<string> words);
  void setNull();
};

class Dictionary {
public:
  Dictionary();

  explicit Dictionary(string filename);

  explicit Dictionary(Dictionary *dictionary);

  ~Dictionary();

  bool addWord(Word *word);

  bool mergeAddWord(Word *word);

  bool deleteWord(string word);

  bool deleteWord(Word word);

  int find(string word);

  int find(Word word);

  Word *get(string word);

  Word *get(Word word);

  vector<Word *> getAll() const;

  int wordsCount();

  bool out(string filename);

  bool in(string filename);

  bool merge(string filename);

  bool merge(Dictionary *toMerge);

  bool merge(const Dictionary &toMerge);

  Dictionary &operator+=(const Dictionary &toAdd);

  friend Dictionary operator+(const Dictionary &first, const Dictionary &second);

  Dictionary &operator=(const Dictionary &copy);

private:
  void shuffleIds();

  vector<Word *> words;

  void destroy();
};




#endif //TASK3_DICTIONARYCLASS_H
