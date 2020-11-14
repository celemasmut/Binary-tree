#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "employers.h"
typedef struct nodoTree
{
    stEmpleado dat;
    struct nodoTree*left;
    struct nodoTree*right;
}nodoTree;


nodoTree*inicTree();
nodoTree*createNodoTree(stEmpleado dat);
nodoTree*insertTree(nodoTree* tree, nodoTree*new1);
void showTree(nodoTree*tree);
void inOrder(nodoTree*tree);
void preOrder(nodoTree*tree);
void postOrder(nodoTree*tree);
nodoTree*searchingNodoTree(nodoTree*tree,char dni);
nodoTree*searchingByNameNTree(nodoTree*tree,char lastName[]);
int bigger(int right,int left);
int amountOfLevels(nodoTree*tree);
int amountOfHeigh(nodoTree*tree);
int amountOfNodos(nodoTree*tree);
int amountOfleaf(nodoTree*tree);
int sumSalary(nodoTree*tree);


#endif // BINARY_TREE_H_INCLUDED
