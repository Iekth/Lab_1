#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
#include<locale.h>
//��-�������� �� ��� ���������� ��������� � ���������...
int num = 0; //������ �������� � ������� words
int len = 0;
char* words; //������ ��������(�������� ��������� ������������ �����) 
//int bb;
int yy;
void addLetter(char);
int main() {
	setlocale(0, "Russian");
	int g, z, r, kol = 0, kol1 = 0, po = 0, status = 0, end1, vv, cc, bb, er;
	int w, n1, i, j, k, n, m;
	char** str, * xx;
	printf("Vvedite kol-vo matric:\n");
	scanf_s("%d", &n1);
	fflush(stdin);
	printf("Vvedite kol-vo strok v matrice:\n");
	scanf_s("%d", &n);
	fflush(stdin);
	printf("Vvedite kol-vo stolbcov v matrice:\n");
	scanf_s("%d", &m);
	fflush(stdin);
	printf("Vvedite razmer stroki:\n");
	scanf_s("%d", &k);
	fflush(stdin);
	k += 2;
	yy = k;
	getchar();
	fflush(stdin);
	for (w = 1; w <= n1; w++) {//��� �������� �� ��������
		str = (char**)malloc(n * sizeof(char*));//��� �������� ��������� ������������ �������
		if (!(str = (char**)malloc(n * sizeof(char*))))
			return 0;
		g = w;
		printf("Vvod %d matrici:\n", w);
		for (i = 0; i < n; i++) {
			str[i] = (char*)malloc(m * sizeof(char));
			if (!(str[i] = (char*)malloc(m * sizeof(char)))) {
				free(str[i]);
				free(str);
				return 0;
			}
			for (j = 0; j < m; j++) {
				xx = &str[i][j];//���������� ��������� ����� ��������(� ��� ����� ���)
				xx = (char*)malloc(k * sizeof(char));//����� ������������ ������ �� ����� ���������
				if (!(xx = (char*)malloc(k * sizeof(char)))) {
					free(xx);
					return 0;
				}
				//getchar();
				fgets(xx, k, stdin);//����� ������ ��� ����� �������� �������(���������)
				//getchar();
				fflush(stdin);
				z = 0;
				while (xx[z] != '\0' && xx[z] != '\n') {
					if (xx[z] == ' ') {//���� ������-���������� �� �������� �� �����
						while (xx[z] == ' ') {
							kol1++;
							z++;
							if (xx[z] == '\0')
								break;
						}
					}
					if (xx[z] != ' ' && xx[z] != '\0' && xx[z] != '\n') {//����� �����-������� ������� ������� �� � �����
						r = z;
						bb = r;
						er = bb;
						while (xx[z] != ' ' && xx[z] != '\0' && xx[z] != '\n') {//������� ����??
							kol++;
							z++;
						}

						if (kol > 2) {//����������� ������� �������� ��� 3 �����

							if (kol > 2 && kol % 2 == 0) {//������� ��� ���� � ������� ����������� ����
								end1 = r + kol - 1;//����� �����
								while (status == 0) {
									if (xx[r] != xx[end1]) {
										kol = 0;
										break;
									}
									if (xx[r] == xx[end1]) {//�������� �������������� ���� 
										r++;//������� � ������ ���� �����
										end1--;//����� � ������� ���� �����
										if (r + 1 == end1 && xx[r] == xx[end1]) {//���� �� ������� � �� �������� ��� ������� � �������� �����-������������� ������� �����
											if (status == 0) { //�������� ����� ������ � ������ ������(words) � ������� ��� 
												for (bb; bb <= er + kol - 1; bb++) {
													addLetter(xx[bb]);

												}
												addLetter(' '); //��������� ������ � ������ words ��� ���������� 
											}
											po++;
											status = 0;
											kol = 0;
											break;
										}
									}
								}
							}


							if (kol > 2 && kol % 2 != 0) {//��� �������� ����
								end1 = r + kol - 1;
								vv = kol / 2;//������ �������� ����� (� �����������)
								cc = r;
								while (status == 0) {
									if (xx[r] != xx[end1]) {
										kol = 0;
										break;
									}
									if (xx[r] == xx[end1]) {
										if (kol == 3) {
											if (status == 0) { //�������� ����� ������ � ������ ������(words) � ������� ��� 
												for (bb; bb <= er + kol - 1; bb++) {
													addLetter(xx[bb]);
												}
												addLetter(' '); //��������� ������ � ������ words ��� ���������� 
											}
											kol = 0;
											po++;
											break;
										}
										r++;
										end1--;
										if (r + 1 == cc + vv && xx[r] == xx[end1]) {//������� �� ������� ������������ � �������� ����� ���� �������� ��������(�������� 3 � 5)
											if (status == 0) { //�������� ����� ������ � ������ ������(words) � ������� ��� 
												for (bb; bb <= er + kol - 1; bb++) {
													addLetter(xx[bb]);
												}
												addLetter(' '); //��������� ������ � ������ words ��� ���������� 
											}
											po++;
											status = 0;
											kol = 0;
											break;
										}
									}
								}
							}
							kol = 0;
						}
						kol = 0;
					}
				}
			}
		}
	}
	//printf("po==%d",po); ��� ���-�� ����� ����
	printf("\n���� ��������������- \n ");
	for (int t = 0; t < len; ++t) {
		printf("%c", words[t]);
	}
	return 0;
}
void addLetter(char sym) { //������� ��� ���������� ������� � ������ words 
	words = (char*)realloc(words, ++len * sizeof(char));//len ������ ������������� �� 1 ��� ��� �������� �� 1 ����� � ����� � int main
	if (!words) {
		free(words);
		return ;
	}

	char* tmp = (char*)realloc(words, ++len * sizeof(char));
	if (tmp) {
		words = tmp; //����������� ������ ������� words
		free(tmp);
	}
	else {
		printf("Realloc error");
		free(tmp);

	}
	words[num] = sym;
	num++;

}