#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include "functions.h"

void answQue(int fl, char **eng, char **rus, int num) {

	if (num < 5) {
		printf("Недостаточно слов для теста!\n\n");
		system("PAUSE");
		return;
	}

	FILE *f;

	int k;
	int *ws;

	system("cls");
	if (fl == 1) {
		printf("Сколько слов хотите выучить (<%d)? ", num + 1);
	}
	else {
		printf("Сколько слов хотите повторить (<%d)? ", num + 1);
	}
	scanf("%d", &k);
	while ((k < 1) || (k > num)) {
		printf("Введите еще раз (0>k>%d): ", num + 1);
		scanf("%d", &k);
	}
	ws = (int*)malloc(k * sizeof(int));
	for (int i = 0; i < k; i++) {
		ws[i] = rand() % num;
		for (int j = i - 1; j >= 0; j--) {
			if (ws[i] == ws[j]) {
				ws[i] = rand() % num;
				j = i;
			}
		}
	}

	system("cls");

	printf("Ознакомьтесь со словами:\n\n");
	for (int i = 0; i < k; i++) {
		printf("%s - %s\n", eng[ws[i]], rus[ws[i]]);
	}
	printf("\n");
	system("PAUSE");

	if (fl == 1) {
		f = fopen("../source/studied.txt", "a+");
	}

	int var[4];
	int n;
	int answ;
	int sum = 0;
	for (int i = 0; i < k; i++) {
		n = rand() % 4;
		for (int j = 0; j < 4; j++) {
			var[j] = rand() % num;
			for (int z = j - 1; z >= 0; z--) {
				if ((var[j] == var[z]) || (var[j] == ws[i])) {
					var[j] = rand() % num;
					z = j;
				}
			}
		}
		var[n] = ws[i];
		system("cls");
		printf("%d из %d\n\n%s:\n1: %s\n2: %s\n3: %s\n4: %s\n\n", i + 1, k, eng[ws[i]], rus[var[0]], rus[var[1]], rus[var[2]], rus[var[3]]);
		printf("Выберите вариант(1-4): ");
		scanf("%d", &answ);
		if (answ == n + 1) {
			if (fl == 1) {
				fprintf(f, "%s.%s\n", eng[ws[i]], rus[ws[i]]);
				eng[ws[i]] = "0";
			}
			sum++;
		}
	}

	if (fl == 1) {
		fclose(f);

		f = fopen("../source/vocabulary.txt", "w");
		for (int i = 0; i < num; i++) {
			if (strcmp(eng[i], "0") != 0 ) {
				fprintf(f, "%s.%s\n", eng[i], rus[i]);
			}
		}
		fclose(f);
	}

	printf("\nВерных ответов: %d из %d\n\n", sum, k);

	free(ws);

	system("PAUSE");
	return;

}

void newGame(int fl) {

	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int num;
	
	num = checkStringsNum(fl);

	char **eng;
	char **rus;
	eng = (char**)malloc(num * sizeof(char*));
	for (int i = 0; i < num; i++) {
		eng[i] = (char*)malloc(40 * sizeof(char));
	}
	rus = (char**)malloc(num * sizeof(char*));
	for (int i = 0; i < num; i++) {
		rus[i] = (char*)malloc(40 * sizeof(char));
	}

	wordsMass(fl, eng, rus, num);

	answQue(fl, eng, rus, num);

	for (int i = 0; i < num; i++) {
		free(eng[i]);
	}
	free(eng);

	for (int i = 0; i < num; i++) {
		free(rus[i]);
	}
	free(rus);

	return;

}
