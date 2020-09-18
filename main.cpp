
#include <iostream>

using namespace std;
class Node
{
private:
    int data;
    Node *left;
    Node *right;
public:
    Node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;

    }
    void Set_data(int x)
    {
        data=x;
    }
    int Get_data()
    {
        return data;
    }
    void Set_left(Node *p)
    {
        left=p;
    }
    Node* Get_left()
    {
        return left;
    }
    void Display()
    {
        cout<<data<<endl;
    }
    void Set_right(Node *p)
    {
        right=p;
    }
    Node* Get_right()
    {
        return right;
    }
};
class BST
{
private:
    Node * root;
    Node * right;
    Node * left;
public:
    BST()
    {
        root=NULL;
        left=NULL;
        right=NULL;

    }
    void Add_node(int x)
    {
        Node*new_node=new Node(x);
        if(root==NULL)
        {
            root=new_node;
            return;
        }
        Node *temp=root;
        while(temp!=NULL)
        {
            if(new_node->Get_data()>temp->Get_data())
            {

                if(temp->Get_right()==NULL)
                {
                    temp->Set_right(new_node);
                    return;
                }
                temp=temp->Get_right();

            }
            else
            {

                if(temp->Get_left()==NULL)
                {
                    temp->Set_left(new_node);
                    return;
                }
                temp=temp->Get_left();
            }
        }

    }
    int Search_data(int x)
    {

        cout<<"Search result: ";
        if(root==NULL)
        {
            cout<<"Tree Is Empty ......."<<endl;
            return -1;
        }
        Node * temp=root;
        while(temp!=NULL)
        {
            if(x>temp->Get_data())
            {
                if(temp->Get_data()==x)
                {
                    cout <<"Search_Result: "<<x<<":found...."<<endl;
                    return 2;
                }
                temp=temp->Get_right();

            }
            else
            {

                if(temp->Get_data()==x)
                {
                    cout<<"Search_Result:"<<x<<" found..."<<endl;
                    return 2;
                }
                temp=temp->Get_left();
            }
        }

        cout<<"Search_Result: "<<x<<" :NOT FOUND!"<<endl<<endl;
        return -1;
    }
    void Delete_node(int x)
    {
        cout<<"Delete Result: ";
        if(Search_data(x)==-1)
        {
            cout<<"DATA NOT FOUND..!"<<endl;
            return;
        }
        if(root==NULL)
        {
            cout<<"NOTHING TO Delete......"<<endl;
            return;
        }
        Node * temp=root;
        if(root->Get_data()==x&&root->Get_left()==NULL&&root->Get_right()==NULL)
        {
            root=NULL;
            return;

        }
        if(root->Get_data()==x)
        {
            temp=root->Get_right();
            if(temp->Get_left()==NULL)
            {
                root->Set_data(temp->Get_data());
                root->Set_right(temp->Get_right());
                return;
            }
            while(temp->Get_left()!=NULL)
            {
                temp=temp->Get_left();
            }
            root->Set_data(temp->Get_data());
            temp->Set_left(NULL);
            return;
        }
        while(temp!=NULL)
        {

            if(x>temp->Get_data())
            {
                if(temp->Get_right()->Get_data()==x)

                {
                    if(temp->Get_right()->Get_right()==NULL)
                    {
                        temp->Set_right(NULL);

                        return;
                    }
                }

                if(temp->Get_right()->Get_data()==x)

                {

                    if(temp->Get_right()->Get_right()->Get_right()==NULL&&temp->Get_right()->Get_left()==NULL)
                    {
                        temp->Set_right(temp->Get_right()->Get_right());

                        return;
                    }
                }
                   if(temp->Get_right()->Get_data()==x)
                   {
                       Node *temp2=temp->Get_right()->Get_right();
                       if(temp2->Get_left()==NULL)
                       {
                           temp->Get_right()->Set_data(temp2->Get_data());
                           temp->Get_right()->Set_right(temp2->Get_right());
                           return;

                       }
                       while(temp2->Get_left()->Get_left()!=NULL)
                       {
                           temp2=temp2->Get_left();
                       }
                      temp->Get_right()->Set_data(temp2->Get_left()->Get_data());
                      temp2->Set_left(NULL);
                       return;

                   }
                temp=temp->Get_right();
            }
            else
            {

                if(temp->Get_left()->Get_data()==x)
                {
                    if(temp->Get_left()->Get_left()==NULL)
                    {
                        temp->Set_left(NULL);

                        return;
                    }
                }
                if(temp->Get_left()->Get_data()==x)
                {
                    if(temp->Get_left()->Get_left()->Get_left()==NULL&&temp->Get_left()-> Get_right()==NULL)
                    {
                        temp->Set_left(temp->Get_left()->Get_left());

                        return;
                    }
                }
                if(temp->Get_left()->Get_data()==x)
                {
                    Node * temp2=temp->Get_left()->Get_left();
                    if(temp2->Get_right()==NULL)
                       {
                           temp->Get_left()->Set_data(temp2->Get_data());
                           temp->Get_left()->Set_left(temp2->Get_left());

                           return;

                       }
                    while(temp2->Get_right()->Get_right()!=NULL)
                    {
                        temp2=temp2->Get_right();
                    }
                    temp->Get_left()->Set_data(temp2->Get_right()->Get_data());
                    temp2->Set_right(NULL);

                    return;
                }

                temp=temp->Get_left();
            }
        }
    }
    void Display()
    {  cout<<"Display_Result:"<<endl;
         if(root==NULL)
    {
        cout<<"Nothing To Display...!"<<endl;
        return;
    }
        cout<<"\t\t\t\tPRE_OREDER IS: "<<endl<<endl;
        cout<<"\t\t\t\t";
        Preorder(root);
        cout<<"  "<<endl<<endl;
        cout<<"\t\t\t\tPOST_OREDER IS: "<<endl<<endl;
        cout<<"\t\t\t\t";
        Postorder(root);
        cout<<"  "<<endl<<endl;
        cout<<"\t\t\t\tIN_OREDER IS: "<<endl<<endl;
        cout<<"\t\t\t\t";
        Inorder(root);
        cout<<"   "<<endl<<endl;
    }
    void Preorder(Node*R)
    {
        if(R==NULL)
        {
            return;
        }
        else
        {   cout<<"   "<<R->Get_data();
            Preorder(R->Get_left());
            Preorder(R->Get_right());
        }
    }
    void Postorder(Node*R)
    {
        if(R==NULL)
        {
            return;
        }
        else
        {
           Postorder(R->Get_left());
           Postorder(R->Get_right());
            cout<<"   "<<R->Get_data();

        }

    }
    void Inorder(Node*R)
    {
        int height_of_bst;
        if(R==NULL)
        {

            return;

        }
        else
        {
           Inorder(R->Get_left());
           cout<<"   "<<R->Get_data();
           Inorder(R->Get_right());

        }

    }

