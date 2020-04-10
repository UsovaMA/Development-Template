#include "DictionaryClass.h"
#include "vector"
#include "iostream"
#include "string"

int main() {
  setlocale(LC_ALL, "Russian");
  //������ �� �������

  //�������� �����
  auto word1 = new Word(); //��� �������� � �����
  auto word2 = new Word("cat", "���"); //����� � ���� �������
  auto word3 = new Word("cake", vector<string>{"����", "��������"}); //����� � ��������� ��������

  //���������� �����
  word1->setWord("dog");

  //����������� �������(�������� ���������) (����� ������ ��������� ��������� ��������)
  word1->setTranslation("������");

  //�������� �������(���� ������ ��� ���, �������) (����� ������ ��������� ��������� ��������)
  word1->addTranslation("�������");

  word3->setTranslation(vector<string>{"����123", "!@#."}); //������ �� �� ���� �� ����� ��������

  //�������� �������� �����
  string val = word1->getWord();

  //�������� vector ���������
  vector<string> translations = word1->getTranslations();


  //������ �� ��������

  //������ �������
  auto dictionary = new Dictionary();

  //������� �� �����

  //**��� �������� ��� �������� ���������� true/false ���������� ����� ��� ������� ��������**

  //�������� ����� � �������
  dictionary->addWord(word1);
  dictionary->addWord(word2);
  dictionary->addWord(word3);
  //��������� �� ����� ������ �� ���� ������ ������� (���� ��� ���������, ����������)
  word1->addTranslation("���");

  //���� ����� � ����� ��������� ��� ����������, ��� ����� ��������� ������������
  auto word4 = new Word("cat", "�����");
  dictionary->addWord(word4);

  //��������� ����������� ����� ���������� �����, � ������ ��� ������������� � �������, �������� ����� �������
  dictionary->mergeAddWord(word2);

  //��������� ������� ����� � ������� (0 - ���� ����� ���, ����� ��� id)
  dictionary->find("cat");

  //�������� ������ �� ����� � ������� (����� ���� ���������� ��������� ��� ������� � �������)
  if (dictionary->find("dog")) auto word5 = dictionary->get("dog");

  //������ ���������� ���� � �������
  int amount = dictionary->wordsCount();

  //�������� ������� �� ����� ����������� � ��������� ���� (.txt)
  dictionary->out("myDictionary.txt");

  //�������� ������� �� �����
  auto inDictionary = new Dictionary("myDictionary.txt");

  //����� ��������� ���������� ��� �������
  //dictionary->in("myDictionary.txt");

  //��������� ��������� �������� �� ��������
  if (inDictionary->find("cake")) {
    Word* myWord = inDictionary->get("cake");
    myWord->setTranslation("����");
  }
  auto word6 = new Word("beauty", "�������");
  inDictionary->mergeAddWord(word6);

  //����� �������� ��� ���� ����
  inDictionary->out("changedDictionary.txt");

  //������� ��������
  auto mergeDictionary1 = new Dictionary();
  mergeDictionary1->addWord(new Word("foraging", "�����������"));
  mergeDictionary1->addWord(new Word("steelmaker", vector<string>{"��������", "���������"}));

  //������� � ��������������������� �����
  mergeDictionary1->merge(dictionary);
  mergeDictionary1->out("firstMerge.txt");

  auto mergeDictionary2 = new Dictionary();
  mergeDictionary2->addWord(new Word("mindless", vector<string>{"�������������", "������"}));
  mergeDictionary2->addWord(new Word("capsule", "�������"));

  //������� � �������� �� �����
  mergeDictionary2->merge("changedDictionary.txt");
  mergeDictionary2->out("secondMerge.txt");

  //����� ��� ������� � ����� � ������� "+"
  Dictionary md1 = *mergeDictionary1;
  Dictionary md2 = *mergeDictionary2;
  Dictionary md3 = md1 + md2;
  md3.out("thirdMerge.txt");

  //���������� ������������

  //����� �������� ������������
  auto copiedDict1 = md1;
  copiedDict1.addWord(new Word("astronomy", "����������"));
  //����� �����������
  auto copiedDict2 = Dictionary(md1);
  copiedDict2.addWord(new Word("hotel", "���������"));

  //��������� ��������� �� ������ �� �������-������ (� �������� ����� �� ������ ���� ���� astronomy ��� hotel)
  md1.out("firstMerge.txt");

  copiedDict1.out("firstCopy.txt");
  copiedDict2.out("secondCopy.txt");
  return 0;
}
