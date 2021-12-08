#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node *next;
};

int power(int a, int b)
{
    int res = 1;
    while (b--)
    {
        res *= a;
    }
    return res;
}

void create(struct node *h)
{
    struct node *curr, *temp;
    temp = h;
    int a = 1;
    while (a == 1)
    {
        curr = (struct node *)malloc(sizeof(struct node));
        printf("Enter Coeff: ");
        scanf("%d", &(curr->coeff));
        printf("Enter Exp: ");
        scanf("%d", &(curr->exp));
        curr->next = h;
        temp->next = curr;
        temp = curr;
        printf("Enter another : (1/0) ");
        scanf("%d", &a);
    }
}

void display(struct node *h)
{
    struct node *curr;
    curr = h->next;
    printf("Polynomial is: ");
    while (curr->exp != -1)
    {
        printf("%dX%d + ", curr->coeff, curr->exp);
        curr = curr->next;
    }
    printf("0");
}

struct node *add(struct node *h1, struct node *h2)
{
    struct node *h3, *curr, *curr1, *curr2, *temp;
    h3 = (struct node *)malloc(sizeof(struct node));
    curr2 = h3;
    curr = h1->next;
    curr1 = h2->next;

    while (curr->exp != -1 || curr1->exp != -1)
    {
        if (curr->exp == curr1->exp)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->coeff = curr->coeff + curr1->coeff;
            temp->exp = curr->exp;
            temp->next = h3;
            curr2->next = temp;
            curr2 = temp;
            curr = curr->next;
            curr1 = curr1->next;
        }
        else if (curr->exp > curr1->exp)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->coeff = curr->coeff;
            temp->exp = curr->exp;
            temp->next = h3;
            curr2->next = temp;
            curr2 = temp;
            curr = curr->next;
        }
        else if (curr->exp < curr1->exp)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->coeff = curr1->coeff;
            temp->exp = curr1->exp;
            temp->next = h3;
            curr2->next = temp;
            curr2 = temp;
            curr1 = curr1->next;
        }
        if (curr->exp == -1)
        {
            curr2->next = curr1;
        }
        if (curr1->exp == -1)
        {
            curr2->next = curr;
        }
    }
    return (h3);
}
void evaluate(struct node *h)
{
    struct node *curr;
    curr = h->next;
    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    int result = 0;
    while (curr->exp != -1)
    {
        result = result + ((curr->coeff) * power(x, curr->exp));
        curr = curr->next;
    }
    printf("Result is : %d", result);
}

int main()
{
    struct node *head, *head1, *head2;
    head = (struct node *)malloc(sizeof(struct node));
    head1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));
    head->exp = -1;
    head1->exp = -1;
    head->coeff = 0;
    head1->coeff = 0;
    head2->exp = -1;
    head2->coeff = 0;
    int choice;
    while(choice!=5)
    {
        printf("\n==Menu==[For Addition]\n1.Polynomial 1\n2.Polynomial 2\n3.Add\n4.Evaluate\n5.Exit\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("First\n");
            create(head);
            display(head);
            break;
        case 2:
            printf("\nSecond\n");
            create(head1);
            display(head1);
            break;
        case 3:
            printf("Addition: \n");
            head2 = add(head, head1);
            display(head2);
            break;
        case 4:
            printf("\nEvaluation: \n");
            evaluate(head2);
            break;
        }  
    }
    return 0;
}