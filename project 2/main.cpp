#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    std::string name;
    int  x,y;
    double Distances;
    struct Point *next;
};
struct Point* head;

double calculateOrigin(struct Point *ptr){
    double fx, fy , dxy;
    fx = (*ptr).x - 0;
    fy = (*ptr).y - 0;
    (*ptr).Distances = sqrt(((fx*fx) + (fy*fy))* 1.0);
    dxy = (*ptr).Distances;
    return dxy;
};

Point* GetNewNode(std::string N) {
    Point *newNode;
    newNode = new Point;
    newNode->name = N;

    std::cout<<endl<<"Enter x: ";
    std::cin>>newNode->x;

    std::cout<<endl<<"Enter y: ";
    std::cin>>newNode->y;
    newNode->Distances = calculateOrigin(newNode);

    newNode->next = nullptr;
    return newNode;
}

void InsertAtHead(std::string N) {
    struct Point* newNode = GetNewNode(N);
    if(head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
void Print() {
    struct Point* temp = head;
    std::cout<<std::endl;
    std::cout<<"Point"<<"\t"<<"x"<<"\t"<<"y"<<"\t"<<"distance"<<std::endl;
    while(temp != nullptr) {
        std::cout<<temp->name<<"\t"<<temp->x<<"\t"<<temp->y<<"\t"<<temp->Distances<<std::endl;
        temp = temp->next;
    }
}

int main()
{
    head = nullptr;
    std::string x;
    std::cout<<"string describing obstacle (\"end\" for end of input):";
    std::cin>>x;

    while (x != "end"){
        InsertAtHead(x);
        std::cout<<"string describing obstacle (\"end\" for end of input):";
        std::cin>>x;
    }
    Print();



    return 0;
}