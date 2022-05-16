#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef struct TrNode{
	int data;
	struct TrNode *left;
	struct TrNode *right;
}TNode;

typedef TNode* Element;
Element data[MAX_QUEUE_SIZE]; // ����� �迭
int front; // ����
int rear; // �Ĵ�

void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}

void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear; }
int is_full() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
int size() { return(rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void enqueue(Element val)
{
if (is_full())
	error("  ť ��ȭ ����");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}

Element dequeue()
{
	if (is_empty())
	error("  ť ���� ����");
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}

Element peek()
{
	if (is_empty())
	error("  ť ���� ����");
	return data[(front + 1) % MAX_QUEUE_SIZE];
}

void Level_order(TNode* n){  //������ȸ 
	Element queue;
	init_queue();
	if(n == NULL) return;
	enqueue(n);	
	while (is_empty() != 1){
		n = dequeue(queue);
		if(n != NULL){
			printf ("[%d] ", n->data);
			enqueue(n->left);
			enqueue(n->right);
		}
	}
}

int count_node(TNode *n){ // ����� �� ���� 
	if(n == NULL) return 0;
	else
		return 1 + count_node(n->left) + count_node(n->right);
} 

int count_leaf(TNode *n){ // �ܸ� ����� �� ���� 
	if(n == NULL ) return 0;
	if(n->left == NULL && n->right == NULL) return 1;
	else
	return count_leaf(n->left) + count_leaf(n->right);
}

int calc_height(TNode *n){ // Ʈ���� ���� ���� 
	int hLeft, hRight;
	if(n == NULL) return 0;
	hLeft = calc_height(n->left);
	hRight = calc_height(n->right);
	return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
}

void preorder(TNode *n){ // ������ȸ  
	if(n!=NULL){
		printf("[%d] ", n->data);
		preorder(n->left);
		preorder(n->right);
	}
}

void inorder(TNode *n){ // ������ȸ 
	if(n!=NULL){
		inorder(n->left);
		printf("[%d] ", n->data);
		inorder(n->right);
	}
}

void postorder(TNode *n){ // ������ȸ 
	if(n!=NULL){
		postorder(n->left);
		postorder(n->right);
		printf("[%d] ", n->data);
	}
}

struct TrNode* search(TNode* n, int key){ // ����Ʈ���� Ž�� 
	if(n == NULL) return NULL;
	if(key == n->data) return n;
	else if(key < n->data)
		return search(n->left, key);
	else
		return search(n->right, key);
}

struct TrNode* newNode(int data){ // ���ο� ��� ���� 
	struct TrNode* temp = (struct TrNode* )malloc(sizeof(struct TrNdoe*));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct TrNode* insert_node(TNode* n, int key){ // ����Ʈ���� ���� 
	
	if(n == NULL) return (newNode(key)); // Ʈ���� �����̸� ���ο� ��� ��ȯ 
	if(key < n->data) 
		n->left = insert_node(n->left, key);
	else if(key > n->data)
		n->right = insert_node(n->right, key);
	return n;
}

struct TrNode* min_value_node(TNode* n){
	TNode* current = n;
	while (current->left != NULL)
		current = current->left;
		return current;
}

struct TrNode* delete_node(TNode* n, int key){
	if(n == NULL) return n;
	if(key < n->data)
		n->left = delete_node(n->left, key);
	else if(key > n->data)
		n->right = delete_node(n->right, key);
	else{
		if(n->left == NULL){
			TNode * temp = n->right;
			free(n);
			return temp;
		}
		else if(n->right == NULL){
			TNode* temp = n->left;
			free(n);
			return temp;
		}
		TNode* temp = min_value_node(n->right);
		n->data = temp->data;
		n->right = delete_node(n->right, temp->data);
	}
	return n;
}

int main(void) {
	
	int insertdata;	
	int deletedata;
	char ch;
	struct TrNode* root = NULL;
	struct TrNode* find = NULL;
	
do{
	system("cls");
	printf("\n----------------------------------------\n");
	printf(" ����Ž��Ʈ�� Ž��, ����, ����\n");
	printf("----------------------------------------\n");
	printf(" 1. ����Ž��Ʈ�� Ž�� ('1')\n");
	printf(" 2. ����Ž��Ʈ�� ���� ('2')\n");
	printf(" 3. ����Ž��Ʈ�� ���� ('3')\n");
	printf(" 4. ��ȸ ���� ('4') \n");
	printf(" 5. ���α׷� ���� ('5')\n");
	printf("----------------------------------------\n");
	printf("\n\n ���Ͻô� ���񽺸� �Է��� �ּ���. ");
	
	ch = getche();
	
	switch(ch){
		case '1' : 
			system("cls");
			printf("\n\n Ž���� ������ �� : "); scanf("%d", &insertdata);
			find = search(root, insertdata);
			if(find == NULL){
				printf("�Է��Ͻ� ������ �� [%d] �� ������ ��尡 �����ϴ�.\n", insertdata);
			}
			else{
				printf("�Է��Ͻ� ������ �� [%d] �� ������ ��尡 �ֽ��ϴ�.\n", insertdata);
			}
			printf("\n\n��� �Ϸ��� �ƹ�Ű�� �����ÿ�.\n\n");
			break;
		case '2' : 
			system("cls");
			printf("\n\n ������ ������ �� : "); scanf("%d", &insertdata);
			root = insert_node(root, insertdata);
			printf("\n\n��� �Ϸ��� �ƹ�Ű�� �����ÿ�.\n\n");
			break;
		case '3' : 
			system("cls");
			printf("\n\n ������ ������ �� : "); scanf("%d", &deletedata);
			delete_node(root, deletedata);
			printf("\n\n������ �Ϸ� �Ǿ����ϴ�.\n\n ����Ϸ��� �ƹ�Ű�� �����ÿ�. \n\n");
			break;
		case '4' : 
			system("cls");
			printf("   In-Order : ");
			inorder(root);
			printf("\n");
	
			printf("  Pre-Order : ");
			preorder(root);
			printf("\n");
			
			printf(" Post-Order : ");
			postorder(root);
			printf("\n");
	
			printf("Level-Order : ");
			Level_order(root);
			printf("\n");
			
			printf("\n");
			printf("����� ��      : %d \n", count_node(root));
			printf("�ܸ� ����� �� : %d \n", count_leaf(root));
			printf("Ʈ���� ����    : %d \n", calc_height(root));
			printf("\n\n��� �Ϸ��� �ƹ�Ű�� �����ÿ�.\n\n");
			break;
		case '5' : 
			system("cls");
			printf("\n\n���α׷��� �����մϴ�.\n\n");
			break;
	}
	getche();	
} while(ch != '5');
	
}
