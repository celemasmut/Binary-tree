#include <stdio.h>
#include <stdlib.h>
#include "DoubleListEmployers.h"
#include "Binary tree.h"
#include "employers.h"
#define archivo1 "employers.bin"
nodoTree*archToTree(nodoTree*tree,char archEmployers[]);
nodo2*treeToDList(nodoTree*tree,nodo2*list);


int main()
{
    nodoTree*tree=inicTree();
    tree=archToTree(tree,archivo1);
    inOrder(tree);
    int levels;
    int heigh;
    int amtNodos;
    int amtleaf;
    levels=amountOfLevels(tree);
    printf("\nThe amount of levels is: %d",levels);
    heigh=amountOfHeigh(tree);
    printf("\nIt's heigh is %d",heigh);
    amtNodos=amountOfNodos(tree);
    printf("\nAmount of Nodos is %d",amtNodos);
    amtleaf=amountOfleaf(tree);
    printf("\nleaf %d",amtleaf);
    return 0;
}

nodoTree*archToTree(nodoTree*tree,char archEmployers[])
{
    FILE*arch=fopen(archEmployers,"rb");
    stEmpleado e;
    if(arch)
    {
        while(fread(&e,sizeof(stEmpleado),1,arch) > 0)
        {
            tree=insertTree(tree,createNodoTree(e));
        }
        fclose(arch);
    }
    return tree;
}
nodo2*treeToDList(nodoTree*tree,nodo2*list)
{
    if(tree)
    {//if I want to add in order have to use logic of inorder.
        tree=treeToDList(tree->left,list);
        list=addAtheEndDoubList(list,createNewNodoDoubList(tree->dat));
        tree=treeToDList(tree->right,list);
    }
    return list;
}
