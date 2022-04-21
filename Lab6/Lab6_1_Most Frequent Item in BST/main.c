#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *right, *left;
}treenode;
//global to use it in "inorderTraveral"
int N;

treenode *creatNode(int key);
treenode *levelOrder(treenode *root, int key);
treenode *constructTree(int arr[], int n);
// global to store the elements from recursion
int a =0, arr[10000];
void inorderTraversal(treenode* root)
{
    if (!root)
        return;

    inorderTraversal(root->left);
    //printf("%d ", root->key);
    arr[a] = root->key;
    a++;
    inorderTraversal(root->right);
}


int main()
{
    int  j;
    scanf("%d", &N);
    int nums[N];
    for (j = 0; j<N; j++)
    {
        scanf("%d", &nums[j]);
    }

   treenode *root = constructTree(nums, N);

    inorderTraversal(root);
    //freq_num contain the most frequent numbers and freq contains how many each element repeated
    //pose is the index in freq_num and freq arrays
    //most_freq store the most number of repeats
    int freq_num[N], freq[N], pose=0, most_freq = 0;
    int comp = arr[0], count = 0;
    for (a = 1; a< N; a++)
    {

        if(comp == arr[a])
            count ++;
        else
        {
            freq_num[pose] = comp;
            freq[pose] = count;
            if(count > most_freq)
                most_freq = count;
            pose ++;
            comp = arr[a];
            count = 0;
            if(arr[a] == 0)
                break;
        }
    }
    for(a = 0; a<pose; a++)
    {
        if(freq[a] == most_freq)
            printf("%d\n", freq_num[a]);
    }

    return 0;
}

treenode *creatNode(int key)
{
    treenode *newNode = (treenode *)malloc(sizeof(treenode));

    newNode ->key = key;
    newNode ->right = newNode ->left = NULL;
    return newNode;
}

treenode *levelOrder(treenode *root, int key)
{
    if(root == NULL)
    {
        root = creatNode(key);
        return root;
    }
    if(key <= root->key && key != -1)
        root->left = levelOrder(root->left, key);
     else if(key > root->key && key != -1)
        root->right = levelOrder(root->right, key);
    return root;
}
treenode *constructTree(int arr[], int n)
{
    if(n == 0)
        return NULL;
    treenode *root = NULL;
    int a;
    for(a = 0; a<n; a++)
    {
        root = levelOrder(root, arr[a]);
    }
    return root;
}


