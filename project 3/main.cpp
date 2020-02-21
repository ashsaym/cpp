/*
Task: H3
Family Name: Saym
Given Name: Md Abu
Matriculation number: 3022015
Uni-Email: md.saym@stud.uni-due.de
Course of Studies: ISE CE SWT
*/

#include <iostream>
#include <limits>
#include <fstream>
#include <string>

using namespace std;

struct Entry{
    std::string Key;
    std::string Value;
};

int HashNumber(std::string, int);
int PrimeNumber();
bool PrimeCheck(int);
int findNextPrime(int);
bool OpenFile(std::string ,Entry [], int);
int HashTableItem(std::string, std::string, Entry [], int &);
void Search(std::string,Entry[], int &);
void Print(Entry [], int );


int main(void){
    std::string Name,File;
    bool isFileOpen;
    int Prime = PrimeNumber();
    Entry Table[Prime];
    while (!isFileOpen){
        std::cout<<"Enter File path / file Name to open : ";   /* example :  C:\\Users\\MdAbuSaym\\CLionProjects\\hw_3\\test.txt */
        std::cin>>File;
        isFileOpen = OpenFile(File,Table,Prime);
    }
    Print(Table,Prime);
    while (Name!="0"){
        std::cout<<std::endl<<"translate (0 for end): ";
        std::cin>>Name;
        if (Name=="0"){
            std::cout<<"Thank you... Have a nice day !!!"<<std::endl;
            return EXIT_SUCCESS;
        } else{
            Search(Name,Table,Prime);
            std::cout<<std::endl;
        }
    }
}

int PrimeNumber(){
    int Number;
    std::cout<<std::endl;
    std::cout << "please input value for (prime) number p:\t ";
    std::cin >> Number;
    while(std::cin.fail())
    {
        std::cout << "Invalid Entry..Enter a valid Prime number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "please input value for (prime) number p: " <<std::endl;
        std::cin >> Number;
    }
    bool isPrime = PrimeCheck(Number);
    if(!isPrime){
        std::cout <<Number<< " is not a prime number.Next Possible Prime Numbers is : "<<findNextPrime(Number);
        PrimeNumber();
    }
    return Number;
}
bool PrimeCheck(int Number){
    for (int j=2; j*j<=Number; j++)
    {
        if (Number % j == 0)
            return false;
    }
    return true;
}
int findNextPrime(int Number)
{
    int nextPrime = Number;
    bool found = false;
    while (!found)
    {
        nextPrime++;
        if (PrimeCheck(nextPrime)){
            found = true;
        }
    }
    return nextPrime;
}

int HashNumber(std::string Name, int Prime){
    int Hash = int(Name[0]);
    for (int i=0;i<Name.length()-1;i++)
    {
        Hash=((Hash*128)+int(Name[i+1]))%Prime;
    }
    return Hash;
}

bool OpenFile(std::string filePath,Entry Table[], int Prime){
    std::string line;
    std::ifstream file;
    int colls = 0;
    file.open(filePath,std::ios::in);
    std::cout<<std::endl;
    if(!file){
        std::cout<<"Error in opening file "<<filePath<<std::endl;
        return false;
    } else{
        std::cout<<"File opened : "<<filePath<<std::endl;
        while(std::getline(file, line))
        {
            std::string word,word_en,word_de,German,German_1,German_2,English,English_1,English_2 = "";
            for (char x : line)
            {
                if (x == ';')
                {
                    German = word;
                    word = "";
                }
                else{
                    word = word + x;
                }
                English = word;
            }
            for (char y : German)
            {
                if (y == ',')
                {
                    German_1 = word_de;
                    word_de = "";
                }
                else{
                    if (y!=' '){
                        word_de = word_de + y;
                    }
                }
                German_2 = word_de;
            }
            for (char z : English)
            {
                if (z == ',')
                {
                    English_1 = word_en;
                    word_en = "";
                }
                else {
                    word_en = word_en + z;
                }
                English_2 = word_en;
            }
            if (!German_1.empty() and !English_1.empty()){
                colls = colls + HashTableItem(German_1,English_1,Table,Prime);
                colls = colls + HashTableItem(German_2,English_2,Table,Prime);

            } else if (!German_1.empty() and English_1.empty()){
                colls = colls + HashTableItem(German_1,English,Table,Prime);
                colls = colls + HashTableItem(German_2,English,Table,Prime);
            }
            else{
                colls = colls + HashTableItem(German,English,Table,Prime);
            }
        }
        std::cout<<colls<<" collision(s) during insert"<<std::endl;
        file.close();
        return true;
    }
}

int HashTableItem(std::string G,std::string E, Entry Table[],int &Prime)
{
    int n = 0;
    int colls = 0;
    int i=0;
    n=HashNumber(G,Prime);
    while(!0)
    {   if(n==Prime)
        {
            n=0;
        }
        if(Table[n].Key.empty())
        {   Table[n].Key=G;
            Table[n].Value=E;
            std::cout<<"insert :"<<Table[n].Key<<"->"<<Table[n].Value<<" at index:"<<n<<std::endl;
            break;
        } else{
            std::cout<<"\tcollision with "<<Table[n].Key<<std::endl;
            colls = colls +1;
            if(i==Prime)
            {
                std::cout<<"Array Full... Choose another Bigger Prime Number "<<std::endl;
                break;
            }
            i=i+1;
            n++;
        }
    }
    return colls;
}

void Search(std::string Word,Entry Table[], int &Prime){
    int n= 0;
    int i = 0;
    bool Found = false;
    n=HashNumber(Word,Prime);
    while(!0)
    {   if(n==Prime)
        {
            n=0;
        }
        if(Table[n].Key == Word)
        {    std::cout<<Table[n].Key<<" translate ->"<<Table[n].Value<<std::endl;
            break;
        } else{
            if(i==Prime)
            {   if(!Found)
                {std::cout<<"sorry not known : "<<Word<<std::endl;}
                break;
            }
            n++;
            i++;
        }
    }
}

void Print(Entry Table[], int Prime){
    int  Total = 0;
    std::cout<<std::endl;
    for (int i = 0; i < Prime; ++i) {
        if (!Table[i].Key.empty()){
            std::cout<<"index "<<i<<" : "<<Table[i].Key<<" -> "<<Table[i].Value<<std::endl;
            Total = Total+1;
        }
    }
    std::cout<<"Total Words : "<<Total<<std::endl;
}
