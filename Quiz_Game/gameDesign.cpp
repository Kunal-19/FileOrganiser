#include<iostream>
#include<stdlib.h>
#include<string.h>
#include"text.cpp"
#include"ques.cpp"
#include"score.cpp"
using namespace std;


class game
{
public:
    vector<char> UserAns;
    questionBank ques;
    bool trigger;
    vector<vector<string> > questions;
    text instr;
    int quesNum;

    void print(vector<vector<string> > &questions, int quesNum)
    {
        for(int i=0; i<5; i++) cout << questions[quesNum-1][i]<< endl;
    }

    void startGame()
    {
        trigger = true;               // For breaking the loop in submission(N) and question selection
        ques.createQues();
        questions = ques.question;
        system("clear");     
        for(int i=0; i<15; i++) UserAns.push_back(' ');
        this->quesNum = 1;  
        print(questions,quesNum); 
        ansSelection();
    }

    char AnsOrSkip()
    {
        char choice = '\0';
        while (1)
        {
            cin >> choice;
            if (choice == '1' || choice == '2')
                break;
            else
                cout << "Please Read the Instruction properly.. Please select a valid option(1/2): ";
        }
        if(choice == 1 && quesNum==15) trigger = true;
        else if(choice == 2 && quesNum == 15) trigger = false;
        return choice;
    }


    char makingOptChoice()
    {
        char choice = '\0';

        while (1)
        {
            cin >> choice;
            tolower(choice);
            if (choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd' || choice == '#')
                break;
            else
                cout << "Please Read the Instruction properly.. Please select a valid option(a/b/c/d/#): ";
        }
        return choice;
    }   


    void ansSelection(){
        cout << "\nSelect '1' to ans the question or '2' to move to different question : ";
        char choice = AnsOrSkip();

        if(choice == '1'){
            cout << "Choose a valid option(a,b,c,d) or '#' to return back: ";
            char choice = makingOptChoice();
            if(choice == '#') ansSelection();
            else{
                UserAns[quesNum-1] = choice;
                trigger = true;
                cout << endl;
            }
        }

        if(trigger) submit(quesNum);
        instr.questionTraversalInstructions();
        char mode = '\0';
        cout << "Select a mode to move to different Question: ";
        cin >> mode ;
        quesTraversal(quesNum,mode);
        system("clear");
        print(questions,quesNum);
        ansSelection();
    }


    int questionNumValidity(){
        int num = 0;
        while(1){
            cout << "\nEnter the Question Number to want to go: ";
            cin>> num;
            if(num>0 && num<=15) break;
            else cout << "Enter the valid question number from 1-15!!" << endl; 
        }
        return num;
    }


    void quesTraversal(int &quesNum,char mode){
        switch(mode){
            case '1': 
                quesNum++;
                if(quesNum == 16) quesNum = 1;
                break;
            case '2':
                quesNum--;
                if(quesNum == 0) quesNum = 15;
                break;
            case '3': 
                int selectQuesNo = questionNumValidity();
                quesNum = selectQuesNo;
        }
        if(quesNum == 15) trigger = true;
        else trigger = false;
    }


    void submit(int quesNum){
        if(quesNum!=15) return ;
        char choice = '\0';

        while(1){
            cout << "Do you want to submit your answers(Y/N): ";
            cin >> choice;
            choice = tolower(choice);

            if(choice != 'y' && choice!='n') cout <<  "Please Choose a valid option.. Select 'Y' to submit answers else 'N'." << endl<< endl;
            else if(choice == 'y'){
                instr.command('n');
            }
            else{
                trigger = false;
                ansSelection();
            } 
        }
    }
};

int main()
{
    game g;
    g.startGame();
    return 0;
}