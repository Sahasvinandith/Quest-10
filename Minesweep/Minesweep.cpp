    /*21/ENG/122 : S.V.WEDISINGHE
    21/ENG/122 : S.W.U. SANJANA
    21/ENG/157 : W.A.D. SHENARA*/

#include <iostream>
#include "Grid.h"
using namespace std;

int main()
{
    cout<<"\n\t\tTWELCOME TO MINE SWEEPER\n\n";
    cout<<"Option List\n\n";
    cout<<"\tField option\t|\tSize(grid size)\t\t|\tNo. of Mines\n";
    cout<<"\t  Option 1  \t|\t   10 by 10    \t\t|\t     12     \n";
    cout<<"\t  Option 2  \t|\t   15 by 15    \t\t|\t     18     \n";
    cout<<"\t  Option 3  \t|\t   20 by 20    \t\t|\t     24     \n";

    int option;
    cout<<"\nEnter your option number: ";
    cin>>option;

    Grid* newgrid=new Grid(10,10);
    switch (option)
    {
    case 1:
        newgrid = new Grid(10, 10);
        
        break;
        
    case 2:
        newgrid = new Grid(15, 15);
        break;

    case 3:
        newgrid = new Grid(20, 20);
        break;
    default:
        cout << "Wrong input!!! please try again!!!.\n";
        system("pause");
        system("cls");
        main();
        return 0;
    }

    cout<<endl;

    if (newgrid->playGame() == -1) {
        system("cls");
        cout << "Sorry You lost.. Press to start a new game..\n";
        system("pause");
        system("cls");
        main();
    }
    else {
        system("cls");
        cout << "Congratulations!!! You win !! Press to play again.\n";
        system("pause");
        system("cls");
        main();

    }

    


    


    

}