    void height()
    {
        cout<<"Height Result:   ";
        if(root==NULL)
        {
            cout<<"Height:-1"<<endl;
            return;
        }
        if(root->Get_left()==NULL&&root->Get_right()==NULL)
        {
            cout<<"Height:0"<<endl;
            return;

        }
        cout<<"Height:  "<<Height_of_bst(root)<<endl;
    }
    int Height_of_bst(Node *R)
    {

        if(R==NULL)
            return -1;
        else
            {
            int lh=Height_of_bst(R->Get_left());
            int rh=Height_of_bst(R->Get_right());
             lh++;
             rh++;
            if(lh>rh)
                return lh;
            else
                return rh;
            }
    }
};
int main()
{
    BST obj;
    int number;
    do
    {

        int data;
        cout<<"\t\t"<<"***********BINERY SEARCH TREE************"<<"\t\t\t"<<endl;
        cout<<"\t\t\t"<<"Press 1 for: Display"<<endl<<"\t\t\t"<<"Press 2 for: Add_node_in_Tree"<<endl;
        cout<<"\t\t\t"<< "Press 3 for: Search_Node"<<endl<<"\t\t\t"<<"Press 4 for: Deletion.."<<endl;
        cout<<"\t\t\t"<<"Press 5 for: Height Of BST.."<<endl;
              cout<<"\t\t\t"<<"Press 0 for :EXIT..."<<endl;
                cout<<"\t\t*********************************************\t\t\t"<<endl;

        cin>>number;
        switch (number)
        {
        case  1:
            obj.Display();
            break;
        case  2:
            cout <<"Enter data for Adding :"<<endl;
            cin>>data;
            obj.Add_node(data);
            break;
        case 3:
            cout <<"Enter data for Searching..:"<<endl;
            cin>>data;
            obj.Search_data(data);
            break;
        case 4:
            cout <<"Enter data for Deleting: "<<endl;
            cin>>data;
            obj.Delete_node(data);
            break;
        case 5:
            obj.height();
            break;
        }
    }
    while(number!=0);



    return 0;
}

