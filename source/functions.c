#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int mainMenu() {
	
	setlocale(LC_ALL, "Rus");

	system("cls");

	int opt;
	printf("1. Новая игра\n2. Текущий прогресс\n3. Выход\n\nВыберите действие: ");
	scanf("%d", &opt);

	return opt;

}

int newGameMenu() {

	setlocale(LC_ALL, "Rus");

	system("cls");

	int opt;
	printf("1. Изучение новых слов\n2. Повторенее изученного\n3. Выход в главное меню\n\nВыберите действие: ");
	scanf("%d", &opt);

	return opt;

}

int checkStringsNum(int fl) {

	FILE *f;
	if (fl == 1) {
		f = fopen("../source/vocabulary.txt", "r");
	}
	else {
		f = fopen("../source/studied.txt", "r");
	}

	char ch;
	int num = 0;

	while (!feof(f)) {
		ch = getc(f);
		if (ch == '.') {
			num++;
		}
	}

	fclose(f);

	return num;

}

void wordsMass(int fl, char **eng, char **rus, int num) {
	
	FILE *f;
	if (fl == 1) {
		f = fopen("../source/vocabulary.txt", "r");
	}
	else {
		f = fopen("../source/studied.txt", "r");
	}

	char ch;
	int symb;

	for (int i = 0; i < num; i++) {

		symb = 0;
		ch = getc(f);
		while (ch != '.' && (!feof(f))) {
			eng[i][symb] = ch;
			symb++;
			ch = getc(f);
		}
		eng[i][symb] = '\0';

		symb = 0;
		ch = getc(f);
		while ((ch != '\n') && (!feof(f))) {
			rus[i][symb] = ch;
			symb++;
			ch = getc(f);
		}
		rus[i][symb] = '\0';

	}

	fclose(f);

	return;

}