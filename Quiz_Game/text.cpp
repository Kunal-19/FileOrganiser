#include<iostream>
#include<stdlib.h>

using namespace std;

class text{
    public:

    void rules(){        
        instructions();
        makingInitailChoice();
        questionTraversalInstructions();        
        char choice = makingChoice();
        command(choice);
    }

    void instructions(){
        system("clear");
        cout << "\t\t\t\t*************-WELCOME TO THE QUIZ-GAME-*************"<< endl<<endl;
        cout << "PLEASE FOLLOW THE INSTRUCTIONS"<< endl;
        cout << "-------------------------------------------------------"<< endl;
        cout << "1. THE QUIZ CONTAINS A SET OF 15 QUESTIONS." << endl;
        cout << "2. FOR EACH CORRECT ANSWER YOU WILL BE AWARDED 4 MARKS."<< endl;
        cout << "3. FOR EACH INCORRECT ANSWER -1 WILL BE DEDUCTED." << endl;
        cout << "-------------------------------------------------------"<< endl<< endl;
    }

    void questionTraversalInstructions(){
        system("clear");
        cout << "\t\t\t\t**************-QUESTION TRAVERSALS**************"<< endl<< endl;
        cout << "PLEASE FOLLOW THE INSTRUCTIONS"<< endl;
        cout << "-------------------------------------------------------"<< endl;
        cout << "1. Select '1' to go to next question." << endl;
        cout << "2. Select '2' to go to prev question."<< endl;
        cout << "3. Select '3' to go to random question of your choice.." << endl;
        cout << "-------------------------------------------------------"<< endl<< endl;
    }


    void makingInitailChoice(){
        cout << "Please select 'Y' if you read the instructions : ";
        char choice = '\0';
        while(1){
            cin >> choice;
            if(choice =='y' || choice=='Y') break;
            else
                cout << "Please Read the Instructions properly.. Please select a valid option(Y/y): ";
        }
    }


    char makingChoice(){
        cout << "Please select 'Y' to play the game or 'N' to exit the game : ";
        char choice = '\0';
        while(1){
            cin >> choice;
            if(choice =='y' || choice=='n' || choice=='Y' || choice=='N') break;
            else
                cout << "You made a invalid selection.. Please select a valid option(Y/N): ";
        }
        return choice;
    }


    void command(char choice){
        if(choice == 'n' || choice == 'N'){
            //Clearing the Screen
            system("clear");

            //Moving the cursor to desired position
            printf("\033[%d;%dH", 4, 40);
            cout << "You successfully Exit the game!!!"<< endl;

            //Asking user to whether he/she wants to play again..
            cout << "\nDo you want to play the game again?? " << endl;
            char choice = makingChoice();

            //Exiting the game..
            if(choice == 'n' || choice == 'N') exit(0);
        }
    }
};