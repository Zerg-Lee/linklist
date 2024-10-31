SList::SList() {
    head = 0;
    tail = 0; // added later
}
SList::~SList() {
    if (!isEmpty())
        removeTail();
}
bool SList::isEmpty() {
    return head == 0; // O(1)
}
void SList::addToHead(int d) {
    head = new Node(d, head);        // added later
    if (tail == 0)
        tail = head;
}
void SList::addToTail(int d) {
    if (isEmpty())
        head = tail = new Node(d);
    else {
        tail->next = new Node(d);
        tail = tail->next;
    }
}
bool SList::isInList(int d) { // // O(N)
    Node* temp = head;
    while (temp != NULL && temp->data != d) {
        temp = temp->next;
    }
    return temp != 0;
}
// Assumes the list is not empty. 
// user should call isEmpty before using this.
int SList::removeHead() {
    int data = head->data;
    Node* temp = head;
    // head = head->next;
    // replace with the following condition
    if (head == tail)
        head = tail = 0;
    else
        head = head->next;
    delete temp;
    return data;
}
int SList::removeTail() {
    int data = tail->data;
    if (head == tail) {
        delete head;
        head = tail = NULL;
    }
    else { // O(N) to find previous node
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL; //0
    }

    return data;
}
void SList::removeNode(int d) {
    if (isEmpty())
        return;
    Node* prev, * cur;
    if (head->data == d) {
        cur = head;
        head = cur->next;
        if (tail == cur)
            tail = NULL;

        delete cur;
    }
    else {
        prev = head;
        cur = head->next;
        while (cur != 0 && cur->data != d) {
            prev = cur;
            cur = cur->next;
        }
        if (cur != 0) {
            prev->next = cur->next;
            if (cur == tail)
                tail = prev;
            //cout << " ......... last.." << endl;
            delete cur;
        }
    }
}
// Assumes the list is not empty. 
// user should call isEmpty before using this.
void SList::showList() {
    Node* temp = head;
    while (temp != 0) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int SList::count() {
    Node* temp = head;
    int countNodes = 0;
    while (temp != 0)
    {
        temp = temp->next;
        countNodes++;
    }
    return countNodes;
}
