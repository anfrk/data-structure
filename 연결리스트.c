#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode{ // 단순 연결리스트의 노드 구조를 구조체로 정의 
	char data[4];
	struct listNode *link;
}ListNode;

void insert_Linked_List(ListNode **first, char *data){
	
	ListNode *temp, *curr;
	temp = (ListNode *)malloc(sizeof(ListNode *));	
	strcpy(temp->data,data);							//문자열은 별도 함수로 입력해야 함 
	temp->link = NULL;
	curr = *first;
	
	if(*first == NULL){									//리스트가 비어있을때 제일 앞에 삽입 
		temp->link = NULL;
		*first = temp;
	}
	else{
		while(curr->link != NULL)						//제일 마지막에 노드 삽입 
			curr = curr->link;
		curr->link = temp;
	}
}

void printList(ListNode *first){
	
	ListNode *current;
	current = first;
	printf("L = (");
	while(current != NULL){					//노드가 NULL이 나올때까지 반복 
		printf("%s",current->data);
		current = current->link;
		if(current != NULL) printf(", ");	
	}
	printf(") \n");
}

ListNode *searchNode(ListNode *first, char* data){
	ListNode *curr;
	curr = first;
	while(curr != NULL){						
		if(strcmp(curr->data, data) == 0)		//문자열은 비교할때 별도함수를 사용해야 함 
			return curr;
		curr = curr->link;
	}
	return NULL;
}

void deleteNode(ListNode **first, ListNode *current){
	ListNode *pre;					//삭제할 노드의 선행자 노드를 나타낼 포인터 
	if((*first) == NULL) return;	//공백 리스트라면 삭제 연산 중단 
	if((*first)->link == NULL){		//리스트에 노드가 한개만 있는 경우 
		free(*first);				//첫번째 노드를 메모리에서 해제하고 
		*first = NULL;				//리스트 시작 포인터를 NULL로 설정 
		return;
	}
	else if(current == NULL) return;	//삭제할 노드가 없다면 삭제 연산 중단 
	else{								//삭제할 노드current의 선행자 노드를 포인터 pre를 이용해 찾음 
		pre = *first;
		while(pre->link != current){
			pre = pre->link;
		}
		pre->link = current->link;		//삭제할 노드 current의 선행자 노드와 다음 노드를 연결 
		free(current);					//삭제 노드의 메모리 해제 
	}
}

ListNode *reverse(ListNode *first){
	ListNode *p, *q, *r;
	
	p = first;
	q = NULL;
	r = NULL;
	
	while(p != NULL){
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	first = q;
	return;
}

int main(void) {
	
	ListNode *first = NULL;
	ListNode *p = NULL;
	
	printf("(1)리스트에 [수] 삽입하기! \n ");
	insert_Linked_List(&first, "수");
	printList(first);
	printf("\n");
	
	printf("(2)리스트에 [금] 삽입하기! \n ");
	insert_Linked_List(&first, "금");
	printList(first);
	printf("\n");
	
	printf("(3)리스트에 [월] 삽입하기! \n ");
	insert_Linked_List(&first, "월");
	printList(first);
	printf("\n");
	
	printf("(4)리스트에 [화] 삽입하기! \n ");
	insert_Linked_List(&first, "화");
	printList(first);
	printf("\n");
	
	printf("(5)리스트에서 [수] 탐색하기! \n");
	p = searchNode(first,"수");
	if(p == NULL)
		printf("찾는 데이터가 없습니다.\n");
	else 
		printf("[%s]를 찾았습니다.\n", p->data);
		
	printf("\n(6)리스트에서 [토] 탐색하기! \n");
	p = searchNode(first,"토");
	if(p == NULL)
		printf("찾는 데이터가 없습니다.\n");
	else 
		printf("[%s]를 찾았습니다.\n", p->data);
	
	printf("\n(7)리스트에서 [금] 노드 삭제하기\n");
	p = searchNode(first, "금");
	deleteNode(&first,p);
	printList(first);
	
	printf("\n(8)리스트 순서를 역순으로 바꾸기!\n");
	first = reverse(first);
	printList(first);
}
