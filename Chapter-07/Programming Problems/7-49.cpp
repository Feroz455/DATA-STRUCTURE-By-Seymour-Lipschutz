/*
page 276
7.49  Write a program which reads the social security number SSS 
of an employee and prints the employee’s record. Test the program 
using (a) 165-64-3351, (b) 135-46-6262 and (c) 177-44-5555.
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
	else if(data.SSN <= root->SSN)
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
TreeNode *Delete(TreeNode *root, string SSN)
{
    if(root == NULL)
    {
        return root;
    }
    else
    if(root->SSN > SSN)
    {
        root->left = Delete(root->left, SSN);
    }
    else 
    if(root->SSN < SSN)
    {
        root->right = Delete(root->right, SSN);
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
            root->right = Delete(root->right, temp->SSN);
        }
    }
    return root;

}
void search(TreeNode *root, string SSN)
{
    if(root!= NULL)
    {
        if(root->SSN == SSN)
        {
            cout << setw(10) << root->Name << setw(15) << root->SSN << setw(10) << root->SEX << setw(10) << root->SALARY << endl;
            return;
        }
        search(root->left,SSN);
        search(root->right,SSN);

    }
}
int main()
{
    TreeNode temp;
    int n;
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
    cout << "\n\n";
    search(root,"165-64-3351");
    search(root,"135-46-6262");
    search(root,"177-44-5555");


    
    return 0;
}
/*
Output
Enter details
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
     Rubin    135-46-6262    Female     15500
     Kelly    165-64-3351      Male     19000
     Evans    168-56-8113      Male     34200
     Green    175-56-2251      Male     27200
     Cohen    177-44-4557      Male     19000
     Brown    178-52-1065    Female     14700
     Lewis    181-58-9939    Female     16400
     Davis    192-38-7282    Female     22800
    Harris    208-56-1654    Female     22800


     Kelly    165-64-3351      Male     19000
     Rubin    135-46-6262    Female     15500
*/