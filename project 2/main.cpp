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
void ListDelete(Point **, std::string);
void Print();
void Print_Points();
Point *Sort();

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
    Sort();
    Print();
    while (Start != nullptr){
        Print_Points();
        std::cout<<std::endl<<"delete :";
        std::cin>>x;
        ListDelete(&Start,x);
        Sort();
        Print();
    }
    delete(Start);
    return EXIT_SUCCESS;
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

Point *Sort()
{
    Point * list_end = NULL;
    while(list_end != Start)
    {
        Point *temp, *swap1;
        swap1 = Start;
        while( swap1->next != list_end )
        {
            if(swap1->Distances > swap1->next->Distances)
            {
                Point *swap2 = swap1->next;
                swap1->next = swap2->next;
                swap2->next = swap1;
                if(swap1 == Start)
                {
                    Start = swap2;
                    swap1 = swap2;
                }
                else
                {
                    swap1 = swap2;
                    temp->next = swap2;
                }
            }
            temp = swap1;
            swap1 = swap1->next;
        }
        list_end = swap1;
    }
    return  list_end;
}
void ListDelete(Point **List, std::string value)
{
    Point *current, *previous;
    previous = nullptr;
    for (current = *List;current != nullptr;previous = current, current = current->next) {
        if (current->name == value) {
            if (previous == nullptr) {
                *List = current->next;
            } else {
                previous->next = current->next;
            }
            cout << "Deleting : " << current->name << "\n";
            if (*List == nullptr){
                std::cout<<"No Points are in the list. The list is empty.."<<std::endl;
            }
            delete(current);
            return;
        } else{
            cout << "Value " << current->name << " does not match " << value << ".\n";
        }
    }
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