#include<iostream>
#include<unordered_map>
#include<stdlib.h>
#include<string.h>
#include"text.cpp"
#include"ques.cpp"

class game
{
    unordered_map<question*,char> UserAns;
public:
    questionBank ques;
    question *quesNode = NULL;
    text instr;

    void print(question *q)
    {
        cout << q->ques << endl;
        cout << q->optA << endl;
        cout << q->optB << endl;
        cout << q->optC << endl;
        cout << q->optD << endl;
    }

    void gameplay()
    {
        ques.createQues();
        question *ptr = ques.getHead();
        quesNode = ptr;
        system("clear");       
        print(ptr->next); 

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
                UserAns[quesNode] = choice;
                cout << endl;
                instr.questionTraversalInstructions();
                char mode = '\0';
                cout << "Select a mode to move to different Question: ";
                cin >> mode ;
                quesTraversal(quesNode,mode);
            }
        }
    }

    void quesTraversal(question *&head,char mode){
        switch(mode){
            case '1': head = head->next;
            case '2': head = head->prev;
            case '3': 
                cout << "Enter the Question Number to want to go: ";
                int quesNo;
                cin >> quesNo;
                questionBank ques;
                question *ptr = ques.mp[quesNo];

                while(head!=ptr){
                    head = head->next;
                }
        }
    }
};

int main()
{
    game g;
    g.gameplay();
    return 0;
}