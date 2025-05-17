#pragma once

typedef int elementType;  // 노드에 저장할 데이터는 정수

typedef struct ListNode {  // 연결리스트의 노드 타입 정의
	elementType data;
	struct ListNode* link;
} listNode;

typedef struct {  // 연결리스트의 헤더
	int follow;
	listNode* head;
	listNode* tail;
}linkedList_h;

extern void menuList();

extern linkedList_h* createCLinkedList(void);

extern void destroyCLinkedList(linkedList_h* L);

extern int printCList(linkedList_h* L);

extern int printHeadTail(linkedList_h* L);

extern void insertFirstCNode(linkedList_h* L, elementType item);

extern void insertLastCNode(linkedList_h* L, elementType item);

extern void insertMiddleCNode(linkedList_h* L, int pre, elementType item);

extern void insertNthCNode(linkedList_h* L, int loc, elementType item);

extern void deleteCNode(linkedList_h* L, int p);
