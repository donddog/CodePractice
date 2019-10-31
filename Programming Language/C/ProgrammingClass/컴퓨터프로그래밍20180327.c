#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#define N 5

double distance;
double caldis(int x, int y);

/*int main(void) {

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

int main() {
	
	int x, y;
	char input;
	char a, w, s, d;

	srand(time(NULL));

	x = (rand() % N) + 1;
	y = (rand() % N) + 1;

	printf("��ǥ�� x = %d, y = %d \n", x, y);
	
	while (1) {
		printf("������ ��ǥ : \n");
		input = getch();
		printf("\n");
		if (input == 'a') {
			if (x > 1) {
				x--;
				printf("�������� �� ĭ �����Դϴ�. \n");
				printf("��ǥ�� x = %d, y = %d / �Ÿ��� : %f \n", x, y, caldis(x, y));
			}
			if (x == 1) {
				printf("������ �� �����ϴ�. \n");	
			}
		}
		if (input == 'd') {
			if (x < N) {
				x++;
				printf("���������� �� ĭ �����Դϴ�. \n");
				printf("��ǥ�� x = %d, y = %d / �Ÿ��� : %f \n", x, y, caldis(x, y));
			}
			if (x == N) {
				printf("������ �� �����ϴ�. \n");
			}
		}
		if (input == 'w') {
			if(y > 1) {
				y--;
				printf("�������� �� ĭ �����Դϴ�. \n");
				printf("��ǥ�� x = %d, y = %d / �Ÿ��� : %f \n", x, y, caldis(x, y));
			}
			if (y == 1) {
				printf("������ �� �����ϴ�. \n");
			}
		}
		if (input == 's') {
			if(y < N) {
				y++;
				printf("�Ʒ������� �� ĭ �����Դϴ�. \n");
				printf("��ǥ�� x = %d, y = %d / �Ÿ��� : %f \n", x, y, caldis(x, y));
			}
			if (y == N) {
				printf("������ �� �����ϴ�.\n");
			}
		}
			//move down
		if (input == 'x') break;
		}
		printf("���α׷� ���� \n");
		return 0;
	}

double caldis(int x, int y) {
	double distance;
	distance = sqrt(((x - 1) * (x - 1)) + ((y - 1) * (y - 1)));
	return distance;
}