#include <stdio.h>
#include "bst.h"


int main() {
    BinarySearchTree tree = BSTCreate();

    BSTInsertOrdered(&tree, 5); //       5        |
    BSTInsertOrdered(&tree, 3); //     /   \      |
    BSTInsertOrdered(&tree, 7); //    3     7     |
    BSTInsertOrdered(&tree, 2); //   / \   / \    |
    BSTInsertOrdered(&tree, 4); //  2   4 6   8   |
    BSTInsertOrdered(&tree, 6); //                |
    BSTInsertOrdered(&tree, 8); //                |

    printf("O programa roda\n");

    return 0;
}
