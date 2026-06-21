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
   

};

int main(){

    Linkedlist l;
    for(int i = 0; i < 20; i++){
        l.push_front(i);
    }

    return 0;
}