#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class Node {};
class LinkedList { virtual void tempFunc() {} };

template<class Val>
class NodeT1 : public Node{
    public:
        Val val;   
        NodeT1<Val>* next;

        NodeT1(Val val, NodeT1<Val>* next = NULL) {
            this->val = val;
            this->next = next;
        };
};

template<class Val>
class NodeT2 : public Node {
    public:
        Val val;
        NodeT2<Val>* next, prev;

        NodeT2(Val val, NodeT2<Val>* next = NULL, NodeT2<Val>* prev = NULL) {
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
};

class ListNode {
    public:
        LinkedList* list;
        ListNode* next;
     
        ListNode(LinkedList* list, ListNode* nextArg = NULL) {
            this->list = list;
            this->next = next;
        }
};

template<class Val>
class SinglyLinkList : public LinkedList {
    private:
        NodeT1<Val>* head;
        string identifier;
    public:

        SinglyLinkList(string identifier) {
            this->identifier = identifier;
        }

        NodeT1<Val>* getHead() {
            return head;
        }

        void insert(Val val) {
            if (head != NULL) {
                NodeT1<Val>* temp = head;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = new NodeT1<Val>(val);
            }
            else {
                head = new NodeT1<Val>(val);
            }
        }

        void tempFunc() {

        }
};

template<class Val>
class SinglyCircularLinkList : public LinkedList {
    private:
        NodeT1<Val>* tail;
        int len = 0;
    public:
        string identifier, type;

        SinglyCircularLinkList(string identifier, string type) {
            this->identifier = identifier;
            this->type = type;
        }

        NodeT1<Val>* getTail() {
            return tail;
        }

        void insert(Val val) {
            if (len == 0) {
                tail = new NodeT1<Val>(val);
                tail->next = tail;
                len++;
            } else {
                tail = tail->next = new NodeT1<Val>(val, tail->next);
                len++;
            }
        }

        void displayList() {
            NodeT1<Val>* temp = tail->next;
            cout << temp->val << " ";
            while (temp != tail) {            
                temp = temp->next;
                cout << temp->val << " ";
            }
            cout << endl;
        }

        void tempFunc() { }

};

vector<string> getObject(LinkedList* list) {
    vector<bool> checks;
    vector<vector<string>> correctOutputs;
    vector<string> outputStrs;

    checks.insert(checks.end(), !dynamic_cast<SinglyCircularLinkList<int>*>(list) != 1);
    correctOutputs.insert(correctOutputs.end(), vector<string> { "SinglyCircularLinkList", "int"});

    checks.insert(checks.end(), !dynamic_cast<SinglyCircularLinkList<float>*>(list) != 1);
    correctOutputs.insert(correctOutputs.end(), vector<string> { "SinglyCircularLinkList", "float"});
    
    checks.insert(checks.end(), !dynamic_cast<SinglyCircularLinkList<long>*>(list) != 1);
    correctOutputs.insert(correctOutputs.end(), vector<string> { "SinglyCircularLinkList", "long"});
    
    checks.insert(checks.end(), !dynamic_cast<SinglyCircularLinkList<char>*>(list) != 1);
    correctOutputs.insert(correctOutputs.end(), vector<string> { "SinglyCircularLinkList", "char"});

    for (int i = 0; i < checks.size(); i++) {
        if (checks.at(i)) {
            return correctOutputs.at(i);
        }
    }
}

class ListOfLists {
    private:
        ListNode* head = NULL;
    public:
        ListOfLists() {}

        void addList(LinkedList* list) {
            if (head != NULL) {
                ListNode* temp = head;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = new ListNode(list);
            }
            else {
                head = new ListNode(list);
            }
        }

