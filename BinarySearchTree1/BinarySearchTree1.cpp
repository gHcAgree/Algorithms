#include "BSTree.h"
#include <string.h>

int main() {
	const char* treeString = "10(6(4,8),14(12,16))";
	int pointer = 0;
	Node root = createBSTree(treeString,pointer,strlen(treeString));
}
