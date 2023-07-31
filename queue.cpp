#include <iostream>
#include <queue>
 
using namespace std;

class node
{
    public:
    int data;
    node*next;
   // constructor
    node()
    {
        data=0;
        next=NULL;//-1
    }
};
class Queue
{
    public: 
    node*front;
    node*rear;
    Queue()
    {
       // initialize to two variables
        front=rear=NULL;//=-1
    }
    //here we check the queue is empty or no 
    bool isEmpty()
    {
        if(front==NULL && rear==NULL)
        return true;
        else
        return false;

    }
    //enqueue
    void Enqueue(int item)
    {
        //we added anew node in case the queue isempty or no
        node*newnode =new node();
        newnode->data=item;
        if(isEmpty())
        front = rear = newnode;
        else{
        rear->next=newnode;
        rear=newnode;
        }
    }
    //display
    void display()
    {
    if(isEmpty())
    {
        cout<<"queue is empty \n";
    }
    else
    {
        node*temp=front;
        while(temp !=NULL)
        {
            cout<<temp->data <<"\t";
            temp = temp->next;
        }
    }
        cout<<endl;
    }
    
   // counter
   int count()
   {
    int counter=0;
     node*temp=front;
        while(temp !=NULL)
        {
           counter++;
            temp = temp->next;
        }
        return counter;


   }
   //search
   bool isFound(int item)
   {
    cout<<"enter items:";
    cin>>item;
    cout<<endl;
    bool found=false;
         node*temp=front;
        while(temp !=NULL)
        {
            if(temp->data==item)
            found=true;
            temp=temp->next;
        }
        return found;
   } 
   //clear
   void clear(){
    while (!isEmpty()){
        dequeue();
    }
   }        
   // dequeue
   int dequeue()
   {
      int delvalue;

    if(isEmpty())
    {
        cout <<"the queue is empty \n";
    }
    else if(front==rear)//check 1 item in queue
    {
        delete front;
        front=rear=NULL;
    }
    else
    {
        node*delpointer =front; //additional pointer
        front=front->next;
        //
      
        delvalue=delpointer->data; //
        //
        delete delpointer;
    }
    return delvalue;

   }
    

};

 

 

int main()
{
    Queue ob1;
    int size;
    cout<<"please enter the number of queue items:";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        int item;
        cout<<"enter item enqueue: "<<i+1<<endl;
        cin>>item;
        ob1.Enqueue(item);

    }
    ob1.display();//1_step


    ob1.dequeue();
   cout<<"after dequeue \n";
    ob1.display();//step_2

     ob1.dequeue();
   cout<<"after dequeue \n";
    ob1.display();//step_2

    
    ob1.dequeue();
      cout<<"after dequeue \n";
       cout<<"clear all item\n";
        ob1.clear();
         cout<<"display after clear\n"; 
             ob1.display();      
    
 
 
    return 0;
}