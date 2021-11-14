#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;
template <class T> //����� ����� ��������� �� ������� ����� (������ ����� �����������)
class Keeper {
	T* ptr_mas; //��������� �� ��������
	int size; //������ ����������
public:
	Keeper();
	Keeper(const Keeper&);
	~Keeper();
	void addElement(int index); //���������� ��������
	void deleteElement(int index); //�������� �������� �� �������
	void writeToFile(string); //������ � ����
	void readFromFile(string); //������ �� �����
	void displayData(); //����� ������ �� �����
	void dataChange(int index); //��������� ������
};
template<class T>
Keeper<T>::Keeper() {
	cout << "������ ����������� �� ��������� Keeper" << endl << endl;
	ptr_mas = nullptr;
	size = 0;
}
template<class T>
Keeper<T>::Keeper(const Keeper& other) {
	this->ptr_mas = new T[other.size]; //������� ������ � ����� �������
	this->size = other.size; //�������� ������
	for (int i = 0; i < size; ++i) //�������� ������ ������� � ����� ������
		this->ptr_mas[i] = other.ptr_mas[i];
}
template<class T>
Keeper<T>::~Keeper() {
	cout << "������ ���������� Keeper" << endl << endl;
	delete[] ptr_mas;
}
template<class T>
void Keeper<T>::addElement(int index) {
	try {
		if (index < 0 || index > size)
			throw exception("������������ ������!");
		T* tmp = new T[size + 1]; //������� ����� ������ �� ���� ������� ������ ���������� ����������� (Edition � Poet) ������� ���, ����� � ��� ������ �������� �������
		int j = 0;
		for (int i = 0; i < size; ++i) { //�������� ��� �������� � ����� ������
			if (index == i) //���� ������ ����� ���������� ��������,				�� ���������� ��� ������� � ����� �������
				j++;
			tmp[j++] = ptr_mas[i]; //������� ������� �������������� ����� ������			�������������
		}
		delete[] ptr_mas; //������� ������ ������ ����������� ����������� Edition � Poet ������� ���, ������� ��������� � ������������ �������
		ptr_mas = tmp; //ptr ��������� �� �����		������
			cin >> ptr_mas[index]; //������ ������ ������������		��������, ������� ��������� ��� �������� index
			++size; //�����������		������ ����������
			cout << endl << "����� ������� ������� ��������" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;
	}
}
template<class T>
void Keeper<T>::deleteElement(int index) {
	try {
		if (size == 0) { //���� �� ���������
			exception ex("������ ���! ������ �������!");
			throw ex;
		}
		if (index < 0 || index >= size) { //��������� �� ������
			exception ex("����������� ������!");
			throw ex;
		}
		T* tmp = new T[size - 1]; //������� ����� ������ �� ���� ������� ������ ���������� ����������� Edition � Poet ������� ���, ������� � ������� -1
			int j = 0;
		for (int i = 0; i < size; ++i) { //�������� ��� ��������, ����� ����������
			if (index != i)
				tmp[j++] = ptr_mas[i];
		}
		delete[] ptr_mas; //������� ������ ������ ���������� ���������� Poet � Edition
		ptr_mas = tmp; //ptr ��������� �� �����		������
			--size; //������ 		���������� ����������
			cout << endl << endl << "������� ������" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl; //����� ������ �� �����
	}
}
template<class T>
void Keeper<T>::writeToFile(string s) {
	try {
		ofstream fout(s, ios::out);
		if (!fout) {
			exception ex("�� ������� ������� ����!");
			throw ex;
		}
		if (size == 0) { // ���� � ��������� ��� ������ ��� ������ � ����
			exception ex("������ ��� ������ ���!");
			throw ex;
		}
		fout << size << endl; //������ �������		����������
			for (int i = 0; i < size; ++i) { //������ ���� ��������� ����������
				fout << ptr_mas[i] << endl;
			}
		fout.close();
		cout << "������ � ���� ������ �������" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}
template<class T>
void Keeper<T>::readFromFile(string s) {
	try {
		ifstream fin(s, ios::in);
		if (!fin) {
			exception ex("�� ������� ������� ����!");
			throw ex;
		}
		delete[] ptr_mas; //������� ������, ��� ���		����� �������� ������ �� �����
			fin >> size; //���������		������ ���������� � �����
			ptr_mas = new T[size]; //������� ������		�������� ���������� � �����
			for (int i = 0; i < size; ++i) { //��������� ��� �������� �� �����
				fin >> ptr_mas[i];
			}
		fin.close();
		cout << "������ �� ����� ������ �������" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}
template<class T>
void Keeper<T>::displayData() {
	if (size == 0) { //���� ��������� ����
		cout << "������ ���!" << endl << endl;
	}
	else {
		for (int i = 0; i < size; ++i) { //������ ��� �������� ���������� �� �����
			cout << ptr_mas[i] << endl;
		}
	}
}
template<class T>
void Keeper<T>::dataChange(int id) {
	try {
		if (size == 0) { //���� ��������� ����
			exception ex("������ ���!");
			throw ex;
		}
		if (id < 0 || id >= size) { //������������ ������
			exception ex("������������ ������!");
			throw ex;
		}
		cin >> ptr_mas[id]; //������ �����		������ ���������� ��������
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl; //����� ������ �� �����
	}
}