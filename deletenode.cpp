/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
Node *skipMdeleteN(Node *head, int M, int N);
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}
Node *skipMdeleteN(Node *head, int M, int N)
{
    int count1=1;
    int count2=1;
    if(head==NULL || head->next==NULL){
        return head;
    }
    if(M==0)
        return NULL;
    Node *temp1=head,*temp2=head;
    while(temp1&&temp2){
        for(count1=1;count1<M&&temp1!=NULL;count1++){
            temp1=temp1->next;
        }
        if (temp1 == NULL)  
            return head;
        temp2=temp1->next;
        for(count2=1;count2<=N&&temp2!=NULL;count2++){
            Node *temp=temp2;
            temp2=temp2->next;
            delete(temp);
        }
        temp1->next=temp2;
        temp1=temp2; 
    }
    return head;
    
}
    
