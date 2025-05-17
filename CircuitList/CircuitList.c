

#include <stdio.h>
#include <stdlib.h>

#include "CircuitList.h"

void menuList()
{
	printf("\n======  Linked_List Menu  ======\n");
	printf("1) insertFirst (리스트의 제일 앞에 삽입)\n");
	printf("2) insertLast (리스트의 제일 뒤에 삽입)\n");
	printf("3) insertMiddle (특정 값 뒤에 삽입)\n");
	printf("4) insertNthNode (N번째 위치 삽입)\n");
	printf("6) deleteNodeNode (특정 값 삭제)\n");
	printf("7) print Head/Tail\n");
	printf("0) Program Stop\n");
	printf("Select menu : ");
}

int printHeadTail(linkedList_h* L)
{
	if (L->head == (listNode*)NULL || L->tail == (listNode*)NULL) // 리스트가 비었다면
		printf("Head/Tail  ▶ 리스트가 비어 있습니다.\n");

	else if (L->head == L->tail) // 리스트에 항목이 1개라면
		printf("Head/Tail  ▶ Head : %d, Tail : %d\n", L->head->data, L->tail->data);
	else
		printf("Head/Tail  ▶ Head : %d, Tail : %d\n", L->head->data, L->tail->data);

}

linkedList_h* createCLinkedList(void) {
	linkedList_h* lptr;

	lptr = (linkedList_h*)malloc(sizeof(linkedList_h));
	lptr->head = (listNode*)NULL;
	lptr->tail = (listNode*)NULL;
	lptr->follow = 0;
	return lptr;
}

void destroyCLinkedList(linkedList_h* L) {
	listNode* p;

	while (L->head != L->head->link) {
		p = L->head;
		L->head = L->head->link;  // L->head = p->link;
		free(p);
	}
	free(L->head);
	free(L);
}

int printCList(linkedList_h* L) {


	if (L == NULL || L->head == (listNode*)NULL) {
		printf("\n");
		return;
	}

	printf("Linked List(%d): ", L->follow);
	listNode* lptr = L->head;
	while (lptr->link != L->head) {
		printf("[%d]", lptr->data);
		lptr = lptr->link;
	}
	printf("[%d]", lptr->data);
	return 0;
}

void insertFirstNode(linkedList_h* L, elementType item) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = L->head; //(1)
	L->head = newNode;  //(2)

	return 0;
}

void insertFirstCNode(linkedList_h* L, elementType item) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = L->head; //(1)

	if (L->head != (listNode*)NULL) {
		listNode* temp = L->head;
		while (temp->link != L->head) {
			temp = temp->link;
			L->follow++;
		}
		temp->link = newNode;
	}
	else {
		newNode->link = newNode;
		L->tail = newNode;
	}
	L->head = newNode;  //(2)

	return;
}


void insertLastCNode(linkedList_h* L, elementType item)
{
	listNode* temp, * newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == NULL || L->tail == NULL) //리스트에 항목이 없으면
	{
		newNode->link = newNode;
		L->head = newNode;
		L->tail = newNode;
		return;
	}

	else //리스트에 항목이 존재하면
	{
		newNode->link = L->head; // 새 노드가 head를 가리킴 (원형 유지)
		L->tail->link = newNode; // 기존 tail이 새 노드 가리킴
		L->tail = newNode; // tail 갱신
	}
	L->follow++;
}



void insertMiddleCNode(linkedList_h* L, int key, elementType item) 
{
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == NULL) {  // 리스트가 비어 있을 때
		newNode->link = newNode;
		L->head = newNode;
		L->tail = newNode;
		return;
	}

	// key 값을 가진 노드 찾기 (while문 사용)
	listNode* pre = L->head;
	while (pre->link != L->head && pre->data != key) 
	{
		pre = pre->link;
	}

	// key 값을 가진 노드를 못 찾은 경우
	if (pre->data != key) 
	{
		printf("%d 값을 가진 노드를 찾을 수 없습니다.\n", key);
		free(newNode);
		return;
	}

	// 중간이나 끝에 삽입
	newNode->link = pre->link;
	pre->link = newNode;

	if (pre == L->tail) 
	{  // tail 뒤에 삽입한 경우
		L->tail = newNode;
	}

	L->tail->link = L->head;  // 원형 유지
}


void insertNthCNode(linkedList_h* L, int loc, elementType item) {
	if (L->head == NULL) {
		if (loc == 0) {
			listNode* newNode = (listNode*)malloc(sizeof(listNode));
			newNode->data = item;
			newNode->link = newNode;
			L->head = newNode;
			L->tail = newNode;
		}
		else {
			fprintf(stderr, "[insertNthCNode: 리스트 비었고 loc이 0이 아님]\n");
		}
		return;
	}

	if (loc == 0) {
		insertFirstCNode(L, item); // 원형 리스트용 함수 호출
		return;
	}

	int i = loc;
	listNode* pre = L->head;

	while (i > 1 && pre->link != L->head) {
		pre = pre->link;
		i--;
	}

	if (i == 1) {
		// 중간 삽입
		listNode* newNode = (listNode*)malloc(sizeof(listNode));
		newNode->data = item;
		newNode->link = pre->link;
		pre->link = newNode;

		if (pre == L->tail) {
			L->tail = newNode;
		}
		L->tail->link = L->head;
	}
	else {
		fprintf(stderr, "[insertNthCNode: 위치 초과 오류]\n");
	}
}


void deleteCNode(linkedList_h* L, int item) {
	if (L == NULL || L->head == NULL) return;

	listNode* p = L->head;
	listNode* pre = NULL;

	// 노드가 하나일 때
	if (p->data == item && L->head == L->tail) {
		free(p);
		L->head = NULL;
		L->tail = NULL;
		return;
	}

	// head를 삭제할 때
	if (p->data == item) {
		L->head = p->link;
		L->tail->link = L->head;
		free(p);
		return;
	}

	// 나머지 노드 탐색
	pre = p;
	p = p->link;
	while (p != L->head) {
		if (p->data == item) {
			pre->link = p->link;
			if (p == L->tail)  // tail 삭제
				L->tail = pre;
			free(p);
			return;
		}
		pre = p;
		p = p->link;
	}

	fprintf(stderr, "삭제할 값(%d)을 가진 노드를 찾을 수 없습니다.\n", item);
}
