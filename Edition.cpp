#include "Edition.h"
//���������� ���������� � ������
void Edition::addArtworks(string name) {
	Artworks* tmp = new Artworks;
	tmp->name = name;
	if (head == NULL)
		head = tmp;
	else {
		tmp->nextArtworks = head;
		head = tmp;
	}
	++countArtworks;
}
/*void Edition::deleteArtworks(int index) {
	try {
		if (index < 0 || index >= countArtworks)
			throw exception("������������ ������!"); //�������� ������� �� �������� � �����		�� �����			
		Artworks* current = head;
		if (index == 0) { //������� ������ �������
			head = head->nextArtworks;
			delete current;
		}
		else { //���� ����������			�������
				for (int i = 0; i < index - 1; ++i)
					current = current->nextArtworks;
			//����� current ����� ��������� �� ������� ����� ���������, ������� ���� �������
			Artworks* tmp = current->nextArtworks; //tmp ��������� �� �������,			������� ���� �������
			current->nextArtworks = tmp->nextArtworks; //���������� ������� ��			���������� �������� ��������� �� ������� ����� ����������
				delete tmp;
			//������� �������
		}
		--countArtworks;
	}
	catch (exception& ex) { //������ �� ������ ������ �������
		cout << ex.what() << endl << endl; //����� ������� ������������ ����
	}
}*/