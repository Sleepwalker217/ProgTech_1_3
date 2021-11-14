#include "Function.h"
int main() {
	setlocale(LC_ALL, "");
	Keeper<Poet> poet; //�������� ���������� ������ (��� ������ Poet), ���������� ����������� Keeper ()
	Keeper<Romanticist> romanticist;//�������� ���������� ������ (��� ������ romanticist), ���������� ����������� Keeper ()
	Keeper<Fantasist> fantasist;//�������� ���������� ������ (��� ������ fantasist), ���������� ����������� Keeper ()
	int button;
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "�������� ��������: " << endl << endl;
		cout << "1 - ����" << endl;
		cout << "2 - ���������" << endl;
		cout << "3 - �������" << endl;
		cout << "0 - ����� �� ���������" << endl << endl;
		cout << "�������� �������: ";
		cin >> button;
		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (button) {
		case 1: menuOfEdition(poet, "Poet.txt"); break; // ��������� ����, ���� - ��� � ���� �������
		case 2: menuOfEdition(romanticist, "Romanticist.txt"); break;
		case 3: menuOfEdition(fantasist, "Fantasist.txt"); break;
		case 0: flag = false; break;
		default: cout << endl << "������� ������������ �������!" << endl << endl; system("pause");
			break;
		}
	}
	return 0;
}