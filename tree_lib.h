/**
 * ADT(Abstract Data Type) 树(Tree)
 * Data
 *     树是由一个根结点和若干个子树构成。树中结点具有相同数据类型及层次结构
 * Operation
 *	   InitTree(*T): 构造孔数
 *     DestoryTree(*T): 销毁树T
 *	   CreateTree(*T, definition): 按definition中给出树的定义来构造树
 *	   ClearTree(*T): 若树T存在，则将树T清为空树
 *     TreeEmpty(T): 若T为空树，返回true，否则返回false
 *     TreeDepth(T): 返回T的深度
 *     Root(T): 返回T的根结点
 *     Value(T, cur_e): cur_e是树T中的一个结点，返回此结点的值
 *     Assign（T, cur_e, value): 给树T的结点cur_e赋值为value
 *     Parent(T, cur_e, value): 若cur_e是树T的非根结点，则返回它的双亲，否则返回空
 *     LeftChild(T, cur_e): 若cur_e是树T的非叶结点，则返回它的最左孩子，否则返回空
 *     RightSibling(T, cur_e): 若cur_e有有兄弟，则返回它的右兄弟，否则返回空
 *     InsertChild(*T, *p, i, c): 其中p指向树T的某个结点，i为所指结点p的度加上1，
 *								  非空树c与T不相交，操作结果为插入c为树T中p指结点的第i颗子树
 *     DeleteChild(*T, *p, i): 其中p指向树T的某个结点，i为所指结点p的度，操作结果为
 *                             删除T中p所指结点的第i颗子树
 */

 /**
  * @brief 树的双亲表示法结点结构定义
  */
#define MAX_TREE_SIZE 100
typedef int TElemType;   /* 树的数据类型，暂定为整形 */
typedef struct PTNode    /* 结点结构*/
{
	TElemType data;      /* 结点数据 */
	int parent;          /* 双亲位置 */
}PNode;

typedef struct
{
	PNode nodes[MAX_TREE_SIZE];   /* 结点数据 */
	int r, n;                     /* 根的位置和结点数 */
}PTree;


/**
 * @brief 树的孩子表示法结构定义
 */
typedef struct CTNode    /* 孩子结点 */
{
	int child;
	struct CTNode* next;
}*ChildPtr;

typedef struct   /* 表头结构 */
{
	TElemType data;
	ChildPtr firstchild;
}CTRoot;

typedef struct    /* 树结构 */
{
	CTRoot node[MAX_TREE_SIZE];
	int r, n;
}CTree;

/**
 * @brief 二叉树的二叉链表结点结构定义
 */
typedef struct BiTNode
{
	TElemType data;      /* 结点数据 */
	struct BiTNode* lchild, * rchild; /* 左右孩子指针 */
}BiTNode, * BiTree;