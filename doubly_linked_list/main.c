#include <stdio.h>
#include "dll.h"


int main() {
    DLLNode* products = NULL;
    
    DLLInsert(&products, (DLLData) { 3, "caneta",  2.5   });
    DLLInsert(&products, (DLLData) { 1, "lapis",   1.5   });
    DLLInsert(&products, (DLLData) { 4, "teclado", 100.0 });
    DLLInsert(&products, (DLLData) { 2, "mouse",   55.0  });

    printf("\nImprimir: ");
    DLLPrint(products);

    printf("\nImprimir reverso: ");
    DLLPrintReverse(products);
    
    DLLRemove(&products, 2);
    printf("\nRemover produto 2: ");
    DLLPrint(products);

    DLLDestroy(&products);
    printf("\nDestruir lista: ");
    DLLPrint(products);
}
