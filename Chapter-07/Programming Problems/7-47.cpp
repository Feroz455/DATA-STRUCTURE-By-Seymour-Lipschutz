/*
page 276
 7.47  Write a program which prints the list of employee records in alphabetical order. 
(Hint: Print the records in inorder.)
*/
#include<iomanip>
#include<iostream>
using namespace std;
typedef struct _tree
{
    string Name;
    string SSN;
    string SEX;
    int SALARY;
    _tree *left;
    _tree *right;
}TreeNode;

TreeNode* Insert(TreeNode *root,TreeNode data)
 {
	if(root == NULL) {
		root = new TreeNode();
		root->Name = data.Name;
        root->SSN = data.SSN;
        root->SEX = data.SEX;
        root->SALARY = data.SALARY;
		root->left = root->right = NULL;
	}
	else if(data.Name <= root->Name)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}
void in_order(TreeNode *root)
{
    if(root != NULL)
    {
        in_order(root->left);
        cout << setw(10) << root->Name << setw(15) << root->SSN << setw(10) << root->SEX << setw(10) << root->SALARY << endl;
        in_order(root->right);
    }
}
TreeNode* find_min(TreeNode *root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
TreeNode *Delete(TreeNode *root, string Name)
{
    if(root == NULL)
    {
        return root;
    }
    else
    if(root->Name > Name)
    {
        root->left = Delete(root->left, Name);
    }
    else 
    if(root->Name < Name)
    {
        root->right = Delete(root->right, Name);
    }
    else 
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else 
        if(root->left == NULL)
        {
            TreeNode *temp = root;
            root = root->right;
            delete temp;
        }
        else 
        if(root->right == NULL)
        {
            TreeNode *temp = root;
            root = root->left;
            delete temp;
          
        }
        else 
        {
            TreeNode *temp = find_min(root->right);
            root->Name = temp->Name;
            root->SSN = temp->SSN;
            root->SEX = temp->SEX;
            root->SALARY = temp->SALARY;
            root->right = Delete(root->right, temp->Name);
        }
    }
    return root;

}
int main()
{
    TreeNode temp;
    TreeNode *root = NULL;
    cout << "Enter details\n";
    for(int i = 0; i < 9; i++)
    {
        cin >> temp.Name;
        cin >> temp.SSN;
        cin >> temp.SEX;
        cin >> temp.SALARY;
        root = Insert(root,temp);
    }
    cout << setw(10) << "Name" << setw(15) << "SSN" << setw(10) << "SEX" << setw(10) << "SALARY" << endl;
    in_order(root);
    return 0;
}
/*
Enter details
Davis        
192-38-7282  
Female       
22800

Kelly
165-64-3351
Male
19000

Green
175-56-2251
Male
27200

Brown
178-52-1065
Female
14700


Lewis
181-58-9939
Female
16400

Cohen
177-44-4557
Male
19000

Rubin
135-46-6262
Female
15500

Evans
168-56-8113
Male
34200

Harris
208-56-1654
Female
22800
      Name            SSN       SEX    SALARY
     Brown    178-52-1065    Female     14700
     Cohen    177-44-4557      Male     19000
     Davis    192-38-7282    Female     22800
     Evans    168-56-8113      Male     34200
     Green    175-56-2251      Male     27200
    Harris    208-56-1654    Female     22800
     Kelly    165-64-3351      Male     19000
     Lewis    181-58-9939    Female     16400
     Rubin    135-46-6262    Female     15500

*/