#pragma once
#include "stdafx.h"

// Minimum and maximum macros
#define cMAX(a,b) (((a) > (b)) ? (a) : (b))
#define cMIN(a,b) (((a) < (b)) ? (a) : (b))

struct BTnode
{
	int num;
	int height;
	BTnode* lchild;
	BTnode* rchild;
	BTnode() {};
	BTnode(int cnum, int cheight, BTnode* clchild = nullptr, BTnode* crchild = nullptr) :num(cnum), height(cheight), lchild(clchild), rchild(crchild)
	{
	}
};

int  GetHeight(BTnode* root);
bool LLRotate(BTnode* &root);
bool RRRotate(BTnode* &root);
bool LRRotate(BTnode* &root);
bool RLRotate(BTnode* &root);
bool InsertNode(BTnode* &root, int key);
bool DeleteNode(BTnode* &root, int key);
void midTraval(BTnode* root);
int  depth(BTnode* root);
bool isBalance(BTnode* root);
void preTraval(BTnode* root);