#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef char TElement;
typedef struct TrNode{
	TElement data;
	struct TrNode *left;
	struct TrNode *right;
}TNode;

typedef TNode* Element;
Element data[MAX_QUEUE_SIZE]; // ����� �迭
int front; // ����
int rear; // �Ĵ�

int count_node(TNode *n){
	if(n == NULL) return 0;
	else
		return 1 + count_node(n->left) + count_node(n->right);
} 

int count_leaf(TNode *n){
	if(n == NULL ) return 0;
	if(n->left == NULL && n->right == NULL) return 1;
	else
	return count_leaf(n->left) + count_leaf(n->right);
}

int calc_height(TNode *n){
	int hLeft, hRight;
	if(n == NULL) return 0;
	hLeft = calc_height(n->left);
	hRight = calc_height(n->right);
	return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
}

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
			printf ("[%c] ", n->data);
			enqueue(n->left);
			enqueue(n->right);
		}
	}
}

struct TrNode* newNode(char data){  //���ο� Ʈ����� �߰� 
	struct TrNode* node = (struct TrNode*)malloc(sizeof(struct TrNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

void preorder(TNode *n){ // ������ȸ  
	if(n!=NULL){
		printf("[%c] ", n->data);
		preorder(n->left);
		preorder(n->right);
	}
}

void inorder(TNode *n){ // ������ȸ 
	if(n!=NULL){
		inorder(n->left);
		printf("[%c] ", n->data);
		inorder(n->right);
	}
}

void postorder(TNode *n){ // ������ȸ 
	if(n!=NULL){
		postorder(n->left);
		postorder(n->right);
		printf("[%c] ", n->data);
	}
}

int main(void) {
	
	struct TrNode* root = newNode('A');
	root->left = newNode('B');
	root->left->left = newNode('D');
	root->left->right = newNode('E');
	root->right = newNode('C');
	root->right->left = newNode('F');
	
	printf("In-Order    : ");
	inorder(root);
	printf("\n");
	
	printf("Pre-Order   : ");
	preorder(root);
	printf("\n");
	
	printf("Post-Order  : ");
	postorder(root);
	printf("\n");
	
	printf("Level-Order : ");
	Level_order(root);
	printf("\n");
	
	printf("\n");
	printf("����� ��      : %d \n", count_node(root));
	printf("�ܸ� ����� �� : %d \n", count_leaf(root));
	printf("Ʈ���� ����    : %d \n", calc_height(root)); 

	

	free(root);

}
