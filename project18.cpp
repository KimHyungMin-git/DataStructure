#include <iostream>
#include <string>
using namespace std;
class bst_node{
    public:
    string phone;
    string name;
    string birth;
    string major;
    bst_node *left, *right;
    void set_data(string p, string n, string b, string major);
};
void bst_node :: set_data(string p, string n, string b, string m){
    phone=p;
    name=n;
    birth=b;
    major=m;
}

class bst_tree{
    bst_node *root;
    int s_size;
    public:
    bst_tree();
    int size();
    bool empty();
    void insert_node(bst_node t);
    void show_inorder();
    bst_node search(string n);
};
bst_tree::bst_tree(){
    root=NULL;
    s_size=0;
}
int bst_tree::size(){
    return s_size;
}
bool bst_tree::empty(){
    if(s_size==0)
    return false;
    return true;
}
bst_node bst_tree :: search(string n){
    bst_node* p;
    p = root;
    if (root == NULL) {// 해당 node 없음 처리 예
    bst_node tmp;
    tmp.set_data("00000000000","None", "000000", "None");
    cout << "The name " << n << " does not exist.\n";
    return tmp;}
    while(1){
        if(p->name==n)
        return (*p);
        if(p->name<n){
            if(p->right==NULL){
                bst_node tmp;
    tmp.set_data("00000000000","None", "000000", "None");
    cout << "The name " << n << " does not exist.\n";
    return tmp;
            }
            else{
                p=p->right;
            }
            
        }
        else{
            if(p->left==NULL){
                bst_node tmp;
    tmp.set_data("00000000000","None", "000000", "None");
    cout << "The name " << n << " does not exist.\n";
    return tmp;
            }
            else{
                p=p->left;
            }
        }
    }
}
void inorder(bst_node *p){
    if(p==NULL)
    return ;
    inorder(p->left);
    cout<<p->name<<" : "<<p->major<<" : "<<p->phone<<" : "<<p->birth<<endl;
    inorder(p->right);
}
void bst_tree::show_inorder(){
    if(root==NULL)
    cout<<"Data is empty"<<endl;
    inorder(root);
}

void bst_tree::insert_node(bst_node t){
    bst_node *p;
    bst_node *temp;
    temp= new bst_node;
    (*temp)=t;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL){
        root=temp;
        s_size++;
        return;
    }
    p=root;
    while(1){
        if(p->name==temp->name){
            cout << "Insertion Failed : the name " << t.name << "  already exists." << endl;
            return;
        }
        if(p->name<temp->name){
            if(p->right==NULL){
                p->right=temp;
                s_size++;
                return;
            }
            else{
                p=p->right;
            }
        }
        else{
            if(p->name>temp->name){
                if(p->left==NULL){
                    s_size++;
                    p->left=temp;
                    return;
                }
                else{
                    p=p->left;
                }
            }
        }
    }
}
void insert_new(bst_tree &data){
    string n;
    string b;
    string p;
    string m;
    bst_node newuser;
    cout<<"Name? ";
    getline(cin,n);
    cout<<"Major? ";
    getline(cin,m);
    cout<<"Phone number? ";
    getline(cin,p);
    cout<<"Birth? ";
    getline(cin,b);
    newuser.set_data(p,n,b,m);
    data.insert_node(newuser);
}
void showall(bst_tree &data){
    int d=data.size();
    cout<<"Here are "<<d<<" data!"<<endl;
    data.show_inorder();
}
void serach_node(bst_tree &data){
    string name;
    bst_node p;
    cout<<"Enter a name of user ";
    cin>>name;
    p=data.search(name);
    if(p.name=="None"){
    return;}
    cout<<p.name<<" : "<<p.major<<" : "<<p.phone<<" : "<<p.birth<<endl;
}
int main() 
{   bst_node temp;
    bst_tree dataset;
    int menu;
    temp.set_data("010-1234-5678", "Kim", "000101","Management");
        dataset.insert_node(temp);
        temp.set_data("010-3456-1234", "Park", "990202","MechanicalEngineering");
        dataset.insert_node(temp);
        temp.set_data("010-6645-5311", "Shim", "971205","Biotechnology");
        dataset.insert_node(temp);
    while(1){
        cout<<"1. insert new user"<<endl;
        cout<<"2. search user"<<endl;
        cout<<"3. show all user"<<endl;
        cout<<"4. exit"<<endl;
        cin>>menu;
        cin.ignore();
        switch(menu){
            case 1: 
            insert_new(dataset);
                break;
            case 2: 
                serach_node(dataset);
                break;
            case 3: 
                showall(dataset);
                break;
            case 4:
            default:
                cout<<"byebye";
                return 0;
        }
    }
        return 0;

}
