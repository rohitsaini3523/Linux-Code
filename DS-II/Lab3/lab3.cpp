#include <iostream>
using namespace std;

class tbtnode
{
    string data;
    bool rbit;
    bool lbit;
    tbtnode *right;
    tbtnode *left;
    friend class tbt;
    public:
        tbtnode();
};

tbtnode::tbtnode()
{
    lbit = 1;
    rbit = 1;
}

class tbt
{
    tbtnode *head;
    public:
        void create();
        void preorder();
        tbtnode *presuccr(tbtnode *temp);
        void inorder();
        tbtnode *insuccr(tbtnode *temp);
        tbt();
};
tbt::tbt()
{
    tbtnode *head = new tbtnode;
    head->rbit = 0;
    head->left = head;
    head->right = head;

}
void tbt::create()
{
    tbtnode *temp, *curr;
    tbtnode *root = new tbtnode;
    cout << "Enter Root Data:";
    cin >> root->data;
    head->lbit = 0;
    root->left = head;
    root->right = head;
    head->left = root;
    char ch;
    do
    {
        int flag = 0;
        temp = root;
        curr = new tbtnode;
        cout << "Data: ";
        cin >> curr->data;
        while(flag==0)
        {
            cout << "Left(l) / Right(r): ";
            cin >> ch;
            if(ch=='l')
            {
                if(temp->lbit==1)
                {
                    curr->right = temp;
                    curr->left = temp->left;
                    temp->left = curr;
                    temp->lbit = 0;
                    flag = 1;
                }
                else
                    temp = temp->left;
            }
            if(ch=='r')
            {
                if(temp->rbit==1)
                {
                    curr->left = temp;
                    curr->right = temp->right;
                    temp->right = curr;
                    temp->rbit = 0;
                    flag = 1;
                }
                else
                    temp = temp->right;
            }
        }
        cout << "Enter More (y/n): ";
        cin >> ch;
    } while (ch =='y'||ch=='Y');
}

void tbt::inorder()
{
    tbtnode *temp = head;
    while(1)
    {
        temp = insuccr(temp);
        if(temp==head)
            break;
        cout << "Data: " << temp->data;
    }
}

tbtnode *tbt::insuccr(tbtnode *temp)
{
    tbtnode *x;
    x = temp->right;
    if(temp->rbit==0)
    {
        while(x->lbit==0)
        {
            x = x->left;
        }
    }
    return x;
}

int main() 
{
    tbt T;
    T.create();
    T.inorder();
    return 0;
}