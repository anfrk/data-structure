#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode{ // �ܼ� ���Ḯ��Ʈ�� ��� ������ ����ü�� ���� 
	char data[4];
	struct listNode *link;
}ListNode;

void insert_Linked_List(ListNode **first, char *data){
	
	ListNode *temp, *curr;
	temp = (ListNode *)malloc(sizeof(ListNode *));	
	strcpy(temp->data,data);							//���ڿ��� ���� �Լ��� �Է��ؾ� �� 
	temp->link = NULL;
	curr = *first;
	
	if(*first == NULL){									//����Ʈ�� ��������� ���� �տ� ���� 
		temp->link = NULL;
		*first = temp;
	}
	else{
		while(curr->link != NULL)						//���� �������� ��� ���� 
			curr = curr->link;
		curr->link = temp;
	}
}

void printList(ListNode *first){
	
	ListNode *current;
	current = first;
	printf("L = (");
	while(current != NULL){					//��尡 NULL�� ���ö����� �ݺ� 
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
		if(strcmp(curr->data, data) == 0)		//���ڿ��� ���Ҷ� �����Լ��� ����ؾ� �� 
			return curr;
		curr = curr->link;
	}
	return NULL;
}

void deleteNode(ListNode **first, ListNode *current){
	ListNode *pre;					//������ ����� ������ ��带 ��Ÿ�� ������ 
	if((*first) == NULL) return;	//���� ����Ʈ��� ���� ���� �ߴ� 
	if((*first)->link == NULL){		//����Ʈ�� ��尡 �Ѱ��� �ִ� ��� 
		free(*first);				//ù��° ��带 �޸𸮿��� �����ϰ� 
		*first = NULL;				//����Ʈ ���� �����͸� NULL�� ���� 
		return;
	}
	else if(current == NULL) return;	//������ ��尡 ���ٸ� ���� ���� �ߴ� 
	else{								//������ ���current�� ������ ��带 ������ pre�� �̿��� ã�� 
		pre = *first;
		while(pre->link != current){
			pre = pre->link;
		}
		pre->link = current->link;		//������ ��� current�� ������ ���� ���� ��带 ���� 
		free(current);					//���� ����� �޸� ���� 
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
	
	printf("(1)����Ʈ�� [��] �����ϱ�! \n ");
	insert_Linked_List(&first, "��");
	printList(first);
	printf("\n");
	
	printf("(2)����Ʈ�� [��] �����ϱ�! \n ");
	insert_Linked_List(&first, "��");
	printList(first);
	printf("\n");
	
	printf("(3)����Ʈ�� [��] �����ϱ�! \n ");
	insert_Linked_List(&first, "��");
	printList(first);
	printf("\n");
	
	printf("(4)����Ʈ�� [ȭ] �����ϱ�! \n ");
	insert_Linked_List(&first, "ȭ");
	printList(first);
	printf("\n");
	
	printf("(5)����Ʈ���� [��] Ž���ϱ�! \n");
	p = searchNode(first,"��");
	if(p == NULL)
		printf("ã�� �����Ͱ� �����ϴ�.\n");
	else 
		printf("[%s]�� ã�ҽ��ϴ�.\n", p->data);
		
	printf("\n(6)����Ʈ���� [��] Ž���ϱ�! \n");
	p = searchNode(first,"��");
	if(p == NULL)
		printf("ã�� �����Ͱ� �����ϴ�.\n");
	else 
		printf("[%s]�� ã�ҽ��ϴ�.\n", p->data);
	
	printf("\n(7)����Ʈ���� [��] ��� �����ϱ�\n");
	p = searchNode(first, "��");
	deleteNode(&first,p);
	printList(first);
	
	printf("\n(8)����Ʈ ������ �������� �ٲٱ�!\n");
	first = reverse(first);
	printList(first);
}
