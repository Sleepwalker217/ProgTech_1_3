#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;
struct Artworks { //������ ������������
	string name;
	Artworks* nextArtworks;
};
class Edition {
protected:
	string FIO;						//������� ��� �������� � _
	Artworks* head;					//��������� �� ������ ������ ������
	int countArtworks;				//���������� ������������ � ��������
	void addArtworks(string name);	//���������� ������������
	//void deleteArtworks(int index);	//�������� ������������ �� �������
public:
	Edition() { cout << "������ ����������� Edition" << endl << endl; }
	virtual ~Edition() { cout << "������ ���������� Edition" << endl << endl; }
	//������ ����������� �������, ����� ����� ���� �����������
	virtual void setFIO(string) = 0;
	virtual string getFIO() = 0;
};