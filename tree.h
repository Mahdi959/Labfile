/////////////////////////////////////////////////////////////////////////////////////
//
// File name : tree.h
//
// This program contains the declaration of the tree class, which represents a
//  binary search tree data structure..
//
// Programmer : Mahdi Ashrafee
//
// Date created : in the past
//
// Date last revised : 5/11/2023
//
/////////////////////////////////////////////////////////////////////////////////////
#ifndef TREE_H
#define TREE_H
#include <iostream>


template <class BaseData>
struct TreeNode
{
    BaseData TreeData;
    TreeNode* left, * right;
};

//these are file level because traversals are recursive
void openOutFile();  //probably not the same as yours
std::ofstream opf;         //opf is ofstream object used

template <class BaseData>
class tree
{      //friend class stated here;
public:
    tree();
    ~tree();
    BaseData* retrieve(const BaseData& target);
    void listBySuboption(const std::string& suboption);
    void listBySuboptionHelper(TreeNode<BaseData>* current, const std::string& suboption);
    void savePreOrder(std::ofstream& outfile, TreeNode<BaseData>* current);
    tree(tree<BaseData>& t);
    tree<BaseData>& operator = (const tree<BaseData>& t);
    void insert(BaseData& item);
    void SearchAndDestroy(BaseData target);
    void writeTree(int);
    int fullTree() const;
    int emptyTree() const;
    TreeNode<BaseData>* root;
protected:   //helping functions
    void remove(TreeNode<BaseData>*& current);
    void inOrder(TreeNode<BaseData>*);
    void preOrder(TreeNode<BaseData>*);
    void postOrder(TreeNode<BaseData>*);
    void destroy(TreeNode<BaseData>* p);
    void copyTreeNode(TreeNode <BaseData>** into,
        TreeNode<BaseData>* from);
    void insertNode(TreeNode<BaseData>** into,
        BaseData& item);
    TreeNode <BaseData>* getnode(BaseData& item);

private:


};
#include "tree.cpp"
#endif