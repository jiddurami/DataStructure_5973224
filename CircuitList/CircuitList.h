#pragma once

typedef int elementType;  // ��忡 ������ �����ʹ� ����

typedef struct ListNode {  // ���Ḯ��Ʈ�� ��� Ÿ�� ����
	elementType data;
	struct ListNode* link;
} listNode;

typedef struct {  // ���Ḯ��Ʈ�� ���
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
