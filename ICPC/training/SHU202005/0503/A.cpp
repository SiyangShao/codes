#include <stdio.h>
#include <cstring>
#include <iostream>
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
	cout << node->elem;
	return;
}

int main() {
	char pr[30], in[30];
	while (~scanf("%s%s", &pr, &in)) {
        int len = 0;
        for(int i = 0 ; i < 30 ; i++){
            if(pr[i]==0){
                len = i;
                break;
            }
        }
		BinaryTreeFromOrderings(in, pr, len);
		printf("\n");
        memset(pr,0,sizeof(pr));
        memset(in,0,sizeof(in));
	}
	return 0;
}