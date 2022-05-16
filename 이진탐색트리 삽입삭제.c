#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef struct TrNode{
	int data;
	struct TrNode *left;
	struct TrNode *right;
}TNode;

typedef TNode* Element;
Element data[MAX_QUEUE_SIZE]; // 요소의 배열
int front; // 전단
int rear; // 후단

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
	error("  큐 포화 에러");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}

Element dequeue()
{
	if (is_empty())
	error("  큐 공백 에러");
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}

Element peek()
{
	if (is_empty())
	error("  큐 공백 에러");
	return data[(front + 1) % MAX_QUEUE_SIZE];
}

void Level_order(TNode* n){  //레벨순회 
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

int count_node(TNode *n){ // 노드의 수 측정 
	if(n == NULL) return 0;
	else
		return 1 + count_node(n->left) + count_node(n->right);
} 

int count_leaf(TNode *n){ // 단말 노드의 수 측정 
	if(n == NULL ) return 0;
	if(n->left == NULL && n->right == NULL) return 1;
	else
	return count_leaf(n->left) + count_leaf(n->right);
}

int calc_height(TNode *n){ // 트리의 높이 측정 
	int hLeft, hRight;
	if(n == NULL) return 0;
	hLeft = calc_height(n->left);
	hRight = calc_height(n->right);
	return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
}

void preorder(TNode *n){ // 전위순회  
	if(n!=NULL){
		printf("[%d] ", n->data);
		preorder(n->left);
		preorder(n->right);
	}
}

void inorder(TNode *n){ // 중위순회 
	if(n!=NULL){
		inorder(n->left);
		printf("[%d] ", n->data);
		inorder(n->right);
	}
}

void postorder(TNode *n){ // 후위순회 
	if(n!=NULL){
		postorder(n->left);
		postorder(n->right);
		printf("[%d] ", n->data);
	}
}

struct TrNode* search(TNode* n, int key){ // 이진트리의 탐색 
	if(n == NULL) return NULL;
	if(key == n->data) return n;
	else if(key < n->data)
		return search(n->left, key);
	else
		return search(n->right, key);
}

struct TrNode* newNode(int data){ // 새로운 노드 생성 
	struct TrNode* temp = (struct TrNode* )malloc(sizeof(struct TrNdoe*));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct TrNode* insert_node(TNode* n, int key){ // 이진트리의 삽입 
	
	if(n == NULL) return (newNode(key)); // 트리가 공백이면 새로운 노드 반환 
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
	printf(" 이진탐색트리 탐색, 삽입, 삭제\n");
	printf("----------------------------------------\n");
	printf(" 1. 이진탐색트리 탐색 ('1')\n");
	printf(" 2. 이진탐색트리 삽입 ('2')\n");
	printf(" 3. 이진탐색트리 삭제 ('3')\n");
	printf(" 4. 순회 정렬 ('4') \n");
	printf(" 5. 프로그램 종료 ('5')\n");
	printf("----------------------------------------\n");
	printf("\n\n 원하시는 서비스를 입력해 주세요. ");
	
	ch = getche();
	
	switch(ch){
		case '1' : 
			system("cls");
			printf("\n\n 탐색할 데이터 값 : "); scanf("%d", &insertdata);
			find = search(root, insertdata);
			if(find == NULL){
				printf("입력하신 데이터 값 [%d] 을 가지는 노드가 없습니다.\n", insertdata);
			}
			else{
				printf("입력하신 데이터 값 [%d] 을 가지는 노드가 있습니다.\n", insertdata);
			}
			printf("\n\n계속 하려면 아무키나 누리시오.\n\n");
			break;
		case '2' : 
			system("cls");
			printf("\n\n 삽입할 데이터 값 : "); scanf("%d", &insertdata);
			root = insert_node(root, insertdata);
			printf("\n\n계속 하려면 아무키나 누르시오.\n\n");
			break;
		case '3' : 
			system("cls");
			printf("\n\n 삭제할 데이터 값 : "); scanf("%d", &deletedata);
			delete_node(root, deletedata);
			printf("\n\n삭제가 완료 되었습니다.\n\n 계속하려면 아무키나 누르시오. \n\n");
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
			printf("노드의 수      : %d \n", count_node(root));
			printf("단말 노드의 수 : %d \n", count_leaf(root));
			printf("트리의 높이    : %d \n", calc_height(root));
			printf("\n\n계속 하려면 아무키나 누리시오.\n\n");
			break;
		case '5' : 
			system("cls");
			printf("\n\n프로그램을 종료합니다.\n\n");
			break;
	}
	getche();	
} while(ch != '5');
	
}
