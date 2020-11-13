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
    else //This instance compares which dni is bigger. using atoi to transform a string into int.
    {
        if(atoi(new1->dat.persona.dni) > atoi(tree->dat.persona.dni))
        {
            tree->right=insertTree(tree->right,new1);
        }
        else
        {
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
//searching someone by dni
nodoTree*searchingNodoTree(nodoTree*tree,char dni)
{
    nodoTree*asw=NULL;
    if(tree)
    {
        if( atoi(dni) == atoi(tree->dat.persona.dni))
        {
            asw=tree;
        }
        else
        {
            if(atoi(dni) > atoi(tree->dat.persona.dni))
            {
                asw=searchingNodoTree(tree->right,dni);
            }
            else
            {
                asw=searchingNodoTree(tree->left,dni);
            }
        }
    }
    return asw;
}

nodoTree*searchingByNameNTree(nodoTree*tree,char lastName[])
{
    nodoTree*wanted=inicTree();
    if(tree)
    {
        if(strcmpi(tree->dat.persona.apellido,lastName) == 0)
        {
            wanted=tree;
        }
        else
        {
            wanted=searchingByNameNTree(tree->left,lastName);
            if(!wanted)
                wanted=searchingByNameNTree(tree->right,lastName);
        }
    }
    return wanted;
}

int bigger(int right,int left)
{
    int asw=0;
    if(right==left)
    {
        asw=right;
    }
    else
    {
        if(right>left)
        {
            asw=right;
        }
        else
        {
            asw=left;
        }
    }
    return asw;
}
int amountOfLevels(nodoTree*tree)
{
    int level=0;
    if(tree)
    {
        if(tree->right || tree->left)
        {
            level=1 + bigger(amountOfLevels(tree->right), amountOfLevels(tree->left));
        }
    }
    return level;
}
int amountOfHeigh(nodoTree*tree)
{
    int heigh=0;
    if(tree)
    {
        heigh=1;
        if(tree->right || tree->left)
        {
            heigh=1+ bigger(amountOfHeigh(tree->right), amountOfHeigh(tree->left));
        }
    }
    return heigh;
}

int amountOfNodos(nodoTree*tree)
{
    int amt=0;
    if(tree)
    {
        amt=1;
        if(tree->left || tree->right)
        {
            amt=1+ amountOfNodos(tree->left) + amountOfNodos(tree->right);
        }
    }
    return amt;
}

int amountOfleaf(nodoTree*tree)
{
    int amt=0;
    if(tree)
    {
        if(tree->left || tree->right)
        {
            amt=amountOfleaf(tree->left)+amountOfleaf(tree->right);
            if(tree->left ==NULL)
            {
                amt++;
            }if(tree->right==NULL)
            {
                amt++;
            }
        }
    }
    return amt;
}
