#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//linked list 설정
typedef struct LinkedList {
	int data;
	struct LinkedList* link;
}LinkedList;

// list의 앞 설정
struct LinkedList* head = NULL;

//함수 정의 
void Insert(int data, int position);
struct LinkedList* BinarySearch(int searchnum);


int main() {
	// linked list에 숫자 집어넣기
	Insert(4, 1);
	Insert(7, 2);
	Insert(8, 3);
	Insert(11, 4);
	Insert(13, 5);
	Insert(15, 6);
	Insert(21, 7);
	Insert(26, 8);
	Insert(42, 9);
	Insert(43, 10);
	Insert(48, 11);
	Insert(49, 12);
	Insert(75, 13);
	Insert(96, 14);
	Insert(97, 15);
	Insert(103, 16);

	// 찾을 값 
	int searchnum; 
	// 사용자로부터 숫자 입력받기 
	printf("찾을 숫자를 입력하세요:");
	scanf("%d", &searchnum);

	BinarySearch(searchnum);

	// 창이 자동으로 닫히는 것을 방지 
	system("PAUSE");

}
/* 리스트에 숫자 삽입하는 함수 정의. 나중에 위치를 알아야 하기 때문에
위치를 변수 position에 저장 */
void Insert(int data, int position) {
	//숫자 리스트를 담을 리스트 생성
	LinkedList* temp = (LinkedList*)malloc(sizeof(LinkedList));
	//숫자
	temp->data = data;
	//리스트를 연결할 링크
	temp->link = NULL;

	//리스트의 맨 앞
	if (position == 1) {
		temp->link = head;
		head = temp;
		return;
	}
	//리스트에 차례대로 숫자 집어넣기
	LinkedList* insert = head;
	for (int i = 0; i < position - 2; i++) {
		insert = insert->link;
	}
	temp->link = insert->link;
	insert->link = temp;

}
// 중간값 찾기
struct LinkedList* middle(LinkedList* left, LinkedList* right) {
	//리스트가 비었을 때
	if (left == NULL) {
		return NULL;
	}
	// 중간값을 찾기 위해 두 개의 값 설정 
	LinkedList* slow = left;
	LinkedList* fast = left->link;
	// 중간값 찾기
	while (fast != NULL) {
		fast = fast->link;
		if (fast != NULL) {
			slow = slow->link;
			fast = fast->link;
		}
	}
	return slow;
}
// 위에서 찾은 중간값을 이용하여 이진탐색
struct LinkedList* BinarySearch(int searchnum) {
	// 맨 왼쪽과 맨 오른쪽 설정
	LinkedList* left = head;
	LinkedList* right = NULL;

	do {
		// 중간값
		LinkedList* mid = middle(left, right);

		// 리스트가 비었을 때
		if (mid == NULL)
			return NULL;
		// 중간값과 찾는 값이 같을 때 
		if (mid -> data == searchnum) {
			printf("list에 %d가 존재합니다.", searchnum);
			printf("\n");
			// 찾는 값의 정확한 위치를 찾아주기 위해
			LinkedList* f = head;
			for (int pos = 1; pos < 17; pos++) {
				if (f->data == mid->data) {
					printf("%d(은)는 %d번째 위치에 있습니다.", searchnum, pos);
					printf("\n");
					return 0;
				}
				else
					f = f->link;
			}
			break;
		}
		// 중간값보다 찾는값이 클 경우 왼쪽값을 중간값의 다음으로 설정
		else if (mid->data < searchnum)
			left = mid->link;
		//중간값보다 찾는값이 작을 경우 오른쪽값을 중간값으로 설정
		else if(mid->data > searchnum)
			right = mid;
	} while (right == NULL || right->link != left);
	return NULL;
}
