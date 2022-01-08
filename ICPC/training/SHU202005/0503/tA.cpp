#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	struct TreeNode *left;
	struct TreeNode *right;
	char elem;
};

void BinaryTreeFromOrderings(char *inorder, char *preorder, int length) {
	if (length == 0) {
		// cout<<"invalid length";
		return;
	}
	TreeNode *node = new TreeNode; // Noice that [new] should be written out.
	node->elem = *preorder;
	int rootIndex = 0;
	for (; rootIndex < length; rootIndex++) {
		if (inorder[rootIndex] == *preorder)
			break;
	}
	// Left
	BinaryTreeFromOrderings(inorder, preorder + 1, rootIndex);
	// Right
	BinaryTreeFromOrderings(inorder + rootIndex + 1, preorder + rootIndex + 1,
							length - (rootIndex + 1));
	cout << node->elem << endl;
	return;
}

int main() {
	printf("Hello World!\n");
	char *pr = "DBACEGF";
	char *in = "ABCDEFG";

	BinaryTreeFromOrderings(in, pr, 7);

	printf("\n");
	return 0;
}