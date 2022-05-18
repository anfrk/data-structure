#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef struct AVL_node{
	int data;
	struct AVL_node *left;
	struct AVL_node *right;
}AVLnode;

typedef AVLnode* Element;
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

void Level_order(AVLnode* n){  //레벨순회 

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

AVLnode *rotate_LL(AVLnode *parent){

	AVLnode *child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}

AVLnode *rotate_RR(AVLnode *parent){

	AVLnode *child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

AVLnode *rotate_RL(AVLnode *parent){
	AVLnode *child = parent->right;
	parent->right = rotate_LL(child);
	return rotate_RR(parent);
}

AVLnode *rotate_LR(AVLnode *parent){
	AVLnode *child = parent->left;
	parent->left = rotate_RR(child);
	return rotate_LL(parent);
}

int get_height(AVLnode *n){ // 트리의 높이 측정 

	int hLeft, hRight;
	if(n == NULL) return 0;
	hLeft = get_height(n->left);
	hRight = get_height(n->right);
	return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
}

int get_BF(AVLnode *n){
	if(n == NULL) return 0;
	return get_height(n->left) - get_height(n->right);
}

struct AVL_node *rebalance(AVLnode **n){

	int BF = get_BF(*n);
	if (BF > 1){
		if (get_BF((*n)->left) > 0)
			*n = rotate_LL(*n);
		else
			*n = rotate_LR(*n);
	}
	else if (BF < -1){
		if (get_BF((*n)->right) < 0)
			*n = rotate_RR(*n);
		else
			*n = rotate_RL(*n);
	}
	return *n;
}

 struct AVL_node *insert_AVL_node(AVLnode **n, int key){ // 이진트리의 삽입 
	if(*n == NULL){
		*n = (AVLnode *)malloc(sizeof(AVLnode *));
		(*n)->data = key;
		(*n)->left = NULL;
		(*n)->right = NULL;
	}
	else if(key < (*n)->data){
		(*n)->left = insert_AVL_node(&((*n)->left), key);
		*n = rebalance(n);
	}
	else if(key > (*n)->data){
		(*n)->right = insert_AVL_node(&((*n)->right), key);
		*n = rebalance(n);
	}
	return *n;
}

int main(void) {

	struct AVL_node *root = NULL;
	
	root = insert_AVL_node(&root,30);
	rebalance(&root);
	printf("\nAVL(30)  : ");
	Level_order(root);
	
	root = insert_AVL_node(&root,40);
	rebalance(&root);
	printf("\nAVL(40)  : ");
	Level_order(root);
	
	root = insert_AVL_node(&root,100);
	rebalance(&root);
	printf("\nAVL(100) : ");
	Level_order(root);
	
	root = insert_AVL_node(&root,20);
	rebalance(&root);
	printf("\nAVL(20)  : ");
	Level_order(root);
	
	root = insert_AVL_node(&root,10);
	rebalance(&root);
	printf("\nAVL(10)  : ");
	Level_order(root);
	
	root = insert_AVL_node(&root,60);
	rebalance(&root);
	printf("\nAVL(60)  : ");
	Level_order(root);
	
	root = insert_AVL_node(&root,70);
	rebalance(&root);
	printf("\nAVL(70)  : ");
	Level_order(root);
	
	root = insert_AVL_node(&root,120);
	rebalance(&root);
	printf("\nAVL(120) : ");
	Level_order(root);
	
	root = insert_AVL_node(&root,110);
	rebalance(&root);
	printf("\nAVL(110) : ");
	Level_order(root);
	
}
