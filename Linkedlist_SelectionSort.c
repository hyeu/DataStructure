#include <stdio.h>
#include <stdlib.h>

// 구조체 정의(linked list 구현)
typedef struct LinkedList {
	int data;
	struct LinkedList* link;
}LinkedList;

// 리스트의 처음
struct LinkedList* head = NULL;

// 함수 정의
void Insert(int data, int position);
void SelectionSort(LinkedList* head);

int main() {

	// 각 숫자를 순서대로 리스트에 삽입하기
	Insert(96, 1);
	Insert(4, 2);
	Insert(26, 3);
	Insert(49, 4);
	Insert(75, 5);
	Insert(103, 6);
	Insert(43, 7);
	Insert(42, 8);
	Insert(21, 9);
	Insert(7, 10);
	Insert(15, 11);
	Insert(97, 12);
	Insert(13, 13);
	Insert(11, 14);
	Insert(8, 15);
	Insert(48, 16);

	// 정렬 전의 리스트 순서대로 출력
	printf("정렬 전: ");
	LinkedList* f = head;
	for (int i = 0; i < 16; i++) {
		printf("%d", f->data);
		f = f->link;
		printf(" ");
	}

	printf("\n");

	// 리스트의 맨 앞부터 차례대로 정렬
	SelectionSort(head);

	// 정렬 후의 리스트를 차례대로 출력
	printf("정렬 후: ");
	LinkedList* a = head;
	for (int i = 0; i < 16; i++) {
		printf("%d", a->data);
		a = a->link;
		printf(" ");
	}
	printf("\n");
	system("PAUSE");
}

void Insert(int data, int position) {

	// 정렬할 숫자 리스트를 담을 리스트 생성
	LinkedList* temp = (LinkedList*)malloc(sizeof(LinkedList));

	// 숫자 
	temp->data = data;
	// 리스트 연결 링크
	temp->link = NULL;

	// 리스트의 맨 앞 설정
	if (position == 1) {
		temp->link = head;
		head = temp;
		return;
	}
	LinkedList* insert = head;

	// 숫자를 순서대로 리스트로 연결
	for (int i = 0; i < position - 2; i++) {
		insert = insert->link;
	}
	temp->link = insert->link;
	insert->link = temp;

}

// selection sort 함수 정의
void SelectionSort(LinkedList* head) {
	struct LinkedList* i;
	struct LinkedList* j;
	int temp;

	i = head;

	//비교하는 두 수 중 더 앞에 위치하는 수
	for (i = head; i->link != NULL; i = i->link) {
		// 비교하는 두 수 중 더 뒤에 위치하는 수
		for (j = i->link; j->link != NULL; j = j->link) {
			// 앞에 위치한 수가 뒤의 수보다 크면 swap
			if (i->data > j->data) {
				// swap
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
		// 마지막에 위치한 숫자 비교
		if (j->link == NULL)
			if (i->data > j->data) {
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
	}
}
