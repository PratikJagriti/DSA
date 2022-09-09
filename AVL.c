#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node* lchild;
	int data;
	int height;
	struct node* rchild;
}*root = NULL;

int Height(struct node* p)
{
	int lh, rh;
	lh = (p && p->lchild) ? p->lchild->height : 0;
	rh = (p && p->rchild) ? p->rchild->height : 0;

	return lh > rh ? lh + 1 : rh + 1;
}

int BalanceFactor(struct node* p)
{
	int lh, rh;
	lh = (p && p->lchild) ? p->lchild->height : 0;
	rh = (p && p->rchild) ? p->rchild->height : 0;

	return lh - rh;
}

struct node* LLRotation(struct node* p)
{
	struct node* pl = p->lchild;
	struct ndoe* plr = p->lchild->rchild;

	pl->rchild = p;
	p->lchild = plr;

	p->height = Height(p);
	pl->height = Height(pl);

	if (p == root)
		root = pl;

	return pl;
}

struct node* LRRotation(struct node* p)
{
	struct node* pl = p->lchild;
	struct node* plr = pl->rchild;

	pl->rchild = plr->lchild;
	p->lchild = plr->rchild;
	plr->lchild = pl;
	plr->rchild = p;

	p->height = Height(p);
	pl->height = Height(pl);
	plr->height = Height(plr);

	if (root == p)
		root = plr;

	return plr;

}

struct node* RRRotation(struct node* p)
{
	struct node* pr = p->rchild;
	struct ndoe* prl = p->rchild->lchild;

	pr->lchild = p;
	p->rchild = prl;

	p->height = Height(p);
	pr->height = Height(pr);

	if (p == root)
		root = pr;

	return pr;
}

struct node* RLRotation(struct node* p)
{
	struct node* pr = p->rchild;
	struct node* prl = pr->lchild;

	pr->lchild = prl->rchild;
	p->rchild = prl->lchild;
	prl->lchild = p;
	prl->rchild = pr;

	p->height = Height(p);
	pr->height = Height(pr);
	prl->height = Height(prl);

	if (root == p)
		root = prl;

	return prl;

}

struct node* RInsert(struct node* p, int key)
{
	struct node* t;

	if (p == NULL)
	{
		t = (struct node*)malloc(sizeof(struct node));
		t->data = key;
		t->lchild = t->rchild = NULL;
		t->height = 1;
		return t;
	}

	else if (key < p->data)
		p->lchild = RInsert(p->lchild, key);
	else if (key > p->data)
		p->rchild = RInsert(p->rchild, key);

	p->height = Height(p);

	if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
		return LLRotation(p);
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
		return LRRotation(p);
	else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
		return RRRotation(p);
	else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
		return RLRotation(p);

	return p;
}

int main()
{
	root = RInsert(root, 10);
	RInsert(root, 30);
	RInsert(root, 20);

	return 0;
}