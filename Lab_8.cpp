#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char* words; //Массив символов(содержит найденные симметричные слова)
char** sentences;
int num = 0; //Индекс элемента в массиве words
int len = 0; //Длина массива words (45 - самое большое слово в английском алфавите, но это не точно..
int* sizeOfsentence;
int status = 1; //Статус симметрии
int sizeOfword = 0; //Кол-во букв в слове
int countOfsentences = 0; //Кол-во предложений
int countOfwords = 0; //Кол-во симметричных слов
// Текст для отладки тенет овыф выа ывалж ыар sefsdkj fdjlksjdf ds d 2323 9ir023r0 fj9fJH 0E0(EFJ)(ef0E*)F(^F*&DT FG D*S&FDS&*D 3333 #$$# Дед А Б В ЛОЛ fgd df
// uyguY VBGEDF*y O*VDB FYTS* VDBFYHN SDYFSU*YOL*DYFTS^&$^W*TW GHF*SDFG S*DF GTSD*F ШРПВЫГ ИПЫВ*(ПА ?вып 8аыпв тенет НЕТ ТЕНЕТ НЕЕН рШАР ЫЫШФР ?* Н*?РЦА*?А*

int isAlpha(unsigned char);
void addLetter(char);
void shutDown();

int main() {
	system("chcp 1251");
	setlocale(LC_ALL, "RU");
	words = (char*)calloc(len, sizeof(char));
	if (!words) printf("shit1");

	printf("Введите количество предложений :");
	scanf_s("%d", &countOfsentences);
	rewind(stdin);
	sizeOfsentence = (int*)calloc(countOfsentences, sizeof(int));
	if (!words) printf("shit2");
	sentences = (char**)calloc(countOfsentences, sizeof(char*));
	if (!words) printf("shit3");

	for (int s = 0; s < countOfsentences; ++s) {
		printf("Введите размер предложений %d:", s + 1);
		scanf_s("%d", &sizeOfsentence[s]);
		rewind(stdin);

		sentences[s] = (char*)calloc(++sizeOfsentence[s], sizeof(char));
		printf("Введите предложение:");
		fgets(sentences[s], sizeOfsentence[s], stdin);
		rewind(stdin);

		for (int z = 0; z < sizeOfsentence[s]; ++z) {
			sizeOfword = 0;
			status = 1; //Сброс значений по умолчанию

			if (isAlpha(sentences[s][z])) { //Если буква, то считаем размер слова
				if (z == 0) { //Страшные проверки
					for (int i = z; i < sizeOfsentence[s]; ++i) {
						if (!isAlpha(sentences[s][i])) break;
						sizeOfword++;
					}
					if (sizeOfword <= sizeOfsentence[s] - 2) {
						if (sentences[s][z + sizeOfword] != ' ') {
							continue;
						}
					}
				}
				else {
					if (sentences[s][z - 1] == ' ') {
						for (int i = z; i < sizeOfsentence[s]; ++i) {
							if (!isAlpha(sentences[s][i])) break;
							sizeOfword++;
						}
					}
					if (sentences[s][z - 1] == ' ' && sentences[s][z + sizeOfword] != ' ') {
						if (sentences[s][z + sizeOfword] != '\n' && (z + sizeOfword < sizeOfsentence[s] - 1)) {
							continue;
						}
					}
				}
			}
			if (sizeOfword > 0) {
				int j = z + sizeOfword - 1; //Последняя буква в слове
				for (int i = z; i < z + sizeOfword; ++i) { //Проверка на симметричность
					if (sentences[s][i] != sentences[s][j] && (int)sentences[s][i] + 32 != (int)sentences[s][j] && (int)sentences[s][i] != (int)sentences[s][j] + 32) { //Проверка для заглавных
						status = 0;
						break;
					}
					j--;
				}
				z += sizeOfword; //Главный цикл(идёт по предложению) пропускает проверенное слово

				if (status) { //Копируем слово циклом в другой массив(words) и выводим его
					printf("( ");
					for (int i = z - sizeOfword; i < z; ++i) {
						addLetter(sentences[s][i]);
						printf("%c", sentences[s][i]);
					}
					addLetter(' '); //Добавляем пробел в массив words для читаемости
					countOfwords++; //Добавляем +1 к кол-ву симметричных слов
					printf(" ) - Слово симметрично\n");
				}
				else {
					printf("Слово не симметрично\n");
				}
			}
		}
	}

	printf("\nМассив симметричных слов во всех предложениях - ( ");
	for (int i = 0; i < len; ++i) {
		printf("%c", words[i]);
	}
	

	shutDown();
	return 0;
}

int isAlpha(unsigned char sym) { //Функция для проверки на русские и английские буквы
	if (((int)sym >= 65 && (int)sym <= 90) || ((int)sym >= 97 && (int)sym <= 122)) return 1;
	if (((int)sym >= 192 && (int)sym <= 255)) return 1;
	return 0;
}

void addLetter(char sym) { //Функция для добавления

	
		//words = (char *)realloc(words, ++len * sizeof(char));
		char* tmp = (char*)realloc(words, ++len * sizeof(char));
	if (tmp) {
		words = tmp; //Увеличиваем размер массива words
		//free(tmp); Вроде как уничтожается, но .. его знает
	}
	else {
		printf("Realloc error");
		free(tmp);
		shutDown();
	}
	words[num] = sym;
	num++;
}

void shutDown() { //Освобождение памяти (вынесено в функцию для экстренного завершения программы в случае ошибок выделения памяти)
	free(words);
	free(sizeOfsentence);
	for (int i = 0; i < countOfsentences; ++i) {
		free(sentences[i]);
	}
	free(sentences);
}
