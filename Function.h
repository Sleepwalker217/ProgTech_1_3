#pragma once
#include "Keeper.h"
#include "Poet.h"
#include "Fantasist.h"
#include "Romanticist.h"
#include <iostream>
using namespace std;
template <typename T>
void menuOfEdition(T& obj, string s) { //�������� �������, ������� �������� � ���� ��� ����� (�������� �� 	������ ����)
	int button;
	int id;
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "�������� ��������: " << endl << endl;
		cout << "1 - �������� ������" << endl;
		cout << "2 - ������� ������" << endl;
		cout << "3 - ����� ������ �� ��������" << endl;
		cout << "4 - ��������� ������" << endl;
		cout << "5 - ���������� � ����" << endl;
		cout << "6 - �������������� �� �����" << endl;
		cout << "0 - ����� � �������� ����" << endl << endl;
		cout << "�������� �������: ";
		cin >> button;
		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		system("cls");
		switch (button) {
		case 1: obj.displayData(); cout << "�� ����� ����� �������� ����� �������: "; cin >> id;
			obj.addElement(id); system("pause"); break;
		case 2: obj.displayData(); cout << "����� ������� �������: "; cin >> id; obj.deleteElement(id);
			system("pause"); break;
		case 3: obj.displayData(); system("pause"); break;
		case 4: obj.displayData(); cout << "����� ������� ��������: "; cin >> id; obj.dataChange(id);
			system("pause"); break;
		case 5: obj.writeToFile(s); system("pause"); break;
		case 6: obj.readFromFile(s); system("pause"); break;
		case 0: flag = false; break;
		default: cout << "������� ������������ �������!" << endl << endl; system("pause"); break;
		}
	}
}