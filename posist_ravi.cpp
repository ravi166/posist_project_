#include<bits/stdc++.h>
using namespace std;

vector<int> first_id;
class Date
{
protected:
  string date,time;
  public:
   void getdate()
    {
    cout<< "Enter date : ";
    cin>>date;
     cout<< "\nEnter time : ";
    cin>>time;
    }
};
class Info
{
  protected:
  string name;
  string add,phone,mobile,pass;
  float value;
  public :
  void addinfo()
  {
     cout<<"Enter the name of owner : ";
     cin>>name;
      cout<<"\nEnter the address of owner : ";
      cin>>add;
       cout<<"\nEnter the mobile number of owner : ";
       cin>>mobile;
        cout<<"\nEnter the phone Number of owner : ";
        cin>>phone;
         cout<<"\nEnter the value of this node : ";
         cin>>value;
         cout<<"\nEnter the password of owner : ";
      cin>>pass;
  }
  bool verify(string s)
  {

    if(s==pass)
        return true;
    return false;
  }
};
class Node
{
   Date Timestamp;
   Info Data;
   int node_number;
   int node_id;
   Node* refer_id;
   Node *refer_child_id;
   list<int> child_id;
   public :
   void create_node(int c,Node *root)
   {
      Timestamp.getdate();
      cout<<"\nenter the information of node owner : \n";
      Data.addinfo();
      node_id=c;
      if(root==NULL)
      {
         node_number=c;
         refer_id=NULL;
         refer_child_id=NULL;
         first_id.push_back(c);
      }
      else
      {if(root->refer_id==NULL)
         refer_id=root;
         else
         refer_id=root->refer_id;
         refer_child_id=root;
         (root->child_id).push_back(c);
      }
   }
};
int  coun=0;
map<int,Node*> record;
int main()
{
   cout<<" \nEnter 1 to create first node : ";
    cout<<" \nEnter 2 to create set of  first node : ";
     cout<<" \nEnter 3 to insert node in any set  : ";
      cout<<" \nEnter 4 to encrypt password first node : ";
       cout<<" \nEnter 5 to verify ownwer : ";
       int choice;
       cin>>choice;
       switch(choice)
       {
          case 1:
                  coun++;
                  Node *ptr=(Node *)malloc(sizeof(Node));
                  ptr->create_node(coun,NULL);
                  record[coun]=ptr;
                  break;
         case 2:
               cout<<"\n enter of first node u want to create : ";
               int x;
               cin>>x;
               while(x--)
               {
                coun++;
                  Node *ptr=(Node *)malloc(sizeof(Node));
                  ptr->create_node(coun,NULL);
                  record[coun]=ptr;
               }
               break;
         case 3 :
                  cout<<"\nEnter the id of node in witch u want to add new node : ";
                  int id;
                  cin>>id;
                 coun++;
                  Node *ptr=(Node *)malloc(sizeof(Node));
                  ptr->create_node(coun,record[id]);
                  record[coun]=ptr;
                  break;
         case 4:
            break;
         case 5 :
            cout<<"\n Enter id of node : ";
            int id;
            string s;
            cout<<"\nEnter password : ";
            cin>>s
            cin>>id;
            if(record[id]==0)
                cout<<"Owner does not exist \n";
            else
            {
                if((record[id]->Data).verify(s))
                    cout<<"\nOwner verified\n";
                else
                    cout<<"\nWrong password";
            }
            break;
         default :
            break;
       }
       return 0;
}
