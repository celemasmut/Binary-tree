#include <stdio.h>
#include <stdlib.h>
#include "Binary tree.h"
#define archivo1 "employers.bin"

nodoTree*archToTree(nodoTree*tree,char archEmployers[]);


int main()
{
    nodoTree*tree=inicTree();
    tree=archToTree(tree,archivo1);
    inOrder(tree);
    int levels;
    int heigh;
    levels=amountOfLevels(tree);
    printf("\nThe amount of levels is: %d",levels);
    heigh=amountOfHeigh(tree);
    printf("\nIt's heigh is %d",heigh);
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
