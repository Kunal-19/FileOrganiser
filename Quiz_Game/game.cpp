#include<iostream>
#include<unordered_map>
#include<stdlib.h>
#include<string.h>
#include"text.cpp"
#include"ques.cpp"

class game
{
    unordered_map<question*,char> UserAns;
    vector<int> MarkForReview;
    map<int,char> Solved;
    
    game(){
        for(int i = 0; i<15; i++){
            Solved[i+1] = ' ';
        }
    }

public:
    questionBank ques;
    question *quesNode = NULL;
    unordered_map<int,question *> questionNumMapping;
    text instr;

    void print(question *q)
    {
        cout << q->ques << endl;
        cout << q->optA << endl;
        cout << q->optB << endl;
        cout << q->optC << endl;
        cout << q->optD << endl;
    }

    void startGame()
    {
        ques.createQues();
        questionNumMapping = ques.mp;
        question *ptr = ques.getHead();
        quesNode = ptr;
        system("clear");       
        print(quesNode); 
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
            }
        }

        instr.questionTraversalInstructions();
        char mode = '\0';
        cout << "Select a mode to move to different Question: ";
        cin >> mode ;
        quesTraversal(quesNode,mode);
        system("clear");
        print(quesNode);
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

    void quesTraversal(question *&head,char mode){
        switch(mode){
            case '1': 
                head = head->next;
                break;
            case '2':
                head = head->prev;
                break;
            case '3': 
                int quesNo = questionNumValidity();
                questionBank ques;
                question *ptr = questionNumMapping[quesNo];

                cout << ptr << endl;
                while(head!=ptr){
                    head = head->next;
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