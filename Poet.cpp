#include "Poet.h"
Poet::Poet() {
	cout << "������ ����������� Poet" << endl << endl;
	FIO = "NaN";
	years_of_life = "NaN";
	head = NULL;
	countArtworks = 0;
}
Poet::Poet(const Poet& other) {
	cout << "������ ����������� ����������� Poet" << endl << endl;
	this->countArtworks = 0;
	*this = other;
}
Poet::~Poet() {
	cout << "������ ���������� Poet" << endl << endl;
	Artworks* current = head;
	for (int i = 0; i < countArtworks; ++i) { //������� ��������, ������� � ������ ������
		head = head->nextArtworks;
		delete current;
		current = head;
	}
}
//��� ������ � ������ �� ����� ���������� ��������� ������ �������:
//������ � ����� ����� ����� ���������� ���������
//����� ���� ������� ������ (������� ��������� ������� ��� ������ � ������)
//� ������ ������ ������� ���, ����� ���� �����
//����� ����� ���������� ������������, � �� ��� � ���� ������������
ofstream& operator<<(ofstream& fout, Poet& obj) {//����� ������ � ����
	fout << obj.FIO << " " << obj.years_of_life << " " << obj.countArtworks << endl;
	Artworks* current = obj.head;
	for (int i = 0; i < obj.countArtworks; ++i) {
		fout << current->name << " ";
		current = current->nextArtworks;
	}
	return fout;
}
ifstream& operator >> (ifstream& fin, Poet& obj) {//���� ������ �� �����
	int count; //����������, ����� �����, ������� ������������ ���������
	fin >> obj.FIO >> obj.years_of_life >> count;
	string name;
	for (int i = 0; i < count; ++i) {
		fin >> name; //��������� �������� ������������
		obj.addArtworks(name); //��������� ������������ (������� ���-�� �����������		������������ � ���� �������)
	}
	return fin;
}
ostream& operator<<(ostream& out, Poet& obj) {//����� ������ � �������
	out << "���: " << obj.FIO << endl;
	out << "���� �����: " << obj.years_of_life << endl;
	out << "���������� ������������: " << obj.countArtworks << endl;
	Artworks* current = obj.head;
	for (int i = 0; i < obj.countArtworks; ++i) {
		out << "������������ " << i + 1 << " : " << current->name << endl;
		current = current->nextArtworks;
	}
	out << "--------------------------------------------------------------------------------";
	return out;
}
istream& operator >> (istream& in, Poet& obj) {
	cout << "������� ������" << endl << endl;
	cout << "���: ";
	cin >> obj.FIO;
	cout << "���� �����: ";
	cin >> obj.years_of_life;
	/*����� ������ ����� ������������ ������� ������ ������������, ������� ����� ���	��������������
		Artworks* current = obj.head;
	for (int i = 0; i < obj.countArtworks; ++i) {
		obj.head = obj.head->nextArtworks;
		delete current;
		current = obj.head;
	}*/
	obj.countArtworks = 0; //�������� ���-�� ������������
						   //��������� ����� ������������
	string name;
	int count;
	cout << "���������� ������������: ";
	cin >> count;
	for (int i = 0; i < count; ++i) {
		cout << "������� " << i + 1 << " ������������: ";
		cin >> name;
		obj.addArtworks(name);
	}
	return in;
}
Poet& Poet::operator=(const Poet& other) {
	this->FIO = other.FIO;
	this->years_of_life = other.years_of_life;
	//������� ������ ������������ � ������� ����� �� �����
	Artworks* current = this->head;
	for (int i = 0; i < this->countArtworks; ++i) {
		head = head->nextArtworks;
		delete current;
		current = head;
	}
	this->countArtworks = 0;
	//�������� ������ ���-�� ������������ �� ������� ������ �� �����
	current = other.head;
	for (int i = 0; i < other.countArtworks; ++i) {
		this->addArtworks(current->name);
		current = current->nextArtworks;
	}
	return *this;
}