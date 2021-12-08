#include <iostream>
using namespace std;

class tnode
{

    int data;
    tnode *right;
    tnode *left;
    friend class tree;
};

class tree
{

public:
    tnode *root;
    tree()
    {
        root = NULL;
    }
    void create_r();
    void create_t();
    void inorder_r()
    {
        inorder_r(root);
    }
    void inorder_r(tnode *temp)
    {
        if (temp != NULL)
        {
            inorder_r(temp->left);
            cout << temp->data << " ";
            inorder_r(temp->right);
        }
    }
    void preorder()
    {
        preorder(root);
    }
    void preorder(tnode *temp)
    {
        if (temp != NULL)
        {
            cout << temp->data << " ";
            preorder(temp->left);
            preorder(temp->right);
        }
    }
    void postorder()
    {
        postorder(root);
    }
    void postorder(tnode *temp)
    {
        if (temp != NULL)
        {
            preorder(temp->left);
            preorder(temp->right);
            cout << temp->data << " ";
        }
    }
};

void tree ::create_t()
{

    if (root == NULL)
    {
        cout << "Enter the data for root node : ";
        root = new tnode;
        cin >> root->data;
        root->right = NULL;
        root->left = NULL;
    }
    int c = 1;
    do
    {
        bool flag = 0;
        tnode *curr = new tnode;
        tnode *temp = root;
        int d;
        cout << "Enter data : ";
        cin >> d;
        curr->data = d;
        char ch;

        while (flag == 0)
        {
            cout << "Enter choice l-left/r-right : ";
            cin >> ch;
            if (ch == 'l')
            {
                if (temp->left == NULL)
                {
                    temp->left = curr;
                    flag = 1;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = curr;
                    flag = 1;
                }
                temp = temp->right;
            }
        }
        cout << "do you want to continue 0/1 : ";
        cin >> c;
    } while (c == 1);
}

int main()
{
    tree bt;
    bool c = 1;
    int ch = 0;
    while (c)
    {
        cout << "1.Create"
             << "\n"
             << "2.Inorder Traverasal"
             << "\n"
             << "3.Preorder Traversal \n4.Postorder Traversal" << endl;
        cout << "Enter your choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            bt.create_t();
            break;
        case 2:
            bt.inorder_r();
            cout << "\n"
                 << endl;
            break;
        case 3:
            bt.preorder();
            cout << "\n"
                 << endl;
            break;
        case 4:
            bt.postorder();
            cout << "\n"
                 << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        cout << "Do you want to perform another function 0/1: ";
        cin >> c;
    }
    return 0;
}