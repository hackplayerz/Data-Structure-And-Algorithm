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

	// Ű�� ���翩�� Ȯ��
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
		// ��Ī�� ������ ����Ʈ������ ũ�� ������ ������ ���ʿ� ��ũ
		if (key < p->key) {
			p->left = newNode;
		}
		else {
			p->right = newNode;
		}
	}
	// �ƹ��͵� ������ ��Ʈ���
	else {
		root = newNode;
	}
}

void delete(TreeNode *root, int key) {
	TreeNode *p, *child, *succ, *succ_p, *t;
	p = NULL;
	t = root;

	// key�� ���� ��� t�� Ž��, p�� t�� �θ� ���
	while ((t != NULL && t->key != key)) {
		p = t;
		t = (key < p->key) ? p->left : p->right;
	}
	// Ž���� ��������� t�� NULL�̸� key�� ����
	if (t == NULL) {
		printf("\n@Err : %d��� key�� �������� �ʽ��ϴ�!\n",key);
		return;
	}
	// �ܸ� ����ΰ��
	if (t->left == NULL && t->right == NULL) {
		if (p != NULL) {
			// �θ� ����� �ڽ��ʵ带 NULL�� ����
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
	// �ڽ� ��尡 1���ΰ��
	else if((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			// �θ�� �ڽĳ�� ����
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
	// �ΰ��� �ڽ��� ���°��
	else {
		// ������ ����Ʈ������ �İ��ڸ� ã�´�
		succ_p = t;
		succ = t->right;

		// �İ��ڸ� ã�� �������� �̵�
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		// �ļ����� �θ�� �ڽ��� ����
		if (succ_p->left == succ) {
			succ_p->left = succ->right;
		}
		else {
			succ_p->right = succ->right;
		}
		// �ļ��ڰ� ���� Ű ���� ���� ��忡 ����
		t->key = succ->key;
		// ���� �ļ��� ����
		t = succ;
	}
	free(t);
}
void inorder(TreeNode *tree) {
	if (tree) {
		// ���ʼ���Ʈ�� ��ȸ
		inorder(tree->left);
		// ��� �湮
		printf("%d  ", tree->key);
		// ������ ����Ʈ�� ��ȸ
		inorder(tree->right);
	}
}