#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bToDLL(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    struct TreeNode* left_head = bToDLL(root->left);
    struct TreeNode* right_head = bToDLL(root->right);

    struct TreeNode* left_tail = left_head;
    while (left_tail != NULL && left_tail->right != NULL) {
        left_tail = left_tail->right;
    }

    struct TreeNode* right_tail = right_head;
    while (right_tail != NULL && right_tail->left != NULL) {
        right_tail = right_tail->left;
    }

    if (left_head != NULL) {
        left_tail->right = root;
        root->left = left_tail;
    }
    if (right_head != NULL) {
        root->right = right_head;
        right_head->left = root;
    }
    return (left_head != NULL) ? left_head : root;
}

void print_list_forwards(struct TreeNode* head) {
    struct TreeNode* node = head;
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->right;
    }
    printf("\n");
}

void print_list_backwards(struct TreeNode* tail) {
    struct TreeNode* node = tail;
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->left;
    }
    printf("\n");
}

int main() {
   struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->val = 10;
    root->left = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->left->val = 20;
    root->left->left = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->left->left->val = 40;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->left->right->val = 60;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->right->val = 30;
    root->right->left = NULL;
    root->right->right = NULL;
    struct TreeNode* head = bToDLL(root);
    print_list_forwards(head);
    print_list_backwards(root->left->left);
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);
    return 0;
}
