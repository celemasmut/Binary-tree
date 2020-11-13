#include "Binary tree.h"

nodoTree*inicTree()
{
    return NULL;
}
nodoTree*createNodoTree(stEmpleado dat)
{
    nodoTree*new1=(nodoTree*)malloc(sizeof(nodoTree));
    new1->dat=dat;
    new1->left=NULL;
    new1->right=NULL;
    return new1;
}
nodoTree*insertTree(nodoTree* tree, nodoTree*new1)
{
    if(!tree)
    {
        tree=new1;
    }
    else{//This instance compares which dni is bigger. using atoi to transform a string into int.
        if(atoi(new1->dat.persona.dni) > atoi(tree->dat.persona.dni))
        {
            tree->right=insertTree(tree->right,new1);
        }
        else{
            tree->left=insertTree(tree->left,new1);
        }
    }
    return tree;
}

void showTree(nodoTree*tree)
{
    mostrarEmpleado(tree->dat);
}

void inOrder(nodoTree*tree)
{
    if(tree)
    {
        inOrder(tree->left);
        showTree(tree);
        inOrder(tree->right);
    }
}

void preOrder(nodoTree*tree)
{
    if(tree)
    {
        showTree(tree);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void postOrder(nodoTree*tree)
{
    if(tree)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        showTree(tree);
    }
}

nodoTree*lookingforNodoTree(nodoTree*tree,stEmpleado d)
{
    nodoTree*asw=NULL;
    if(tree)
    {
        if( atoi(d.persona.dni) == atoi(tree->dat.persona.dni))
        {
            asw=tree;
        }
        else{
            if(atoi(d.persona.dni) > atoi(tree->dat.persona.dni))
            {
                asw=lookingforNodoTree(tree->right,d);
            }
            else{
                asw=lookingforNodoTree(tree->left,d);
            }
        }
    }
    return asw;
}
