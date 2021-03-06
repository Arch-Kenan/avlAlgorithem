// testRoute.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "avlDS.h"
#include <stack>
#include <iostream>

int GetHeight(BTnode* root)
{
	if (root)
	{
		return root->height;
	}
	return 0;
}

bool LLRotate(BTnode* &root)
{
	if (root)
	{
		BTnode* tempRef = root->lchild;
		root->lchild = tempRef->rchild;
		tempRef->rchild = root;
		root->height = cMAX(GetHeight(root->lchild), GetHeight(root->rchild)) + 1;
		tempRef->height = cMAX(GetHeight(tempRef->lchild), GetHeight(tempRef->rchild)) + 1;
		root = tempRef;
	}
	return false;
}

bool RRRotate(BTnode* &root)
{
	if (root)
	{
		BTnode* tempRef = root->rchild;
		root->rchild = tempRef->lchild;
		tempRef->lchild = root;
		root->height = cMAX(GetHeight(root->lchild), GetHeight(root->rchild)) + 1;
		tempRef->height = cMAX(GetHeight(tempRef->lchild), GetHeight(tempRef->rchild)) + 1;
		root = tempRef;
		return true;
	}
	else
	{
		return false;
	}

}

bool LRRotate(BTnode* &root)
{
	if (root)
	{
		BTnode* tempRef1 = root->lchild;
		BTnode* tempRef = tempRef1->rchild;
		tempRef1->rchild = tempRef->lchild;
		tempRef1->height = cMAX(GetHeight(tempRef1->lchild), GetHeight(tempRef1->rchild)) + 1;
		root->lchild = tempRef->rchild;
		root->height = cMAX(GetHeight(root->lchild), GetHeight(root->rchild)) + 1;
		tempRef->lchild = tempRef1;
		tempRef->rchild = root;
		tempRef->height = cMAX(GetHeight(tempRef->lchild), GetHeight(tempRef->rchild)) + 1;
		root = tempRef;
		return true;
	}
	else
	{
		return false;
	}

}

//
bool RLRotate(BTnode* &root)
{
	if (root)
	{
		BTnode* tempRef1 = root->rchild;
		BTnode* tempRef = tempRef1->lchild;
		tempRef1->lchild = tempRef->rchild;
		tempRef1->height = cMAX(GetHeight(tempRef1->lchild), GetHeight(tempRef1->rchild)) + 1;
		root->rchild = tempRef->lchild;
		root->height = cMAX(GetHeight(root->lchild), GetHeight(root->rchild)) + 1;
		tempRef->lchild = root;
		tempRef->rchild = tempRef1;
		tempRef->height = cMAX(GetHeight(tempRef->lchild), GetHeight(tempRef->rchild)) + 1;
		root = tempRef;
		return true;
	}
	else
	{
		return false;
	}

}





bool InsertNode(BTnode* &root, int key)
{
	if (root == nullptr)
	{
		root = new BTnode(key, 1);
		return true;
	}
	else if (root->num == key)
	{
		return false;
	}
	else
	{
		if (key < root->num)
		{
			if (!InsertNode(root->lchild, key))
			{
				return false;
			}
			else
			{
				//root->height = cMAX(GetHeight(root->lchild), GetHeight(root->rchild)) + 1;
				if (GetHeight(root->lchild) - GetHeight(root->rchild) == 2)
				{
					if (GetHeight(root->lchild->lchild) > GetHeight(root->lchild->rchild))
					{
						LLRotate(root);
					}
					else
					{
						LRRotate(root);
					}
				}
				root->height = cMAX(GetHeight(root->lchild), GetHeight(root->rchild)) + 1;

			}
		}
		else
		{
			if (!InsertNode(root->rchild, key))
			{
				return false;
			}
			else
			{
				//root->height = cMAX(GetHeight(root->lchild), GetHeight(root->rchild)) + 1;
				if (GetHeight(root->rchild) - GetHeight(root->lchild) == 2)
				{
					if (GetHeight(root->rchild->rchild) > GetHeight(root->rchild->lchild))
					{
						RRRotate(root);
					}
					else
					{
						RLRotate(root);
					}
				}
				root->height = cMAX(GetHeight(root->lchild), GetHeight(root->rchild)) + 1;
			}
		}
		return true;
	}

}





void midTraval(BTnode* root)
{
	//if (!root)
	//{
	//	return;
	//}
	//int index = 0;
	//std::stack<BTnode*>   cStack;
	//cStack.push(root);
	//BTnode* head = root;
	//while (!cStack.empty() || head)
	//{
	//	while (head)
	//	{
	//		cStack.push(head);
	//		head = head->lchild;
	//	}
	//	head = cStack.top();
	//	cStack.pop();
	//	std::cout <<index++<<"   "<< head->height << "    " << head->num << std::endl;
	//	head = head->rchild;
	//}
	if (!root)
	{
		return;
	}
	else
	{
		//std::cout << root->height << "    " << root->num << std::endl;
		midTraval(root->lchild);
		std::cout << root->height << "    " << root->num << std::endl;
		midTraval(root->rchild);
	}
}

void preTraval(BTnode* root)
{
	if (!root)
		return;
	std::stack<BTnode*> stack_temp;
	stack_temp.push(root);
	int index = 0;
	while (!stack_temp.empty())
	{
		root = stack_temp.top();
		stack_temp.pop();
		while (root)
		{
			std::cout <<index++<< "浏览节点:" << root->num << std::endl;
			if (root->rchild)
				stack_temp.push(root->rchild);
			root = root->lchild;
		}
	}
}

int depth(BTnode* root)
{
	if (!root)
	{
		return 0;
	}
	else
	{
		return cMAX(depth(root->lchild), depth(root->rchild)) + 1;
	}
}


bool isBalance(BTnode* root)
{
	if (!root)
	{
		return true;
	}
	else
	{
		if (isBalance(root->lchild) && isBalance(root->rchild))
		{
			int ldp = depth(root->lchild);
			int rdp = depth(root->rchild);
			if ((ldp -rdp) >1 || (ldp - rdp) < -1)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
}





