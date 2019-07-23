#include <stdio.h>

int main() {
	// 정렬할 배열
	int arr[] = { 96, 4, 26, 49, 75, 103, 43, 42, 21, 7, 15, 97, 13, 11, 8, 48 };

	// 정렬 전 배열 출력
	printf("정렬 전 배열:");
	for (int i = 0; i < 16; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	int min, temp;

	// 정렬
	// 두 수 중 앞에 위치한 숫자
	for (int i = 0; i < 15; i++) {
		min = i;
		// 두 수 중 뒤에 위치한 숫자
		for (int j = i + 1; j < 16; j++) {
			// 앞의 숫자가 뒤의 숫자보다 크다면 뒤의 숫자가 있는 위치를 변수 min에 저장
			if (arr[min] > arr[j])
				min = j;
		}
		// 위치 바꾸기(swap)
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}

	// 정렬 후 배열 출력
	printf("정렬 후 배열:");
	for (int i = 0; i < 16; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("PAUSE");
}
