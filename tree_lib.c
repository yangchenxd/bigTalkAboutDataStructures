/**
 * Tree functions
 */
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

 /**
  * @brief Binary tree preorder traversal recursive (二叉树的前序遍历递归算法)
  */
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	printf("%c\n", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

/**
 * @brief Binary tree inorder traversal recursive (二叉树的中序遍历递归算法)
 */
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	InOrderTraverse(T->lchild);
	printf("%c\n", T->data);
	InOrderTraverse(T->rchild);
}

/**
 * @brief Binary tree subsequent traversal recursive (二叉树的后续遍历递归算法)
 */
void PostTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	PostTraverse(T->lchild);
	PostTraverse(T->rchild);
	printf("%c\n", T->data);
}

/**
 * Create Binary tree
 * # means empty tree, create Binary link list to represent Binary Tree
 */
void CreateBiTree(BiTree* T)
{
	TElemType ch;
	scanf("%c", &ch);
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
		{
			return;
		}
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}