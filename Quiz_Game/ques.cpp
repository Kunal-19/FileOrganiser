#include<iostream>
#include<fstream>
#include<unordered_map>
#include<stdlib.h>
using namespace std;


class question{
    public:
    string ques;
    string optA,optB,optC,optD;
    question *next;
    question *prev;
    unordered_map<question*,string> answer;

    vector<int> MarkForReview;
    vector<int> Solved;
    vector<int> Unsolved;

    unordered_map<int,bool> visited;    


    question(string ques,string a,string b,string c,string d){
        this->ques = ques;
        optA = a;
        optB = b;
        optC = c;
        optD = d;
        this->next = NULL;
        this->prev = NULL;
    }
};


void insertAtFirst(vector<string> &ques,question *&head, question *&tail){
    question *q1 = new question(ques[0],ques[1],ques[2],ques[3],ques[4]);
    head = q1;
    head->prev = head;
    tail = head;
    tail->next = head;
}


void insertAtTail(vector<string> &ques,question *&head, question *&tail){
    question *q1 = new question(ques[0],ques[1],ques[2],ques[3],ques[4]);
    tail->next = q1;
    q1->prev = tail;
    tail = q1;
    tail->next = head;
    head->prev = tail;
}


class questionBank{
    public:
    question *head = NULL;   
    question *tail = NULL;

    unordered_map<int,question*> mp;

    void createQues(){
        vector<string> questionDetails(5);
        ifstream in("ques.txt");
        
        for(int i = 0; i<15; i++){
            for(int j=0; j<5; j++){
                getline(in,questionDetails[j]);
            }

            mp[i+1] = tail;

            if(head == NULL) insertAtFirst(questionDetails,head,tail);
            else insertAtTail(questionDetails,head,tail);
        }
        in.close();
    }

    void ansBankk(){
        question *q;

        ifstream in("ans.txt");
        question *ptr = head;

        while(ptr){
            string ans = "";
            getline(in,ans);

            q->answer[ptr] = ans;
            ptr = ptr->next;
        }
    }

    question *getHead(){
        return head;
    }
    question *getTail(){
        return tail;
    }
};
