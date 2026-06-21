#include <iostream> 

using namespace std;

class Linkedlist {
    private :

        struct node { // like a class just more public used fro small data//
            int elem;
            node* next;

            node(int x){
                elem = x;
                next = nullptr;
                cout << "Constructed a node with " << elem <<endl;
            }

            ~node(){
                if(next != nullptr){
                delete next;
                }
                cout <<"Detroyed a node with " <<elem <<endl;
            }
        };
    
    public:

    node* head; //first node//

    Linkedlist(){
        head = nullptr;
    }

    ~Linkedlist(){
        if(head != nullptr){
                delete head;
                }
    }

    void push_front(int data){
        node* n = new node(data);
        
        if(head != nullptr){
            n->next = head; // or: n->next = head;//
        }
        head = n;
    }

    int pop_front(){
        if(head !=nullptr){
        int result = head->elem;
        node* old_head = head;
        head = head->next;

        old_head->next = nullptr;
        delete old_head;

        return result;
        }
        cout <<"Error: cannot pop from empty list" << endl;
        return -1;

    }
   

};

int main(){
    {
        Linkedlist l;
        for(int i = 0; i < 20; i++){
        l.push_front(i);
        }

        for(int i = 0; i < 20; i++){
            cout << l.pop_front()<< endl;
        }
    }

    cout << "end" <<endl;

    return 0;
}