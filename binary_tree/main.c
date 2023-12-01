#include <stdio.h>
#include "bt.h"


int main() {
    BinaryTree tree = BTCreate();

    BTInsertOrdered(&tree, 5); //       5        |
    BTInsertOrdered(&tree, 3); //     /   \      |
    BTInsertOrdered(&tree, 7); //    3     7     |
    BTInsertOrdered(&tree, 2); //   / \   / \    |
    BTInsertOrdered(&tree, 4); //  2   4 6   8   |
    BTInsertOrdered(&tree, 6); //                |
    BTInsertOrdered(&tree, 8); //                |

    printf("O programa roda\n");

    return 0;
}
