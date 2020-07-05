/**
 * ADT(Abstract Data Type) ��(Tree)
 * Data
 *     ������һ�����������ɸ��������ɡ����н�������ͬ�������ͼ���νṹ
 * Operation
 *	   InitTree(*T): �������
 *     DestoryTree(*T): ������T
 *	   CreateTree(*T, definition): ��definition�и������Ķ�����������
 *	   ClearTree(*T): ����T���ڣ�����T��Ϊ����
 *     TreeEmpty(T): ��TΪ����������true�����򷵻�false
 *     TreeDepth(T): ����T�����
 *     Root(T): ����T�ĸ����
 *     Value(T, cur_e): cur_e����T�е�һ����㣬���ش˽���ֵ
 *     Assign��T, cur_e, value): ����T�Ľ��cur_e��ֵΪvalue
 *     Parent(T, cur_e, value): ��cur_e����T�ķǸ���㣬�򷵻�����˫�ף����򷵻ؿ�
 *     LeftChild(T, cur_e): ��cur_e����T�ķ�Ҷ��㣬�򷵻����������ӣ����򷵻ؿ�
 *     RightSibling(T, cur_e): ��cur_e�����ֵܣ��򷵻��������ֵܣ����򷵻ؿ�
 *     InsertChild(*T, *p, i, c): ����pָ����T��ĳ����㣬iΪ��ָ���p�Ķȼ���1��
 *								  �ǿ���c��T���ཻ���������Ϊ����cΪ��T��pָ���ĵ�i������
 *     DeleteChild(*T, *p, i): ����pָ����T��ĳ����㣬iΪ��ָ���p�Ķȣ��������Ϊ
 *                             ɾ��T��p��ָ���ĵ�i������
 */

 /**
  * @brief ����˫�ױ�ʾ�����ṹ����
  */
#define MAX_TREE_SIZE 100
typedef int TElemType;   /* �����������ͣ��ݶ�Ϊ���� */
typedef struct PTNode    /* ���ṹ*/
{
	TElemType data;      /* ������� */
	int parent;          /* ˫��λ�� */
}PNode;

typedef struct
{
	PNode nodes[MAX_TREE_SIZE];   /* ������� */
	int r, n;                     /* ����λ�úͽ���� */
}PTree;


/**
 * @brief ���ĺ��ӱ�ʾ���ṹ����
 */
typedef struct CTNode    /* ���ӽ�� */
{
	int child;
	struct CTNode* next;
}*ChildPtr;

typedef struct   /* ��ͷ�ṹ */
{
	TElemType data;
	ChildPtr firstchild;
}CTRoot;

typedef struct    /* ���ṹ */
{
	CTRoot node[MAX_TREE_SIZE];
	int r, n;
}CTree;

/**
 * @brief �������Ķ���������ṹ����
 */
typedef struct BiTNode
{
	TElemType data;      /* ������� */
	struct BiTNode* lchild, * rchild; /* ���Һ���ָ�� */
}BiTNode, * BiTree;