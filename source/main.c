#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "game.h"
#include "functions.h"

int main(int argc, char *argv[]) {

	setlocale(LC_ALL, "Rus");

	int opt;

	while (1) {
		opt = mainMenu();
		switch (opt) {
			case 1:
				opt = newGameMenu();
				switch (opt) {
				case 1:
					newGame(1);
					break;
				case 2:
					newGame(2);
					break;
				case 3:
					break;
				default:
					system("cls");
					printf("������� ������ �����������! ����� � ������� ����\n");
					break;
				}
				break;
			case 2:
				system("cls");
				printf("������� ��������:\n������� ����: %d �� %d\n\n", checkStringsNum(2), checkStringsNum(1)+ checkStringsNum(2));
				system("PAUSE");
				break;
			case 3:
				return 0;
				break;
			default:
				printf("������� ������ �����������!\n");
		}
	}

}