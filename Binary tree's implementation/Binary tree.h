#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
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
nodoTree*lookingforNodoTree(nodoTree*tree,stEmpleado d);

#endif // BINARY_TREE_H_INCLUDED
