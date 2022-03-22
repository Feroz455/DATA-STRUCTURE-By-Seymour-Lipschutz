#include <iostream>
using namespace std;
#define SPACE 10
class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};
class AVLTree
{
public:
    TreeNode *root;
    AVLTree()
    {
        root = NULL;
    }
    bool isTreeEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
            return false;
    }
    // Get Height
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        else
        {
            // Compute the height of each subtree
            int lheight = height(root->left);
            int rheight = height(root->right);
            // Use the larger one
            if (lheight > rheight)
            {
                return (lheight + 1);
            }
            else
                return (rheight + 1);
        }
    }

    // Get Balance factor of node N
    int getBalancefactor(TreeNode *root)
    {
        if (root == NULL)
            return -1;
        return height(root->left) - height(root->right);
    }
    TreeNode *rightRotate(TreeNode *y)
    {
        TreeNode *x = y->left;
        TreeNode *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;
        return x;
    }

    TreeNode *leftRotate(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        return y;
    }

    TreeNode *insert(TreeNode *root, TreeNode *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            cout << "Value inserted successfully" << endl;
            return root;
        }
        if (new_node->value < root->value)
        {
            root->left == insert(root->left, new_node);
        }
        else if (new_node->value > root->value)
        {
            root->right = insert(root->right, new_node);
        }
        else
        {
            cout << "No duplication values allowed!" << endl;
            return root;
        }
        int bf = getBalancefactor(root);
        // Left left case
        if (bf > 1 && new_node->value < root->left->value)
        {
            return rightRotate(root);
        }
        // Right Right Case
        if (bf < -1 && new_node->value > root->right->value)
        {
            return leftRotate(root);
        }
        // Left Right Case
        if (bf > 1 && new_node->value > root->left->value)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        // Right Left Case
        if (bf < -1 && new_node->value < root->right->value)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    TreeNode *minValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        // Loop down to find the leftmost leaf
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
    TreeNode *deleteNode(TreeNode *root, int value)
    {
        if (root == NULL)
        {
            return NULL;
        }
        // If the key to be deleted is smaller then the root's key
        // the it lies in left subtree
        else if (value < root->value)
        {
            root->left = deleteNode(root->left, value);
        }
        // If the key to be deleted is greater then the root's key
        // Then it lies in right subtree
        else if (value > root->value)
        {
            root->right = deleteNode(root->right, value);
        }
        // If key is same as root's key then This is the node to be
        // Deleted
        else
        {
            // node with only one child or no child
            if (root->left == NULL)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                // node with two children
                // Get the inorder successor(Samllest
                // in the right subtree )
                TreeNode *temp = minValueNode(root->right);
                // copy the inorder successor's content to this node
                root->value = temp->value;
                root->right = deleteNode(root->right, temp->value);
                // deletedNode(root->right, temp->value);
            }
        }
        int bf = getBalancefactor(root);
        // Left Left Imbalance / Case or right rotation
        if (bf == 2 && getBalancefactor(root->left) >= 0)
        {
            return rightRotate(root);
        }
        // Left Right Imbalance / Case or LR ratation
        else if (bf == 2 && getBalancefactor(root->left) == -1)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        // Right Right Imbalance/ Case or left rotation
        else if (bf == -2 && getBalancefactor(root->right) <= 0)
        {
            return leftRotate(root);
        }
        else if (bf == -2 && getBalancefactor(root->right) == 1)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    void print2D(TreeNode *root, int space)
    {
        // Base Case 1
        if (root == NULL)
        {
            return;
        }
        // Increase distance between levels 2
        space += SPACE;
        print2D(root->right, space);
        cout << endl;
        for (int i = SPACE; i < space; i++)
        {
            cout << " ";
        }
        cout << root->value << "\n";
        print2D(root->left, space);
    }
    void printPreorder(TreeNode *root)
    {
        if (root != NULL)
        {
            cout << root->value;
            printPreorder(root->left);
            printPreorder(root->right);
        }
    }
    void printInorder(TreeNode *root)
    {
        if (root != NULL)
        {
            printInorder(root->left);
            cout << root->value;
            printInorder(root->right);
        }
    }
    void printPostorder(TreeNode *root)
    {
        if (root != NULL)
        {
            printPostorder(root->left);
            printPostorder(root->right);
            cout << root->value;
        }
    }
    void printGivenLevel(TreeNode *root, int level)
    {
        if (root == NULL)
        {
            return;
        }
        else if (level == 0)
        {
            cout << root->value;
        }
        else
        {
            printGivenLevel(root->left, level - 1);
            printGivenLevel(root->right, level - 1);
        }
    }
    void printLevelOrderBFS(TreeNode *root)
    {
        int h = height(root);
        for (int i = 0; i <= h; i++)
        {
            printGivenLevel(root, i);
        }
    }
    TreeNode *iterativeSearch(int value)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (value == temp->value)
                {
                    return temp;
                }
                else if (value < temp->value)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }
    TreeNode *recursiveSearch(TreeNode *root, int value)
    {
        if (root == NULL || root->value == value)
        {
            return root;
        }
        else if (value < root->value)
        {
            return recursiveSearch(root->left, value);
        }
        else
        {
            return recursiveSearch(root->right, value);
        }
    }
};
int main()
{
    AVLTree obj;
    int option, val;

    do
    {
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal AVL Tree values" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;
        cin >> option;
        // Node n1
        TreeNode *new_node = new TreeNode();
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "AVL INSERT" << endl;
            cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
            cin >> val;
            new_node->value = val;
            obj.root = obj.insert(obj.root, new_node);
            cout << endl;
            break;
        case 2:
            cout << "SEARCH" << endl;
            cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
            cin >> val;
            // new_node = obj.iterativeSearch(val);
            new_node = obj.recursiveSearch(obj.root, val);
            if (new_node != NULL)
            {
                cout << "Value found" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 3:
            cout << "DELETE" << endl;
            cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
            cin >> val;
            new_node = obj.recursiveSearch(obj.root, val);
            if (new_node != NULL)
            {
                obj.root = obj.deleteNode(obj.root, val);
                cout << "Value Deleted" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 4:
            cout << "PRINT 2D: " << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            // cout <<"Print Level Order BFS: \n";
            // obj.printLevelOrderBFS(obj.root);
            // cout <<endl;
            //	      cout <<"PRE-ORDER: ";
            //	      obj.printPreorder(obj.root);
            //	      cout<<endl;
            //	      cout <<"IN-ORDER: ";
            //	      obj.printInorder(obj.root);
            //	      cout<<endl;
            //	      cout <<"POST-ORDER: ";
            //	      obj.printPostorder(obj.root);
            break;
        case 5:
            cout << "TREE HEIGHT" << endl;
            cout << "Height : " << obj.height(obj.root) << endl;
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}