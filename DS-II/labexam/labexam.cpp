// Q2. Implement threaded binary tree and perform inorder traversal
// Name: Rohit Saini
// Roll no: 06
// Panel: A1
// Erp: 1032200897
#include <iostream>
using namespace std;

//Node 
class tnode
{
    string s;
    bool rbit;
    bool lbit;
    tnode *right;
    //1 - threaded pointer
    //0 - pointer
    //right- inorder successor
    tnode *left;
    // left - inorder previous
    friend class threadbt;
public:
    tnode()
    {
        lbit = 1;
        rbit = 1;
    }
};
//threaded binary tree
class threadbt
{
    tnode *head;
public:
    void create();
    tnode *inordersuccessor(tnode *temp);
    void inorder();
    //For memory Allocation
    threadbt()
    {
        head = new tnode();
        head->rbit = 0;
        head->left = head;
        head->right = head;
    }
};
void threadbt::create()
{
    tnode *root = new tnode;
    cout << "Enter root Data: ";
    cin >> root->s;
    head->lbit = 0;
    root->right = head;
    root->left = head;
    head->left = root;
    bool flag;
    tnode *temp;
    char ch, which_child;
    do
    {
        flag = 0;
        temp = root;
        cout << "Enter Node Data: ";
        tnode *curr = new tnode();
        cin >> curr->s;
        while(flag==0)
        {
            cout << "To add to left press (l) and for right (r): ";
            cin >> which_child;
            if(which_child == 'l')
            {
                if(temp->lbit == 1)
                {
                    curr->right = temp;
                    curr->left = temp->left;
                    temp->left = curr;
                    temp->lbit = 0;
                    flag = 1;
                }
                else
                {
                    temp = temp->left;
                }
            }
            if(which_child == 'r')
            {
                if(temp->rbit == 1)
                {
                    curr->left = temp;
                    curr->right = temp->right;
                    temp->right = curr;
                    temp->rbit = 0;
                    flag = 1;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
        cout << "Do you want to add more nodes (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

tnode *threadbt::inordersuccessor(tnode *temp)
{
    tnode *temp1 = temp->right;
    if(temp->rbit == 0)
    {
        while(temp1->lbit == 0)
        {
            temp1 = temp1->left;
        }
    }
    return temp1;
}

void threadbt::inorder()
{
    tnode *temp = head;
    while(true)
    {
        temp = inordersuccessor(temp);
        if(temp == head)
        {
            break;
        }
        cout << temp->s << " ";
    }
    cout << endl;
}


int main()
{
    threadbt tbt;
    int ch;
    do
    {
        cout << "\n1.Create\n2.Inorder\nChoice:";
        cin >> ch;
        switch(ch)
        {
            case 1:
                tbt.create();
                break;
            case 2:
                tbt.inorder();
                break;
        }
    } while (ch > 0 && ch < 3);
    return 0;
}