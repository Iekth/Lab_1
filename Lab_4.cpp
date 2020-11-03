#include <stdio.h>
#include <locale.h>
#include <windows.h>
#define SIZE 9


int main() {

	int arr[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
	int i, j, g;

	setlocale(LC_ALL, "Russian"); //ðóñèôèêàöèÿ

	//ââîä ÷èñåë âðó÷íóþ
	
	for (i = 0; i < SIZE; i++) {
		printf("ââåäèòå ýëåìåíò, ïîæàëóéñòà  ");
		scanf_s("%d", &arr[i]);
	}
	system("CLS"); 

	//âûâîä ââåäåííûõ ÷èñåë
	printf("èçíà÷àëüíûå ÷èñëà:");
	for (i = 0; i < SIZE; i++) {
		printf("%2d", arr[i]);
	}

	for (i = 0; i < SIZE; i++) {
		g = arr[i]; 
		j = i + 1; 

		if (arr[i] < arr[j]) { 
			arr[i] = arr[j];

		}
		else {
			j++; //ðàññìàòðèâàåì ñëåäóþùåå ÷èñëî
			for (j; j < SIZE; j++) {
				if (arr[i] < arr[j]) {
					arr[i] = arr[j];
				}
			}
		}

		if (arr[i] == g) 
			arr[i] = 0;
	}

	printf("\n   êîíå÷íûå ÷èñëà:"); //âûâîä ðåçóëüòàòà
	for (i = 0; i < SIZE; i++) {
		printf("%2d", arr[i]);
	}
}
