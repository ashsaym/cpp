#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    std::string name;
    int  x,y;
    double Distances;
    struct Point *next;
};
struct Point* Start;
double calculateOrigin(struct Point*);
Point* Get_New_Point(std::string);
void Add_Point(std::string);
void removePoints(std::string);
void Order_print();
void Print();
void Print_Points();


int main()
{
    Start = nullptr;
    std::string x;
    std::cout<<"string describing obstacle (\"end\" for end of input):";
    std::cin>>x;

    while (x != "end"){
        Add_Point(x);
        std::cout<<"string describing obstacle (\"end\" for end of input):";
        std::cin>>x;
    }
    Order_print();
    while (Start != nullptr){
        Print_Points();
        std::cout<<std::endl<<"delete :";
        std::cin>>x;
        removePoints(x);
        Print();
    }
    delete(Start);
    return 0;
}


double calculateOrigin(struct Point *ptr){
    double fx, fy , dxy;
    fx = (*ptr).x - 0;
    fy = (*ptr).y - 0;
    (*ptr).Distances = sqrt(((fx*fx) + (fy*fy))* 1.0);
    dxy = (*ptr).Distances;
    return dxy;
};

Point* Get_New_Point(std::string N) {
    Point *newNode;
    newNode = new Point;
    newNode->name = N;

    std::cout<<endl<<"Enter X : ";
    std::cin>>newNode->x;

    std::cout<<"Y : ";
    std::cin>>newNode->y;
    newNode->Distances = calculateOrigin(newNode);
    std::cout<<std::endl;

    newNode->next = nullptr;
    return newNode;
}

void Add_Point(std::string N) {
    struct Point* newNode = Get_New_Point(N);
    if(Start == nullptr) {
        Start = newNode;
        return;
    }
    newNode->next = Start;
    Start = newNode;
}

void removePoints(std::string remValue) {
    Point* prev = Start;
    Point* current = Start->next;
    while(current != nullptr) {
        if(current->name == remValue) {
            break;
        }
        else {
            cout << "Value " << current->name << " does not match " << remValue << ".\n";
            prev = current;
            current = current->next;
        }
    }
    if(current == nullptr) {
        cout << "Can't remove value: no match found.\n";
    } else {
        cout << "Deleting: " << current << "\n";
        prev->next = current->next;
        delete current;
    }
}
void Order_print()
{
    Point* current = Start;
    Point *prev = nullptr, *next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    Start = prev;
    Print();
}
void Print() {
    struct Point* temp = Start;
    std::cout<<std::endl;
    while(temp != nullptr) {
        std::cout<<"obstacle "<<temp->name <<" : ("<<temp->x<<","<<temp->y<<")\tdistance : "<< temp->Distances<<"m"<<std::endl;
        temp = temp->next;
    }
}
void Print_Points() {
    struct Point* temp = Start;
    std::cout<<std::endl;
    std::cout<<"Delete Point : ";
    while(temp != nullptr) {
        std::cout<<temp->name<<" ";
        temp = temp->next;
    }
}