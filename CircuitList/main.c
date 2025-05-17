#include <stdio.h>
#include <stdlib.h>

#include "CircuitList.h"

int main(void)
{

	linkedList_h* mylist = createCLinkedList();
	int num, r, d;

	while (1)
	{
		menuList();
		scanf_s("%d", &num);

		int n;
		switch (num)
		{

		case 1:
			printf("삽입할 값 : ");
			scanf_s("%d", &n);
			insertFirstCNode(mylist, n);
			printCList(mylist);
			break;

		case 2:
			printf("삽입할 값 : ");
			scanf_s("%d", &n);
			insertLastCNode(mylist, n);
			printCList(mylist);
			break;
		case 3:
			printf("(key) 어떤 값 뒤에 ? : ");
			scanf_s("%d", &r);
			printf("삽입할 값 : ");
			scanf_s("%d", &n);
			insertMiddleCNode(mylist, r, n);
			printCList(mylist);
			break;
		case 4:
			printf("삽입할 위치 (0부터 시작) : ");
			scanf_s("%d", &r);
			printf("삽입할 값 : ");
			scanf_s("%d", &n);
			insertNthCNode(mylist, r, n);
			printCList(mylist);
			break;
		case 5:
			printCList(mylist);
			break;
		case 6:
			printf("삭제할 값 : ");
			scanf_s("%d", &n);
			deleteCNode(mylist, n);
			printCList(mylist);
			break;
		case 7:
			printHeadTail(mylist);
			break;
		case 0:
			printf("종료");
			exit(0);
		}
	}
}