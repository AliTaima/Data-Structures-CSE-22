#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *right, *left;
    int height;
}avl_node;

int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

avl_node *creatNode(int key)
{
    avl_node *newNode = (avl_node *)malloc(sizeof(avl_node));
    newNode ->key = key;
    newNode ->right = newNode->left =NULL;
    newNode ->height = 0;
    return newNode;
}

int height(avl_node *N)
{
    if (N == NULL)
        return -1;
    return N->height;
}

int getBalance(avl_node *N)
{
    if(N == NULL)
        return -1;
    return height(N->left) - height(N->right);
}

avl_node *leftRotate(avl_node *a)
{
    avl_node *b = a->right;
    avl_node *T2 = b->left;

    b ->left = a;
    a ->right = T2;

    a ->height = max(height(a->left), height(a->right)) + 1;
    b ->height = max(height(b->left), height(b->right)) + 1;

    return b;
}

avl_node *rightRotate(avl_node *c)
{
    avl_node *b = c->left;
    avl_node *T2 = b ->right;

    b ->right = c;
    c ->left = T2;

    c ->height = max(height(c->left ), height(c->right)) + 1;
    c ->height = max(height(b->left), height(b->right)) + 1;

    return b;
}

avl_node *insertNode(avl_node *node, int key)
{
    //find the correct position to insert the new node and insert it
    if(node == NULL)
        return creatNode(key);

    if(key < node ->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node ->right, key);
    else
        return node;
    //update the balance factor of each node and balance the tree

    node->height = 1 + max(height(node ->left), height(node->right));

    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->right->key)
    {
        node ->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;

}

avl_node *constructTree(int arr[], int n)
{
    if(n == 0)
        return NULL;
    avl_node *root = NULL;
    int a;
    for(a = 0; a<n; a++)
    {
        root = insertNode(root, arr[a]);
    }
    return root;
}
int a =0, arr[10000];
void preorderTraversal(avl_node* root)
{

    if (!root)
        return;

    arr[a] = root->key;  //store preorder elements in array
    a++;
    preorderTraversal(root->left);
    preorderTraversal(root->right);

}

int main()
{
    int  N, j;
    scanf("%d", &N);
    int nums[N];
    for (j = 0; j<N; j++)
    {
        scanf("%d", &nums[j]);
    }
    avl_node *root = constructTree(nums, N);
    preorderTraversal(root);
    int b;
    for (b = 0; b<a; b++)
    {
        printf("%d", arr[b]);
        if(b != a-1)
            printf(",");
    }
    return 0;
}
