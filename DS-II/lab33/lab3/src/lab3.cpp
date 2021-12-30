//============================================================================
// Name        : lab3.cpp
// Author      : Rohit Saini
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
using namespace std;

class tbtnode{
    char data;
    bool rbit;
    bool lbit;
    tbtnode* right;
    tbtnode* left;
    friend class tbt;

    public:
    tbtnode(){
        lbit = 1;
        rbit = 1;
    }
};

class tbt{
    tbtnode *head;

    public:
    void create();
    void preorder();
    tbtnode *preordersucc(tbtnode *temp);
    tbtnode *inordersucc(tbtnode *temp);
    void inorder();
    tbt(){
        head = new tbtnode();
        head->rbit = 0;
        head->left = head;
        head->right = head;
    }
};

void tbt::create(){
    tbtnode *root = new tbtnode();
    cout<<"Enter root data :";
    cin>>root->data;
    head->lbit = 0;
    root->left = head;
    root->right = head;
    head->left = root;
    bool flag;
    tbtnode *temp;
    char ch;
    char choice;
    do{
        flag = 0;
        temp = root;
        cout<<"Enter node data :";
        tbtnode *curr = new tbtnode();
        cin>>curr->data;
        while(flag == 0){
            cout<<"To add to left press l and for right press r : ";
            cin>>ch;
            if(ch == 'l'){
                if(temp->lbit == 1){
                    curr->right = temp;
                    curr->left = temp->left;
                    temp->left = curr;
                    temp->lbit = 0;
                    flag = 1;
                }
                else{
                    temp = temp->left;
                }
            }
            if(ch == 'r'){
                if(temp->rbit == 1){
                    curr->left = temp;
                    curr->right = temp->right;
                    temp->right = curr;
                    temp->rbit = 0;
                    flag = 1;
                }
                else{
                    temp = temp->right;
                }
            }
        }
        cout<<"Do you want to add more nodes (y/n): ";
        cin>>choice;
    }while(choice == 'y');
}

void tbt::inorder(){
    tbtnode *temp = head;
    while(true){
        temp = inordersucc(temp);
        if(temp == head){
            break;
        }
        cout<<temp->data<<" ";
    }
}

tbtnode* tbt::inordersucc(tbtnode *temp){
    tbtnode *x = temp->right;
    if(temp->rbit == 0){
        while (x->lbit == 0)
        {
            x = x->left;
        }
    }
    return x;
}

void tbt::preorder(){
    tbtnode *temp = head->left;
    while(temp != head){
        cout<<temp->data<<" ";
        while (temp->lbit != 1)
        {
            temp = temp->left;
            cout<<temp->data<<" ";
        }
        while (temp->rbit == 1)
        {
            temp = temp->right;
        }
        temp = temp->right;

    }
}

int main(){
    tbt t;
	int choice;
	string key;
	do{
		printf("Menu:\n1.create\n2.inorder traversal\n3.preorder traversal\n4.Exit\n\nEnter the choice : ");
		cin>>choice;
		switch (choice){
		case 1:
			t.create();
			break;
		case 2:
			cout<<endl;
			t.inorder();
			cout<<endl;
			break;
		case 3:
			cout<<endl;
			t.preorder();
			cout<<endl;
			break;
		}
	}while(choice>0 && choice<4);

    return 0;
}
