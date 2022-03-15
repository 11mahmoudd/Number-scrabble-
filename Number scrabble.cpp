#include <iostream>
#include <sstream>
using namespace std;
int list_size=9;
int list_of_numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int sum1=0;
int sum2=0;
int turn=0;
void explain();
void display_state();
int get_input(string player);
bool check_int(string inputt);
bool find_item(int arr[],int size,int searched_item);
void display_score();
bool first_won();
bool second_won();
bool empty();
void update_score(int number);
void play();

int main()
{
    play();
}


void explain()
{
    cout<<"Number scrabble is played with the list of numbers between 1 and 9.\n";
    cout<<"Each player takes turns picking a number from the list.\n";
    cout<<"Once a number has been picked, it cannot be picked again.\n";
    cout<<"If a player has picked three numbers that add up to 15, that player wins the game.\n";
    cout<<"However, if all the numbers are used and no player gets exactly 15, the game is a draw.\n";

}



void display_state()
{
    for(int i=0;i<list_size;i++)
        if (i == list_size-1)
            cout<<list_of_numbers[i];
        else if (i<list_size)
            cout<<list_of_numbers[i]<<",";
    
}



bool check_int(string inputt)
{
    bool integer ;
    for (int i=0; i<inputt.length();i++)
    {
        if(isdigit(inputt[i])==true)
        {
            integer =  true;
        }
        else
            integer = false;
    }
    return integer;
}




int get_input(string player)
{
    bool check= true;
    string picked;
    int choosen=0;
    while (check)
    {
        cout<<player <<" player please enter the number you want to pick : ";
        cin>>picked;
        if (check_int(picked))
        {
            stringstream x(picked);
            x >>choosen;
            if (find_item(list_of_numbers,list_size,choosen))
            {
                for (int i=0;i<=list_size;i++)
                {
                    if (list_of_numbers[i]==choosen)
                    {
                        for (int j=i;j<=(list_size-1);j++)
                            list_of_numbers[j]=list_of_numbers[j+1];
                            list_size-=1;
                    }
                }
            check=false;
            }
            else
                cout<<"***Check if the number is available in the list ,please*** \n";
        }
    }
    return choosen;
}



void update_score(int number)
{
    if (turn%2 ==0)
    {
        sum1+=number;
        turn+=1;
    }
    else
    {
        sum2+=number;
        turn+=1;
    }

}





bool find_item(int arr[],int size,int searched_item)
{

    bool found = false;
    for(int i=0;i<size ; i++)
    {
        if(arr[i]==searched_item)
            found = true;
    }
    return found;
}


void display_score()
{
    cout<<"First player have : "<<sum1<<"\n" ;
    cout<<"Second player have : "<<sum2 <<"\n";
}



bool first_won()
{
    if (sum1==15)
        return true;
    else
    return false;
}


bool second_won()
{
    if (sum2==15)
        return true;
    else
    return false;
}



bool empty()
{
    if(sizeof(list_of_numbers)==0)
    {
        return false;
    }
    else
        return true;
}


void play()
{
    bool run = empty();
    explain();
    while (run)
    {
        display_state();
        update_score(get_input("\nFirst"));
        display_score();
        if (first_won())
        {
            cout<<"First player won <3 ";
            break;
        }
        display_state();
        if(sum1 != 15 && sum2 != 15 && list_of_numbers[0]==0)
        {
            cout<<"Draw";
            break;
        }
        update_score(get_input("\nSecond"));
        display_score();
        if (second_won())
        {
            cout<<"Second player won <3 ";
            break;
        }
    }
}
