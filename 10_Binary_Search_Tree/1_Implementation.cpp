#include <iostream>
using namespace std;

class node
{
private:
    int data;
    node *left;
    node *right;

public:
    friend class bst;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class bst
{
private:
    node *root;

public:
    bst(int data)
    {
        root = new node(data);
    }
    void insert_node(int data)
    {
        root = insert_node(root, data);
    }
    node *insert_node(node *root, int data)
    {
        if (root == NULL)
        {
            root = new node(data);
            return root;
        }
        else if (root->data > data)
        {
            root->left = insert_node(root->left, data);
        }
        else
        {
            root->right = insert_node(root->right, data);
        }
    }

    void inorder()
    {
        inorder(root);
    }
    void inorder(node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    bool search(node *root, int x)
    {
        if (root == NULL)
            return false;
        else if (root->data == x)
            return true;
        else if (root->data > x)
            search(root->left, x);
        else
            search(root->right, x);
    }
    void delete_node(int data)
    {
        delete_node(root, data);
    }
    node *delete_node(node *root, int data)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (root->data == data)
        {
            if (root->right == NULL)
            {
                return root->left;
            }
            else if (root->right != NULL)
            {
                int inorder_node = find_inorder_node(root->right);
                root->data = inorder_node;
                root->right = delete_node(root->right, inorder_node);
            }
        }
        else if (root->data > data)
        {
            root->left = delete_node(root->left, data);
        }
        else if (root->data < data)
        {
            root->right = delete_node(root->right, data);
        }
    }

    int find_inorder_node(node *root)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root->data;
    }
};

int main()
{
    bst a(10);
    a.insert_node(8);
    a.insert_node(6);
    a.insert_node(9);

    a.inorder();
    cout << endl;
    a.delete_node(8);
    a.inorder();

    return 0;
}