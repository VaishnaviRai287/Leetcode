class Node{
    public:
    string data;
    Node* next;
    Node* back;
    Node() : data(""), next(nullptr), back(nullptr) {};
    Node(string x) : data(x), next(nullptr), back(nullptr) {};
    Node(string x, Node* next, Node* back) : data(x), next(next), back(back){};
};
class BrowserHistory {
public:
    Node* current;
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
         Node* temp = current->next;
        current->next = nullptr; // detach immediately
        while (temp) {
            Node* nxt = temp->next;
            delete temp;
            temp = nxt;
        }

        Node* newNode = new Node(url);
        current->next = newNode;
        newNode->back = current;
        current = newNode;
    }
    
    string back(int steps) {
        while(steps){
            if(current->back) current = current-> back;
            else break;
            steps--;
        }
        return current->data;
    }
    
    string forward(int steps) {
        while(steps){
            if(current->next) current = current-> next;
            else break;
            steps--;
        }
        return current->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */