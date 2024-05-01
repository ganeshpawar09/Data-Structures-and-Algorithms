#include <iostream>
using namespace std;

class node
{
    int data;
    node *right;
    node *left;

public:
    friend class avl;
    node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

class avl
{
private:
    node *root;

public:
    avl()
    {
        root = NULL;
    }

    void insert(int value)
    {
        root = insert(value, root);
    }

    node *insert(int value, node *root)
    {
        if (root == NULL)
        {
            root = new node(value);
            return root;
        }
        else
        {
            if (value < root->data)
            {
                root->left = insert(value, root->left);
                if (balanceFactor(root) == 2)
                {
                    if (value < root->left->data)
                    {
                        root = ll(root);
                    }
                    else if (value > root->left->data)
                    {
                        root = lr(root);
                    }
                }
            }
            else if (value > root->data)
            {
                root->right = insert(value, root->right);

                if (balanceFactor(root) == -2)
                {
                    if (value > root->right->data)
                    {
                        root = rr(root);
                    }
                    else
                    {
                        root = rl(root);
                    }
                }
            }
            else
            {
                cout << "Duplicate value found" << endl;
            }
        }
        return root;
    }

    void delete_node(int value)
    {
        root = delete_node(value, root);
    }

    node *delete_node(int value, node *root)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            if (value < root->data)
            {
                root->left = delete_node(value, root->left);
                if (balanceFactor(root) == 2)
                {
                    if (value < root->left->data)
                    {
                        root = ll(root);
                    }
                    else if (value > root->left->data)
                    {
                        root = lr(root);
                    }
                }
            }
            else if (value > root->data)
            {
                root->right = delete_node(value, root->right);

                if (balanceFactor(root) == -2)
                {
                    if (value > root->right->data)
                    {
                        root = rr(root);
                    }
                    else
                    {
                        root = rl(root);
                    }
                }
            }
            else
            {
                if (root->right == NULL)
                {
                    node *temp = root->left;
                    delete root;
                    return temp;
                }
            }
        }
        return root;
    }

    node *rightRotation(node *a)
    {
        node *b = a->left;
        a->left = b->right;
        b->right = a;
        return b;
    }
    node *leftRotation(node *a)
    {
        node *b = a->right;
        a->right = b->left;
        b->left = a;
        return b;
    }

    node *ll(node *a)
    {
        return rightRotation(a);
    }
    node *rr(node *a)
    {
        return leftRotation(a);
    }
    node *lr(node *a)
    {
        a->left = leftRotation(a->left);
        return rightRotation(a);
    }
    node *rl(node *a)
    {

        a->right = rightRotation(a->right);
        return leftRotation(a);
    }

    void print()
    {
        cout << "Info of root ->";
        cout << root->data << "  ";
        cout << balanceFactor(root) << endl
             << endl;

        cout << "Inorder ->";
        inorder(root);
        cout << endl;

        cout << "Preorder ->";
        preorder(root);
        cout << endl;

        cout << "Postorder ->";
        postorder(root);
        cout << endl;
    }

private:
    int balanceFactor(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 0;
        }
        int left_ht = height(root->left);
        int right_ht = height(root->right);
        return left_ht - right_ht;
    }
    int height(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }

        int left_ht = height(root->left);
        int right_ht = height(root->right);

        return 1 + max(left_ht, right_ht);
    }

    void inorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << "  ";
        inorder(root->right);
    }
    void preorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << "  ";

        preorder(root->left);
        preorder(root->right);
    }
    void postorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "  ";
    }
};

int main()
{
    avl a;
    a.insert(10);
    a.insert(6);
    a.insert(8);
    a.print();
    return 0;
}