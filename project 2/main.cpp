#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
    std::string name;
    double x,y, Distances;
    Point *next;
};

Point* Start;
Point* Get_New_Point(std::string);
void Add_Point(std::string);
double round(double);
double calculateOrigin(Point*);
double calculateDistance(Point*, Point*);
Point* Sort(Point*);
string Nearest(Point*);
void Delete_Point(Point**, std::string);
void deleteList(Point**);
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
    if (Start != nullptr){
        Start = Sort(Start);
        while (Start != nullptr){
            Print();
            std::cout<<std::endl<<"delete (";
            Print_Points();
            std::cout<<" or \"all\") : ";
            std::cin>>x;
            if (x != "all"){
                Delete_Point(&Start,x);
            } else{
                deleteList(&Start);
            }
        }
    } else{
        Print();
        main();
    }
    delete(Start);
    std::cout<<"\nAll data has been deleted...";
    std::cout<<"Exiting the program...";
    return EXIT_SUCCESS;
}

double round(double var)
{
    double value = (int)(var * 100 + .5);
    return (double)value / 100;
}

double calculateOrigin(Point* ptr){
    double fx, fy , dxy;
    fx = pow(((ptr->x)-0), 2);
    fy = pow(((ptr->y)-0),2);
    dxy = round(sqrt(fx+fy));
    return dxy;
};


double calculateDistance(Point* p1 , Point* p2){
    double fx,fy,d;
    fx = pow(((p1->x)-(p2->x)), 2);
    fy = pow(((p1->y)-(p2->y)),2);
    d = round(sqrt(fx+fy));
    return d;
}

Point* Get_New_Point(std::string N) {
    Point* newNode;
    newNode = new Point;
    newNode->name = N;

    std::cout<<endl<<"x and y coordinate : ";
    std::cin>>newNode->x>>newNode->y;
    while(std::cin.fail())
    {
        std::cout << "Invalid coordinate.. Please enter valid coordinates.."<< std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<endl<<"x and y coordinate : ";
        std::cin>>newNode->x>>newNode->y;
    }
    newNode->Distances = calculateOrigin(newNode);
    std::cout<<std::endl;

    newNode->next = nullptr;
    return newNode;
}

void Add_Point(std::string N) {
    Point* newNode = Get_New_Point(N);
    if(Start == nullptr) {
        Start = newNode;
        return;
    }
    newNode->next = Start;
    Start = newNode;
}

Point* Sort(Point* Start)
{
    Point* list_end = nullptr;
    while(list_end != Start)
    {
        Point* temp;
        Point* swap;
        swap = Start;
        while( swap->next != list_end )
        {
            if(swap->Distances > swap->next->Distances)
            {
                Point* swap_next = swap->next;
                swap->next = swap_next->next;
                swap_next->next = swap;
                if(swap == Start)
                {
                    Start = swap_next;
                    swap = swap_next;
                }
                else
                {
                    swap = swap_next;
                    temp->next = swap_next;
                }
            }
            temp = swap;
            swap = swap->next;
        }
        list_end = swap;
    }
    return  list_end;
}

string Nearest(Point* Near){
    int min = INT_MAX;
    string sm;
    double d;
    Point* temp = Start;
    while (temp!= nullptr){
        if (temp == Near){
            temp = temp->next;
        } else{
            d = calculateDistance(Near,temp);
            if (min > d){
                min = d;
                sm = temp->name;
            }
            temp = temp->next;
        }
    }
    return  sm;
}

void Delete_Point(Point** List, std::string value)
{
    Point* current;
    Point* previous;
    previous = nullptr;
    for (current = *List;current != nullptr;previous = current, current = current->next) {
        if (current->name == value) {
            if (previous == nullptr) {
                *List = current->next;
            } else {
                previous->next = current->next;
            }
            cout << "Deleting : " << current->name << "\n";
            delete(current);
            if (*List == nullptr){
                std::cout<<"No Points are in the list. The list is empty.."<<std::endl;
                std::cout<<R"(Want to start again ? ("yes" / "no"))";
                string y;
                cin>>y;
                if (y == "yes"){
                    main();
                } else{
                    delete(Start);
                    EXIT_SUCCESS;
                }
            }
        } else{
            cout << "Value " << current->name << " does not match " << value << ".\n";
        }
    }
}
void deleteList(Point** Start)
{
    Point* current = *Start;
    Point* next;

    while (current != nullptr)
    {
        next = current->next;
        delete(current);
        current = next;
    }
    *Start = current;
    *Start = nullptr;
    std::cout<<"\n List has been deleted.";
}
void Print() {
    Point* temp = Start;
    std::cout<<std::endl;
    if (temp == nullptr){
        std::cout<<"List is empty"<<std::endl;
    }
    while(temp != nullptr) {
        std::cout<<"obstacle "<<temp->name <<" : ("<<temp->x<<","<<temp->y<<")"<<"\t"<<"distance : "<< temp->Distances<<"m"<<"\t"<<"nearest : "<<Nearest(temp)<<std::endl;
        temp = temp->next;
    }
}
void Print_Points() {
    Point* temp = Start;
    while(temp != nullptr) {
        std::cout<<temp->name<<",";
        temp = temp->next;
    }
}
