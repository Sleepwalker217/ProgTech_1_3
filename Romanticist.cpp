#include "Romanticist.h"
Romanticist::Romanticist() {
	cout << "������ ����������� Romanticist" << endl << endl;
	FIO = "NaN";
	biography = "NaN";
	years_of_life = "NaN";
	head = NULL;
	countArtworks = 0;
}
Romanticist::Romanticist(const Romanticist& other) {
	cout << "������ ����������� ����������� Romanticist" << endl << endl;
	this->countArtworks = 0;
	*this = other;
}
Romanticist::~Romanticist() {
	cout << "������ ���������� Romanticist" << endl << endl;
	Artworks* current = head;
	for (int i = 0; i < countArtworks; ++i) {
		head = head->nextArtworks;
		delete current;
		current = head;
	}
}
ofstream& operator<<(ofstream& fout, Romanticist& obj) { //����������� ������ � ���� (������������� �	������ ������ ����������)
	fout << obj.FIO << " " << obj.years_of_life << " " << obj.biography << " " << obj.countArtworks << endl;
	Artworks* current = obj.head;
	for (int i = 0; i < obj.countArtworks; ++i) {
		fout << current->name << " ";
		current = current->nextArtworks;
	}
	return fout;
}
ifstream& operator >> (ifstream& fin, Romanticist& obj) { //���������� ������ �� �����
	int count;
	fin >> obj.FIO >> obj.years_of_life >> obj.biography >> count;
	string name;
	for (int i = 0; i < count; ++i) {
		fin >> name;
		obj.addArtworks(name);
	}
	return fin;
}
ostream& operator<<(ostream& out, Romanticist& obj) { //���������� ������ �� �������
	out << "���: " << obj.FIO << endl;
	out << "���� �����: " << obj.years_of_life << endl;
	out << "������� ���������: " << obj.biography << endl;
	out << "���������� ������������: " << obj.countArtworks << endl;
	Artworks* current = obj.head;
	for (int i = 0; i < obj.countArtworks; ++i) {
		out << "������������ " << i + 1 << " : " << current->name << endl;
		current = current->nextArtworks;
	}
	out << "--------------------------------------------------------------------------------";
	return out;
}
istream& operator >> (istream& in, Romanticist& obj) { //���������� ������ � ����������
	cout << "������� ������" << endl << endl;
	cout << "���: ";
	cin >> obj.FIO;
	cout << "���� �����: ";
	cin >> obj.years_of_life;
	cout << "������� ���������: ";
	cin >> obj.biography;
	Artworks* current = obj.head;
	for (int i = 0; i < obj.countArtworks; ++i) {
		obj.head = obj.head->nextArtworks;
		delete current;
		current = obj.head;
	}
	obj.countArtworks = 0;
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
Romanticist& Romanticist::operator=(const Romanticist& other) { //���������� ��������� ������������
	this->FIO = other.FIO;
	this->years_of_life = other.years_of_life;
	this->biography = other.biography;
	Artworks* current = this->head; //��������� �� ������ ������������ ������� a (�������� ������	������)
	for (int i = 0; i < this->countArtworks; ++i) {
		head = head->nextArtworks;
		delete current;
		current = head;
	}
	this->countArtworks = 0; //�������� ������
	current = other.head;
	for (int i = 0; i < other.countArtworks; ++i) {
		this->addArtworks(current->name);
		current = current->nextArtworks;
	}
	return *this;
}