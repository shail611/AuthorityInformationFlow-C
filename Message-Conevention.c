/*
This is the Comprehensive assignment
Shail Shah 

The data structure used in the program is linked-tree-list.

There is a linked list which in-turn stores the address of root nodes for trees.
*/
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
struct node{            // Creating a structure with suitable parameters.
    int count;
    struct node *left,*right,*next,*link;   // left and right used for tree, and next and link for linked list
    char name[100];
};
struct node *start=NULL;        // start for all trees root nodes.
struct node *newData=NULL;      // a variable to create new nodes.
struct node *almighty=start;    // a variable to traverse linked list.
struct node *MegaStart=NULL;    // a variable that stores starting address of linked list
struct node *justTemp=NULL;     // just a temporary variable

int MegaCount = 0;
void insert(struct node *root);
void display_post(struct node *root);

void create()                   // creates a new node
{
    newData=(struct node*)malloc(sizeof(struct node));  // assigning dynamic memory
    gets(newData->name);
    newData->left=NULL;
    newData->count = 1;
    newData->right=NULL;
}
void getInfo(char a[])      // Get info about all departments from the user
{
    int in;
    almighty=(struct node*)malloc(sizeof(struct node)); // creating a node in the linked list
    if(MegaCount==0)                                    // initializing MegaStart with starting point of the linked list
    {
        MegaStart = almighty;
    }
    else
        justTemp->next = almighty;
    MegaCount++;
    strcpy(almighty->name,a);                          // assigning name to list
    almighty->next = NULL;
    printf("Enter number of %s:\n",almighty->name);
    scanf("%d",&in);
    almighty->count = in;                               // assigning count to list
    if(in>0)
    {
        char asdf[1];
        printf("Enter name of %s %d: ",almighty->name,1);
        gets(asdf);
        create();
        insert(start);
    }
    for(int i=1;i<in;i++)                           // Getting info about all members of particular department
        {
            printf("Enter name of %s %d: ",almighty->name,i+1);
            create();                               // creating new node
            insert(start);                          // storing in a tree
        }
        justTemp = almighty;

    almighty->link = start;                 // assigning root node of tree to the linked list via link

     start = NULL;
     almighty = almighty->next;
}

void view()                 // function to view all departments and is members
{
    almighty = MegaStart;
    while(almighty!=NULL)
    {
        printf("\nNumber of %s are %d\n",almighty->name,almighty->count);
        display_post(almighty->link);
        almighty = almighty->next;
    }
}
void display_info(struct node *root,char info[])        // function to display message entered by user to all departments
{
    if(root==NULL) return;
    display_info(root->left,info);
    for(int i=0;i<root->count;i++)
        printf("Respected %s,\n %s\n\n",root->name,info);
    display_info(root->right,info);

}
void convey()                               // function to input message from user
{
    printf("Enter info to convey: ");
    char info[300];
    gets(info);
    gets(info);
    almighty = MegaStart;
    printf("\nInfo going to %ss\n\n",almighty->name);
    display_info(almighty->link,info);

    while(1)
    {
        int n;
        if(almighty->next==NULL) break;
        printf("Enter 1 to pass on to %s or 0 to wait...\n",almighty->next->name);  // taking permission to allow forwarding of message
        scanf("%d",&n);
        if(n==1)
        {
            almighty = almighty->next;
            printf("\nInfo going to %ss\n\n",almighty->name);
            display_info(almighty->link,info);
        }
    }
}
void member()                   // function to add a new member to any department
{
    int n,p=1;
    printf("\nWhich department to add a new member?: \n");
    almighty = MegaStart;
    while(almighty!=NULL)       // show all departments
    {
        printf("%d. %s\n",p,almighty->name);
        p++;
        almighty = almighty->next;
    }
    scanf("%d",&n);
    while(n>=p||n<1)        // get particular department
    {
        printf("\nEnter again:");
        scanf("%d",&n);
    }
    almighty = MegaStart;
    for(int i=1;i<n;i++)
        almighty = almighty->next;
    printf("\nAdding a member in %s department\n",almighty->name);  // inputting name from user for new member
    printf("\nEnter name: ");
    char tt[1];
    gets(tt);
    create();
    insert(almighty->link);     // inserting in the tree regarding particular department
    insert(almighty->link);
    almighty->count++;

}
int main()      // Main Function
{
    char a[] = "Director";
    char b[] = "H.O.D";
    char c[] = "Faculty Adviser";
    char da[] = "Student";
    printf("Welcome to the Management of the Institution.\nHere all the important messages are provided as per priorities.\nPriorities are:\n1.%s\n2.%s\n3.%s\n4.%s\n\n",a,b,c,da);
    printf("\n");
    getInfo(a);     // Getting info about all departments.
    printf("\n");
    getInfo(b);
    printf("\n");
    getInfo(c);
    printf("\n");
    getInfo(da);
    printf("\n");
    while(1)
    {int dir;
        printf("\nEnter:\n1. To convey a message.\n2. To add another member\n3. View all departments\n0. exit\n");  // user friendly manual
        scanf("%d",&dir);
        switch(dir)
        {
            case 3:view();break;
            case 2:member();break;
            case 1:convey();break;
            case 0:printf("Thank you for using this program");exit(0);
            default:printf("Enter valid id...");
        }
    }

    return 0;
}

void insert(struct node *root)              // function to sort all names from one department in a tree and giving them appropriate count
{

    if(start==NULL){
        start=newData;
        start->next = NULL;
    }

    else if(strcmp(newData->name,root->name)<0&&root->left!=NULL)
    {
        insert(root->left);
    }

    else if(strcmp(newData->name,root->name)>0&&root->right!=NULL)
    {
        insert(root->right);
    }
    else if(strcmp(newData->name , root->name)<0&&root->left==NULL)
    {
        root->left = newData;
        root->left->count = 1;
    }

    else if(strcmp(newData->name , root->name)>0&&root->right==NULL)
    {
        root->right = newData;
        root->right->count = 1;
    }
    else if(strcmp(newData->name , root->name)==0)
    {
        root->count ++;
    }
}

void display_post(struct node *root)            // function to display all contents of a tree in ascending order
{
    if(root==NULL) return;
    display_post(root->left);
    printf("%s \n",root->name);
    display_post(root->right);

}
