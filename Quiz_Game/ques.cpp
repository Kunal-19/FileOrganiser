#include<iostream>
#include<fstream>
#include<unordered_map>
#include<stdlib.h>
using namespace std;


class question{
    public:
    string ques;
    string opt[4];
    int quesNum;

    question(string ques,string a,string b,string c,string d){
        this->ques = ques;
        opt[0] = a, opt[1] = b, opt[2] = c, opt[3] = d;
        quesNum = 0;
    }
};


class questionBank{
    public:
    vector<vector<string> > question;
    vector<string> solutions;

    void createQues(){
        vector<string> questionDetails(5);
        ifstream in("ques.txt");
        
        for(int i = 0; i<15; i++){
            for(int j=0; j<5; j++){
                getline(in,questionDetails[j]);
            }
            question.push_back(questionDetails);
        }
        in.close();
    }

    private:
    void ansBank(){
        ifstream in("ans.txt");        
        for(int i=0; i<15; i++){
            string temp;
            getline(in,temp);
            solutions.push_back(temp);
        }       
    }
};