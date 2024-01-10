
#include <iostream>
using namespace std;

int main()
{
    cout<<"\nWELCOME TO MINE SWEEPER\n\n";
    cout<<"Option List\n\n";
    cout<<"\tField option\t|\tSize(grid size)\t\t|\tNo. of Mines\n";
    cout<<"\t  Option 1  \t|\t   10 by 10    \t\t|\t     12     \n";
    cout<<"\t  Option 2  \t|\t   15 by 15    \t\t|\t     18     \n";
    cout<<"\t  Option 3  \t|\t   20 by 20    \t\t|\t     24     \n";

    int option;
    cout<<"\nEnter your option number: ";
    cin>>option;
    cout<<endl;

    cout<<"Commands\n\n";
    cout<<"F - place a flag on the location\nR - reveal the uncovered location\n\n";
    char row , column , command;
    cout<<"Enter three letters in <row letter><column letter><command>: ";
    cin>>row>>column>>command;
    if (command != 'r' && command != 'f')
    {
        cout<<"Invalid command!\n";
    }
    

}