        void displayListsIdentifier() {
            ListNode* temp = head;
            int i = 1;
            while (temp) {
                /*SinglyCircularLinkList<Val>* list = (SinglyCircularLinkList<Val>*)(temp->list);             

                cout << i << ") " << list->identifier << ", Items: ";
                list->displayList();

                i++;
                temp = temp->next;*/
            }
        }           
};

template<class Val>
LinkedList* getList(string identifier) {
    
    /*SinglyLinkList<Val>* list = new SinglyLinkList<Val>(identifier);
    list->insert(1);
    //list->insert(2);
    //list->insert(4);
    //list->insert(8);
    return list->getHead();
    */

    SinglyCircularLinkList<Val>* list = new SinglyCircularLinkList<Val>(identifier);
    list->insert(1.0001);
    list->insert(2.0001);
    return list;
};

void showMenu() {
    cout << "Linked List Menu:" << endl;
    cout << "1) Create New List" << endl;
    cout << "2) Display Existing Lists" << endl;
    cout << "3) Delete List" << endl;
    cout << "Enter (0) to exit. Choice: ";
};

string showNewListMenu() {
    cout << "New List Creation:" << endl;
    cout << "List Name : ";

    string listIdentifier;
    cin >> listIdentifier;
    cout << endl;

    cout << "Select Type," << endl;
    cout << "1) int" << endl;
    cout << "2) long" << endl;
    cout << "3) float" << endl;
    cout << "4) char" << endl;
    cout << "5) Back" << endl;
    cout << "Enter (0) to exit. Choice: ";

    return listIdentifier;
};

void showDisplayExistingListsMenu() {
    cout << "Existing Lists:" << endl;
    cout << "Select Option," << endl;
    cout << "1) Edit" << endl;
    cout << "2) Back" << endl;
    cout << "Enter (0) to exit. Choice: ";
};

void showEditListsMenu(string listIdentifier) {
    cout << "Edit \"" << listIdentifier << "\"" << endl;
    cout << "Select Option," << endl;
    cout << "1) Insert at Start" << endl;
    cout << "2) Insert at End" << endl;
    cout << "3) Insert at Index" << endl;
    cout << "4) Delete from Start" << endl;
    cout << "5) Delete from End" << endl;
    cout << "6) Delete at Index" << endl;
    cout << "7) Search for Element" << endl;
    cout << "8) Display List" << endl;
    cout << "9) Back" << endl;
    cout << "Enter (0) to exit. Choice: ";
};

int showDeletsListsMenu(vector<string> listsIdentifier) {
    cout << "Existing Lists:" << endl;
    cout << "Select which to delete," << endl;

    int i = 0;
    for (; i < listsIdentifier.size(); i++) {
        cout << (i + 1) << ") " << listsIdentifier[i] << endl;
    }

    cout << (i + 1) << ") Back" << endl;
    cout << "Enter (0) to exit. Choice: ";

    return (i + 1);
};

void createNewList() {
    int newListMenuTypeChoice;
    string listIdentifier = showNewListMenu();
    cin >> newListMenuTypeChoice;
    while (true) {
        switch (newListMenuTypeChoice) {
            case 0:
                system("exit");
                break;
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            default:
                system("clear");
                showMenu();
                break;
        }
    }
};

void displayExistingLists(ListOfLists* lists) {

};

void deleteList() {

};

int main() {
    ListOfLists* lists = new ListOfLists();

    /*showMenu();

    int mainMenuChoice;
    cin >> mainMenuChoice;

    while (true) {
        switch (mainMenuChoice) {
            case 0:
                system("exit");
                break;
            case 1:
                createNewList();
                break;
            case 2:
                displayExistingLists(lists);
                break;
            case 3:
                deleteList();
                break;
            default:
                system("clear");
                showMenu();
                break;
        }
    }*/

    
    SinglyCircularLinkList<long>* singlyCurcularList = new SinglyCircularLinkList<long>("First List", "long");
    singlyCurcularList->insert(1);
    singlyCurcularList->insert(10);
    singlyCurcularList->insert(100);

    SinglyLinkList<int>* singlyList = new SinglyLinkList<int>("Second List");
    singlyList->insert(2);

    vector<LinkedList*> customLists;
    customLists.insert(customLists.end(), singlyCurcularList);
    customLists.insert(customLists.end(), singlyList);
    
    LinkedList* testListParent = customLists.at(0);
    SinglyCircularLinkList<int>* testList = dynamic_cast<SinglyCircularLinkList<int>*>(testListParent);

    //cout << (!testList == 1 ? "true" : "false") << endl;
    vector<string> resObjData = getObject(testListParent);
    cout << "Class Name: " << resObjData.at(0) << endl << "Elem Type: " << resObjData.at(1) << endl;
    

    system("pause");
    return 0;
}