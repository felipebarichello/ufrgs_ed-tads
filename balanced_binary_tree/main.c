#include <stdio.h>
#include "bbt.h"


int main() {
    BalancedBinaryTree tree = BBTCreate();

    BBTPrintList(tree, BBT_TRAVERSAL_IN, BBT_LEFT);

    BBTInsertOrdered(&tree, 5); //       5        |
    BBTInsertOrdered(&tree, 3); //     /   \      |
    BBTInsertOrdered(&tree, 7); //    3     7     |
    BBTInsertOrdered(&tree, 2); //   / \   / \    |
    BBTInsertOrdered(&tree, 4); //  2   4 6   8   |
    BBTInsertOrdered(&tree, 6); //                |
    BBTInsertOrdered(&tree, 8); //                |

    BBTPrintList(tree, BBT_TRAVERSAL_IN, BBT_LEFT);

    printf("O programa roda\n");

    return 0;
}
