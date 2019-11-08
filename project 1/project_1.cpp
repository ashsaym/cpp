#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <limits>
#define N 100
using namespace std;
struct TeamData
{
    string Name;
    int Points;
    int Matches;
};

void Menu(TeamData*,int);
void MenuItems();
void Switcher(TeamData*, int , int);
void initial_Teams(TeamData*,int);
void Show_Rank(TeamData*,int);
void initial_Rank(TeamData*,int);
void Game_Table(TeamData*,int);
void Choosing_Team(TeamData*,int);
void ResetData(TeamData*,int);
void pointReseter(TeamData*, int);
void Indexer(TeamData*, int);
void SortPoints(TeamData*, int);
int TeamSelect(TeamData*, int);
void Point_Calculator(TeamData*, int , int , int);



int main(void)
{
    unsigned int Number_of_Teams;
    TeamData Team[N];
    std::cout<<"Number of Teams : "<< "\t";
    std::cin>>Number_of_Teams;
    while(std::cin.fail())
    {
        std::cout << "Invalid Entry.. Enter 1 - "<<N << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Number of Teams : "<< "\t";
        std::cin>>Number_of_Teams;
    }

    if (Number_of_Teams>0 && Number_of_Teams<N){
        std::cout<<"Number of Teams are : "<< "\t" <<Number_of_Teams<<endl;
        pointReseter(Team, Number_of_Teams);
        Menu(Team,Number_of_Teams);

    }
    else{
        std::cout<<"Please enter a valid number of teams ...\t"<<endl;
        main();
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}



void Menu(TeamData Team[] , int Number_of_Teams){
    MenuItems();
    std::cout<<"Please choose an option : "<<endl;
    int Option;
    std::cin >> Option;
    while(std::cin.fail())
    {
        std::cout << "Invalid Entry.. Enter 0,1,2,3 or 9 - "<< std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Please choose an option : "<<endl;
        std::cin >> Option;
    }
    Switcher(Team,Number_of_Teams,Option);
}



void MenuItems(){
    std::cout<<"Welcome to Game table \n";
    std::cout<<"Option 1: Enter Team Name \n";
    std::cout<<"Option 2: Show Ranking \n";
    std::cout<<"Option 3: Add Result of a Match \n";
    std::cout<<"Option 9: Reset Points \n";
    std::cout<<"Option 0: Quit \n";
}



void Switcher( TeamData Team[] ,int Number_of_Teams , int Option){
    switch(Option) {
        case 1 :
            initial_Teams(Team,Number_of_Teams);
            system("PAUSE");
            system("CLS");
            Menu(Team,Number_of_Teams);
            break;
        case 2 :
            Show_Rank(Team,Number_of_Teams);
            system("PAUSE");
            system("CLS");
            Menu(Team,Number_of_Teams);
            break;
        case 3 :
            Choosing_Team(Team,Number_of_Teams);
            system("PAUSE");
            system("CLS");
            Menu(Team,Number_of_Teams);
            break;
        case 9 :
            ResetData(Team,Number_of_Teams);
            system("PAUSE");
            system("CLS");
            Menu(Team,Number_of_Teams);
            break;
        case 0 :
            std::cout<<"Thank you ... Have a nice Day !!!";
            std::exit(EXIT_SUCCESS);
        default :
            std::cout<<"Option you selected is not valid.. Choose a valid one..."<<endl;
            Menu(Team,Number_of_Teams);
            break;
    }
}



void initial_Teams(TeamData Team[], int Number_of_Teams) {
    std::cout<<"Enter team Names "<<endl;
    std::cout<<"=============="<<endl;
    for (int i = 0; i < Number_of_Teams; i++) {
        std::cout << "Team " << i+1<<endl;
        std::cin >> Team[i].Name;
    }
    pointReseter(Team, Number_of_Teams);
    initial_Rank(Team,Number_of_Teams);
}



void initial_Rank(TeamData Team[],int Number_of_Teams){
    std::cout<<"initial ranking"<<endl;
    std::cout<<"=============="<<endl;
    Game_Table(Team,Number_of_Teams);
}



void Show_Rank(TeamData Team[],int Number_of_Teams){
    std::cout<<"Points ranking"<<endl;
    std::cout<<"=============="<<endl;
    Game_Table(Team,Number_of_Teams);
}



void Game_Table(TeamData Team[],int Number_of_Teams){
    SortPoints(Team,Number_of_Teams);
    std::cout << "Nr." << "\t";
    std::cout << "Matches" << "\t";
    std::cout << "Points\t";
    std::cout << "Name"<<std::endl;
    for (int j = 0; j < Number_of_Teams; j++) {
        std::cout <<j+1 <<"\t";
        std::cout << Team[j].Matches<< "\t";
        std::cout <<Team[j].Points<< "\t";
        std::cout <<Team[j].Name<<std::endl;
    }
}



void Choosing_Team(TeamData Team[],int Number_of_Teams){
    std::cout<<"Team List"<<endl;
    std::cout<<"=============="<<endl;

    int TeamNr_1,TeamNr_2 = 0;
    Indexer(Team,Number_of_Teams);
    std::cout<<"Select Team 1 :"<<endl;
    std::cin>>TeamNr_1;
    while(std::cin.fail())
    {
        std::cout << "Invalid Entry.. Enter 1 - "<<Number_of_Teams << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Select Team 1 :"<<endl;
        std::cin>>TeamNr_1;
    }

    Indexer(Team,Number_of_Teams);
    std::cout<<"Select Team 2 :"<<endl;
    std::cin>>TeamNr_2;
    while(std::cin.fail())
    {
        std::cout << "Invalid Entry.. Enter 1 - "<<Number_of_Teams << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Select Team 2 :"<<endl;
        std::cin>>TeamNr_2;
    }

    int Selected_1 = TeamSelect(Team,TeamNr_1);
    int Selected_2 = TeamSelect(Team,TeamNr_2);

    if (Selected_1!= Selected_2 && Selected_1<=Number_of_Teams && Selected_2 <= Number_of_Teams && Selected_1+1!= 0 && Selected_2+1!=0 ){
        int Selected_points_1 = Team[Selected_1].Points;
        int Selected_points_2 = Team[Selected_2].Points;

        std::cout<<Team[Selected_1].Name<<"\t vs \t"<<Team[Selected_2].Name<<endl;

        Point_Calculator(Team , Number_of_Teams, Selected_1 , Selected_points_1);
        Point_Calculator(Team , Number_of_Teams, Selected_2 , Selected_points_2);

        SortPoints(Team,Number_of_Teams);
        Show_Rank(Team,Number_of_Teams);
    } else{
        std::cout<<"*** sorry teams need to be different and Have to choose from the list ***"<<endl;
        Choosing_Team(Team,Number_of_Teams);
    }



}



void Indexer(TeamData Team[], int Number_of_Teams){
    for (int i = 0; i < Number_of_Teams; i++) {
        std::cout<<i+1<<"\t";
        std::cout<<Team[i].Name<<endl;
    }
}



int TeamSelect(TeamData Team[], int TeamNr){
    int teamSelect;
    teamSelect = TeamNr - 1;
    std::cout<< "you choose: \t" <<Team[teamSelect].Name<<endl;
    return teamSelect;
}



void Point_Calculator(TeamData Team[], int Number_of_Teams, int Selected , int Selected_points){
    int new_points;
    std::cout<<"Enter Points for "<<Team[Selected].Name <<":"<<endl;
    std::cin>> new_points;
    Team[Selected].Points= new_points + Selected_points;
    Team[Selected].Matches = Team[Selected].Matches +1;
}



void SortPoints(TeamData Team[], int Number_of_Teams){
    for (int i = 0;i < Number_of_Teams; i++ ){
        {
            for(int j= i + 1; j < Number_of_Teams; j++)
            {
                if(Team[i].Points<Team[j].Points)
                {
                    TeamData temp = Team[i];
                    Team[i]=Team[j];
                    Team[j]=temp;
                }
            }
        }
    }
}



void ResetData(TeamData Team[], int Number_of_Teams) {
    std::cout<<endl;
    std::cout<<"Reset Game Data "<<endl;
    std::cout<<"=============="<<endl;
    pointReseter(Team, Number_of_Teams);
    std::cout<<"Game Data has been reset successfully ..."<<endl;
    Game_Table(Team,Number_of_Teams);
}



void pointReseter(TeamData *Team, int Number_of_Teams){
    for (int i = 0; i < Number_of_Teams; i++) {
        Team[i].Points = 0;
        Team[i].Matches = 0;
    }
}
