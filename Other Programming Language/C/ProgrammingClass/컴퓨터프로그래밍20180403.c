#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#define N 5

double distance;
double caldis(int x, int y, int tx, int ty);

/* �Ÿ��� ���ϴ� ����
int main(void) {

	int x, y;
	double a;

	srand(time(NULL));

	x = (rand() % N) + 1;
	y = (rand() % N) + 1;
	printf("��ǥ�� x = %d, y = %d \n", x, y);

	a = sqrt(((x - 1) * (x - 1)) + ((y - 1) * (y - 1)));
	printf("�����Ÿ� a = %f \n", a);

	return 0;
}*/

int main(void) {
	int tx, ty;
	int x, y;
	char input;
	char a, w, s, d;
	int score,  energy, i;
	
	score = 0;
	int temp = 10;
	energy = temp;

	srand(time(NULL));

	x = (rand() % N) + 1;
	y = (rand() % N) + 1;
	tx = (rand() % N) + 1;
	ty = (rand() % N) + 1;

	if (x == tx, y == ty) {
		tx = (rand() % N) + 1;
		ty = (rand() % N) + 1;
	}
	printf("��ǥ�� x = %d, y = %d �������� �Ÿ��� %f \n", x, y, caldis(x,y,tx,ty));
	printf("���� �������� : %d \n", energy);
	
	while (1) {
			printf("������ ��ǥ : \n");
			input = getch();
			printf("\n");


			if (input == 'a') {
				if (x > 1) {
					x--;
					printf("�������� �� ĭ �����Դϴ�. \n");
					printf("��ǥ�� x = %d, y = %d / �Ÿ��� : %f \n", x, y, caldis(x, y, tx, ty));
					energy--;
					printf("������ �ܷ� : %d \n", energy);
					if (energy == 0) {
						printf("GAME OVER, total score : %d \n", score);
						system("pause");
						break;
					}
				}
				if (x == 1) {
					printf("������ �� �����ϴ�. \n");
				}
			}
			if (input == 'd') {
				if (x < N) {
					x++;
					printf("���������� �� ĭ �����Դϴ�. \n");
					printf("��ǥ�� x = %d, y = %d / �Ÿ��� : %f \n", x, y, caldis(x, y, tx, ty));
					energy--;
					printf("������ �ܷ� : %d \n", energy);
					if (energy == 0) {
						printf("GAME OVER, total score : %d \n", score);
						system("pause");
						break;
					}
				}
				if (x == N) {
					printf("������ �� �����ϴ�. \n");
				}
			}
			if (input == 'w') {
				if (y > 1) {
					y--;
					printf("�������� �� ĭ �����Դϴ�. \n");
					printf("��ǥ�� x = %d, y = %d / �Ÿ��� : %f \n", x, y, caldis(x, y, tx, ty));
					energy--;
					printf("������ �ܷ� : %d \n", energy);
					if (energy == 0) {
						printf("GAME OVER, total score : %d \n", score);
						system("pause");
						break;
					}
				}
				if (y == 1) {
					printf("������ �� �����ϴ�. \n");
				}
			}
			if (input == 's') {
				if (y < N) {
					y++;
					printf("�Ʒ������� �� ĭ �����Դϴ�. \n");
					printf("��ǥ�� x = %d, y = %d / �Ÿ��� : %f \n", x, y, caldis(x, y, tx, ty));
					energy--;
					printf("������ �ܷ� : %d \n", energy);
					if (energy == 0) {
						printf("GAME OVER, total score : %d \n", score);
						system("pause");
						break;
					}
				}
				if (y == N) {
					printf("������ �� �����ϴ�.\n");
				}
			}
			for (i = 10; i >0; i--) {
				energy == i;
				if (x == tx && y == ty) {
					printf("�����մϴ�. ������ ã���̽��ϴ�. \n");
					score++;
					printf("score : %d \n", score);
					printf("���� ���带 �����մϴ�. \n");
					system("pause");
					tx = (rand() % N) + 1;
					ty = (rand() % N) + 1;
					if (x == tx, y == ty) {
						tx = (rand() % N) + 1;
						ty = (rand() % N) + 1;
					}
					energy = --temp;

					printf("���� ��ġ�� x = %d, y = %d �Դϴ�. �������� �Ÿ��� %f \n", x, y, caldis(x, y, tx, ty));
					printf("���� �������� : %d \n", energy);

					if (energy == 0) {
						printf("WIN, final score : %d \n", score);
					}
				}
			}
			//move down
			if (input == 'x') break;
		}

	printf("���α׷� ���� \n");
	return 0;
}

double caldis(int x, int y, int tx, int ty) {
	double distance;
	distance = sqrt(((x - tx) * (x - tx)) + ((y - ty) * (y - ty)));
	return distance;
}