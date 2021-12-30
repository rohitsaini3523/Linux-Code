{
    treenode *temp;
    queue q;
    if (root == NULL)
    {
        cout << "Binary search tree empty!";
    }
    else
    {
        int p = 1, r = 0;
        temp = root;
        q.insert(temp);
        while (!q.empty())
        {
            for (int i = 0; i < p; i++)
            {
                temp = q.remove();
                cout << temp->keyword << ":\t" << temp->meaning << "\t \t";
                if (temp->left != NULL)
                {
                    r++;
                }
                if (temp->right != NULL)
                {
                    q.insert(temp->right);
                    r++;
                }
            }
            cout << endl;
            p = r;
            r = 0;
        }
    }
}
r++;
                }
                if (temp->right != NULL)
                {
                    q.insert(temp->right);
                    r++;
                }
            }
            cout << endl;
            p = r;
            r = 0;
        }
    }
}