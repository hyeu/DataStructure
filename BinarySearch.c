#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//찾을 값 정의
	int key_value;
	int mid = 0;

	// 배열
	int arr[] = { 4, 7, 8, 11, 13, 15, 21, 26, 42, 43, 48, 49, 75, 96, 97, 103 };

	//5개의 숫자를 찾기 위해 loop돌리기
	for (int i = 1; i < 6; i++) {
		printf("%d번째 찾을 숫자를 입력하세요:", i);
		scanf("%d", &key_value);

		// 맨 앞과 맨 뒤 숫자 
		int left = 0;
		int right = 15;

		while (1) {
			// mid가 배열의 가운데일 때
			mid = (left + right) / 2;
			// 만약 찾는 값이 mid보다 크면 왼쪽 값을 mid+1
			if (key_value > arr[mid])
				left = mid + 1;
			// 만약 찾는 값이 mid보다 작으면 오른쪽 값을 mid-1
			else if (key_value < arr[mid])
				right = mid - 1;
			else
				break;
		}
		//위치 출력
		printf("%d(은)는 %d번째에 있습니다.", key_value, mid + 1);
		printf("\n");
	}
	//칭이 자동으로 닫히는 것을 방지
	system("PAUSE");
}
