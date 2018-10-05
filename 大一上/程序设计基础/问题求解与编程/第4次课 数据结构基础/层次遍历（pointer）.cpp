#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAXN = 256;

typedef struct TNode{
	int value;       
	int have_value;  //是否被赋值过
	struct TNode * left, * right;

} Node;

Node * root;

Node * newnode()
{
	Node * node = (Node *)malloc(sizeof(Node));
	if(node != NULL)
	{
		node->have_value = 0;  //表示没有被赋值过
		node->left = node->right = NULL;
	}
	return node;
}

int failed;

void addnode(int v, char * s)
{
	int n = strlen(s);
	Node * node = root;   //从根节点开始往下走
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='L')
		{
			if(node->left==NULL) node->left = newnode(); //节点不存在，建立新节点
			node = node->left;
		}
		if(s[i]=='R')
		{
			if(node->right==NULL) node->right = newnode();
			node = node->right;
		}
	}
	if(node->have_value) failed = 1; //已经赋值过，表明输入有误
	node->value = v;
	node->have_value = 1;
}

void remove_tree(Node * node)
{
	if(node==NULL) return;
	remove_tree(node->left);
	remove_tree(node->right);
	free(node);
}

char s[MAXN+10];
int read_input()
{
	failed = 0;
	remove_tree(root);
	root = newnode();   //创建根节点
	while(1)
	{
		if(scanf("%s",s)!=1) return 0;  //整个输入结束
		if(!strcmp(s,"()")) break;    //读到()，退出循环
		int v;
		sscanf(&s[1],"%d",&v);       //读入节点值
		addnode(v,strchr(s,',')+1);   //添加节点
	}
	return 1;
}

int n = 0, ans[MAXN];    //节点总数和输出序列
int bfs() // 初始时一个根节点，每取一个节点，它的左右儿子放入队列
{
	int front = 0, rear = 1;
	Node * tree[MAXN];   //队列
	tree[0] = root;
	while(front<rear)
	{
		Node * node = tree[front++];
		if(!node->have_value)  return 0; //有节点没被赋值，表明输入有误
		ans[n++] = node->value;
		if(node->left != NULL) tree[rear++] = node->left;
		if(node->right != NULL) tree[rear++] = node->right;
	}
	return 1;
}

int main()
{
	while(read_input())
	{
		if(!bfs()) failed = 1;
		if(failed) printf("-1\n");
		else
		{
			for(int i=0; i<n; i++)
				printf("%d ", ans[i]);
			printf("\n");
		}
	}
	return 0;
}