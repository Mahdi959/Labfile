/////////////////////////////////////////////////////////////////////////////////////
//
// File name : tree.cpp
//
// This program  contains the implementation of the tree class member functions.
//
// Programmer : Mahdi Ashrafee
//
// Date created : in the past
//
// Date last revised : 5/11/2023
//
/////////////////////////////////////////////////////////////////////////////////////
#include "tree.h"
#include "employee.h"
using namespace std;


//constructor
template <class BaseData>
tree<BaseData>::tree()
{
    root = 0;
}

//destructor
template <class BaseData>
tree<BaseData>::~tree()
{
    if (root)
        destroy(root);
}


/////////////////////////////////// destroy //////////////////////////////////////////
//
// purpose: Recursively destroys the tree by deleting each node.
//
// input parameters: p - Pointer to the current node.
//
// output parameters: None
//
// return value: None
//
/////////////////////////////////////////////////////////////////////////////////////

template <class BaseData>
void tree<BaseData>::destroy(TreeNode<BaseData>* p)
{
    if (p)
    {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}

/////////////////////////////////// tree (copy constructor) ///////////////////////////
//
// purpose: Creates a new tree as a copy of an existing tree.
//
// input parameters: t - Reference to the existing tree.
//
// output parameters: None
//
// return value: None
//
/////////////////////////////////////////////////////////////////////////////////////
template <class BaseData>
tree<BaseData> ::tree(tree<BaseData>& t)
{
    root = 0;
    copyTreeNode(&root, t.root);
}

/////////////////////////////////// operator= //////////////////////////////////////////
//
// purpose: Overloads the assignment operator to copy the contents of one tree to another.
//
// input parameters: t - Reference to the tree to be copied.
//
// output parameters: None
//
// return value: Reference to the copied tree.
//
/////////////////////////////////////////////////////////////////////////////////////
template <class BaseData>
tree<BaseData>& tree<BaseData>:: operator = (const tree<BaseData>& t)
{
    if (this == &t) return *this;
    if (root)
        destroy(root);
    root = 0;
    copyTreeNode(&root, t.root);
    return *this;
} 

/////////////////////////////////// inOrder //////////////////////////////////////////
//
// purpose: Performs an in-order traversal of the tree and prints the nodes.
//
// input parameters: p - Pointer to the current node.
//
// output parameters: None
//
// return value: None
//
/////////////////////////////////////////////////////////////////////////////////////
template <class BaseData>
void tree<BaseData>::inOrder(TreeNode<BaseData>* p)
{
    if (p)
    {
        inOrder(p->left);
        cout << p->TreeData;
        inOrder(p->right);
    }
}//END InOrder;

/////////////////////////////////// preOrder //////////////////////////////////////////
//
// purpose: Performs a pre-order traversal of the tree and prints the nodes.
//
// input parameters: p - Pointer to the current node.
//
// output parameters: None
//
// return value: None
//
/////////////////////////////////////////////////////////////////////////////////////
template <class BaseData>
void tree<BaseData>::preOrder(TreeNode<BaseData>* p)
{
    if (p)
    {
        cout << p->TreeData;
        preOrder(p->left);
        preOrder(p->right);
    }
}//END PreOrder;

/////////////////////////////////// postOrder //////////////////////////////////////////
//
// purpose: Performs a post-order traversal of the tree and prints the nodes.
//
// input parameters: p - Pointer to the current node.
//
// output parameters: None
//
// return value: None
//
/////////////////////////////////////////////////////////////////////////////////////
template <class BaseData>
void tree<BaseData>::postOrder(TreeNode<BaseData>* p)
{
    if (p)
    {
        postOrder(p->left);
        postOrder(p->right);
        cout << p->TreeData;
    }
}//END PostOrder; */

/////////////////////////////////// SearchAndDestroy //////////////////////////////////////////
//
// purpose: Searches for a node with the given target value and removes it from the tree.
//
// input parameters: target - The value to be searched and destroyed.
//
// output parameters: None
//
// return value: None
//
/////////////////////////////////////////////////////////////////////////////////////
template <class BaseData>
void tree<BaseData>::SearchAndDestroy(BaseData target)
{
    TreeNode<BaseData>* previous, * current;

    current = root;
    previous = 0;
    while (current && (current->TreeData != target))
    {
        previous = current;
        if (current->TreeData > target)
            current = current->left;
        else current = current->right;
    }  //(*while*)
    if (!current)    //target not found
    {
        cout << "target not found " << endl;
        return;
    }

    //remove requires the actual node in the tree
    if (current == root)  remove(root);
    else
    {
        if (previous->left == current) remove(previous->left);
        else remove(previous->right);
    }
    cout << "Success!";
}//END SearchAndDestroy;





/////////////////////////////////// remove //////////////////////////////////////////
//
// purpose: Removes the given node from the tree.
//
// input parameters: current - Reference to the pointer pointing to the current node.
//
// output parameters: None
//
// return value: None
//
/////////////////////////////////////////////////////////////////////////////////////

template<class BaseData>
void tree<BaseData>::remove(TreeNode<BaseData>*& current)
{
    TreeNode<BaseData>* previous, * temp;
    // (*the pointer sent in is the parent (left or right) in the tree*)
    temp = current;
    if (current->left == 0 && current->right == 0)  //leaf node
        current = 0;                                //parent is null
    else
    {
        if (current->left == 0)       //  no left child
            current = current->right; //  replace with right child
        else                          //  has left child
        {
            temp = current->left;
            previous = current;
            while (temp->right != 0)
            {
                previous = temp;     // locate TreeNode that has the
                temp = temp->right;  // largest value smaller than
            }                      // the value of TreeNode to be
          // deleted
            current->TreeData = temp->TreeData; // replace with
            //that TreeData
            if (previous == current)      //  replace is left child
                previous->left = temp->left;
            else {
                previous->right = temp->left;
            }// replace is down rt
            // subtree of left child
        }

    }
    delete temp;
}//END Delete;

/////////////////////////////////// emptyTree //////////////////////////////////////////
//
// purpose: Checks if the tree is empty.
//
// input parameters: None
//
// output parameters: None
//
// return value: Returns 1 if the tree is empty, otherwise returns 0.
//
/////////////////////////////////////////////////////////////////////////////////////
template<class BaseData>
int tree<BaseData> ::emptyTree()  const
{
    return !root;
}

/////////////////////////////////// fullTree //////////////////////////////////////////
//
// purpose: Checks if the tree is full.
//
// input parameters: None
//
// output parameters: None
//
// return value: Returns 1 if the tree is full, otherwise returns 0.
//
/////////////////////////////////////////////////////////////////////////////////////
template<class BaseData>
int tree<BaseData> ::fullTree()   const
{
    TreeNode<BaseData>* temp = new TreeNode<BaseData>;

    if (!temp) return 1;
    delete temp;
    return 0;
}


/////////////////////////////////// insert //////////////////////////////////////////
//
// purpose: Inserts a new node with the given item into the tree.
//
// input parameters: item - The value to be inserted.
//
// output parameters: None
//
// return value: None
//
/////////////////////////////////////////////////////////////////////////////////////
template <class BaseData>
void tree<BaseData> ::insert(BaseData& item)
{
    insertNode(&root, item);
}


/////////////////////////////////// insertNode //////////////////////////////////////////
//
// purpose: Inserts a new node with the given item into the tree.
//
// input parameters: into - Reference to the pointer pointing to the current node.
// item - The value to be inserted.
//
// output parameters: None
//
// return value: None
//
/////////////////////////////////////////////////////////////////////////////////////
template <class BaseData>
void tree<BaseData>::insertNode(TreeNode<BaseData>** into, BaseData& item)
{
    if (!(*into))
    {
        *into = getnode(item);
        return;
    }
    if (item < (*into)->TreeData && !((*into)->left))
        (*into)->left = tree<BaseData>::getnode(item);
    else if (item < (*into)->TreeData)
        insertNode(&((*into)->left), item);
    else if (item >= (*into)->TreeData && !((*into)->right))
        (*into)->right = tree<BaseData>::getnode(item);
    else insertNode(&((*into)->right), item);

}

/////////////////////////////////// getnode //////////////////////////////////////////
//
// purpose: Creates a new tree node with the given item.
//
// input parameters: item - The value to be inserted.
//
// output parameters: None
//
// return value: Pointer to the newly created tree node.
//
/////////////////////////////////////////////////////////////////////////////////////
template <class BaseData>
TreeNode <BaseData>* tree<BaseData>::getnode(BaseData& item)
{
    TreeNode<BaseData>* temp = new TreeNode<BaseData>;
    if (temp)
    {
        temp->TreeData = item;
        temp->left = 0;
        temp->right = 0;
    }
    return temp;
}

/////////////////////////////////// copyTreeNode //////////////////////////////////////////
//
// purpose: Copies a tree node from one tree to another.
//
// input parameters: into - Reference to the pointer pointing to the current node in the new tree.
// from - Pointer to the current node in the existing tree.
//
// output parameters: None
//
// return value: None
//
/////////////////////////////////////////////////////////////////////////////////////
template <class BaseData>
void tree<BaseData>::copyTreeNode(TreeNode <BaseData>** into,
    TreeNode<BaseData>* from)
{
    if (!from) return;
    insertNode(&(*into), from->TreeData);
    copyTreeNode(&(*into), from->left);
    copyTreeNode(&(*into), from->right);
}

/////////////////////////////////// writeTree //////////////////////////////////////////
//
// purpose: Writes the tree nodes in the specified order (pre-order, in-order, or post-order).
//
// input parameters: choice - The choice of traversal order (1: pre-order, 2: in-order, 3: post-order).
//
// output parameters: None
//
// return value: None
//
/////////////////////////////////////////////////////////////////////////////////////
template <class BaseData>
void tree<BaseData>::writeTree(int choice)
{
    switch (choice)
    {
    case 1:
        tree<BaseData>::preOrder(root);
        break;
    case 2:
        tree<BaseData>::inOrder(root);
        break;
    case 3:
        tree<BaseData>::postOrder(root);
        break;
    default:
        cout << "tree not written" << endl;
    }//end switch
}//end write Tree

/////////////////////////////////// retrieve //////////////////////////////////////////
//
// purpose: Retrieves a node with the given target value from the tree.
//
// input parameters: target - The value to be searched.
//
// output parameters: None
//
// return value: Pointer to the retrieved node, or nullptr if not found.
//
/////////////////////////////////////////////////////////////////////////////////////
template <class BaseData>
BaseData* tree<BaseData>::retrieve(const BaseData& target) {
    TreeNode<BaseData>* current = root;
    while (current != nullptr) {
        if (target == current->TreeData) {
            return &current->TreeData;
        }
        else if (target < current->TreeData) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return nullptr;
}
/////////////////////////////////// listBySuboption //////////////////////////////////////////
//
// purpose: Lists the nodes in the tree based on the given suboption.
//
// input parameters: suboption - The suboption to determine which nodes to list.
//
// output parameters: None
//
// return value: None
//
/////////////////////////////////////////////////////////////////////////////////////
template <class BaseData>
void tree<BaseData>::listBySuboption(const std::string& suboption) {
    listBySuboptionHelper(root, suboption);
}
/////////////////////////////////// listBySuboptionHelper //////////////////////////////////////////
//
// purpose: Helper function to perform the recursive traversal and listing of nodes based on the suboption.
//
// input parameters: current - Pointer to the current node.
// suboption - The suboption to determine which nodes to list.
//
// output parameters: None
//
// return value: None
//
/////////////////////////////////////////////////////////////////////////////////////
template <class BaseData>
void tree<BaseData>::listBySuboptionHelper(TreeNode<BaseData>* current, const std::string& suboption) {
    if (current != nullptr) {
        listBySuboptionHelper(current->left, suboption);

        std::string empCode(1, current->TreeData.getEmpCode());
        std::string sub(suboption);

        if (sub == "A" ||
            (sub == "O" && empCode == "O") ||
            (sub == "F" && empCode == "F") ||
            (sub == "S" && empCode == "S")) {
            std::cout << current->TreeData << std::endl;
        }

        listBySuboptionHelper(current->right, suboption);
    }
}







/////////////////////////////////// savePreOrder //////////////////////////////////////////
//
// purpose: Saves the nodes of the tree in pre-order traversal to the specified output file.
//
// input parameters: outfile - Reference to the output file stream.
// current - Pointer to the current node.
//
// output parameters: None
//
// return value: None
//
/////////////////////////////////////////////////////////////////////////////////////
template <class BaseData>
void tree<BaseData>::savePreOrder(std::ofstream& outfile, TreeNode<BaseData>* current) {
    if (current != nullptr) {
        outfile << current->TreeData << std::endl;
        savePreOrder(outfile, current->left);
        savePreOrder(outfile, current->right);
    }
}
