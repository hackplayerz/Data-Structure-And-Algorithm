#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
}TreeNode;
void insert(TreeNode *root, int key);
void delete(TreeNode *root, int key);
void inorder(TreeNode *tree);

void main() {
	TreeNode *tree_C;
	tree_C = (TreeNode *)malloc(sizeof(TreeNode));
	tree_C->left = NULL;
	tree_C->right = NULL;
	// First key
	tree_C->key = 72;

	insert(tree_C, 45);
	insert(tree_C, 91);
	insert(tree_C, 74);
	insert(tree_C, 40);
	insert(tree_C, 22);
	insert(tree_C, 18);
	insert(tree_C, 25);
	insert(tree_C, 34);
	insert(tree_C, 52);
	inorder(tree_C);
	delete(tree_C, 72);
	delete(tree_C, 55);
	inorder(tree_C);

	printf("\n");
	getch();
	return 0;
}

void insert(TreeNode *root, int key) {
	TreeNode *p, *t;
	TreeNode *newNode;
	t = root;
	p = NULL;

	// 키의 존재여부 확인
	while (t!=NULL)
	{
		if (key == t->key) {
			printf("Key is already exist!");
		}
		
		p = t;
		if (key < p->key) {
			t = p->left;
		}
		else {
			t = p->right;
		}
	}
	newNode = (TreeNode *)malloc(sizeof(TreeNode));
	if (newNode == NULL) {
		printf("@Err : Memory Error!");
		exit(1);
	}
	newNode->key = key;
	newNode->left = newNode->right = NULL;
	
	if (p != NULL) {
		// 서칭이 끝난후 서브트리보다 크면 오른쪽 작으면 왼쪽에 링크
		if (key < p->key) {
			p->left = newNode;
		}
		else {
			p->right = newNode;
		}
	}
	// 아무것도 없으면 루트노드
	else {
		root = newNode;
	}
}

void delete(TreeNode *root, int key) {
	TreeNode *p, *child, *succ, *succ_p, *t;
	p = NULL;
	t = root;

	// key를 갖는 노드 t를 탐색, p는 t의 부모 노드
	while ((t != NULL && t->key != key)) {
		p = t;
		t = (key < p->key) ? p->left : p->right;
	}
	// 탐색이 종료됬을때 t가 NULL이면 key가 없음
	if (t == NULL) {
		printf("\n@Err : %d라는 key가 존재하지 않습니다!\n",key);
		return;
	}
	// 단말 노드인경우
	if (t->left == NULL && t->right == NULL) {
		if (p != NULL) {
			// 부모 노드의 자식필드를 NULL로 설정
			if (p->left == t) {
				p->left = NULL;
			}
			else {
				p->right = NULL;
			}
		}
		else {
			root = NULL;
		}
	}
	// 자식 노드가 1개인경우
	else if((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			// 부모와 자식노드 연걸
			if (p->left == t) {
				p->left = child;
			}
			else
				p->right = NULL;
		}
		else {
			root = child;
		}
	}
	// 두개의 자식을 갖는경우
	else {
		// 오른쪽 서브트리에서 후계자를 찾는다
		succ_p = t;
		succ = t->right;

		// 후계자를 찾아 왼쪽으로 이동
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		// 후속자의 부모와 자식을 연결
		if (succ_p->left == succ) {
			succ_p->left = succ->right;
		}
		else {
			succ_p->right = succ->right;
		}
		// 후속자가 가진 키 값을 현재 노드에 복사
		t->key = succ->key;
		// 기존 후속자 삭제
		t = succ;
	}
	free(t);
}
void inorder(TreeNode *tree) {
	if (tree) {
		// 왼쪽서브트리 순회
		inorder(tree->left);
		// 노드 방문
		printf("%d  ", tree->key);
		// 오른쪽 서브트리 순회
		inorder(tree->right);
	}
}