#include <stdio.h>
#include <stdlib.h>

typedef char BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);

void ShowIntData(char data);

int		main(void)
{
	int N, i;
	char data[4];
	BTreeNode *arr[26];
	scanf("%d", &N);
	i = 0;
	while (i < 26)
		arr[i++] = MakeBTreeNode();
	i = 0;
	while (i < N)
	{
		scanf(" %c %c %c", &data[0], &data[1], &data[2]);
		arr[data[0] - 'A']->data = data[0];
		if (data[1] != '.')
		{
			arr[data[0] - 'A']->left = arr[data[1] - 'A'];
			arr[data[1] - 'A']->data = data[1];
		}
		if (data[2] != '.')
		{
			arr[data[0] - 'A']->right = arr[data[2] - 'A'];
			arr[data[2] - 'A']->data = data[2];
		}
		++i;
	}

	PreorderTraverse(arr[0], ShowIntData);
	printf("\n");
	InorderTraverse(arr[0], ShowIntData);
	printf("\n");
	PostorderTraverse(arr[0], ShowIntData);
	printf("\n");
	return (0);
}

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));

	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTreeNode* bt)
{
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

void ShowIntData(char data)
{
	printf("%c", data);
}