#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
/*This is a machine which initializes with the file "Definition.txt".
Functions:
    transistionFunction: This accepts the present state and remaining string and returns the next state.
    getInitialState: This is a getter function which returns the initialState.
    checker: This checks whether the input is selected by the machine or not.
*/
class Machine{
private:
    vector<char> States;
    vector<char> Alphabets;
    vector<vector<char>> transistion;
    char initialState;
    vector<char> finalStates;
public:
    Machine(){
    ifstream definition;
    definition.open("definition.txt");
    if(!definition.is_open())
    cout<<"Error";
    char c;
    while((c = definition.get()) != '\n')
    {
        Alphabets.push_back(c);
    }
    while((c = definition.get()) != '\n')
    {
        States.push_back(c);
    }
        vector<char> temp;
        for(int i=0; i<States.size(); i++)
        {
            for(int j=0; j<Alphabets.size();j++)
            {
                temp.push_back(definition.get());
            }
            c=definition.get();
            transistion.push_back(temp);
            temp.clear();
        }
    initialState = definition.get();
    c=definition.get();
    while((c = definition.get()) != EOF)
    {
        finalStates.push_back(c);
    }
    }
    char transistionFunction(char state, char checkLetter){
        int presentState=-1, presentLetter=-1;
        if(checkLetter=='e')
        return state;
        for(int i=0;i<States.size();i++)
        {
        if(state==States[i]){
             presentState=i;
             break;
        }
        }
        for(int i=0;i<Alphabets.size();i++)
        {
            if(checkLetter==Alphabets[i])
            {
                presentLetter=i;
                break;
            }

        }
        if(presentLetter==-1){
        cout<<"The string is not valid.";
        exit(1);
        }
        if(presentState==-1){
        cout<<"The state is not valid.";
        exit(1);
        }
       return transistion[presentState][presentLetter];
        }

    char getInitialState()
    {
        return initialState;
    }

    void checker(char state)
    {   vector<char>::iterator it;
        it = find(finalStates.begin(),finalStates.end(),state);
        if(it != finalStates.end())
            cout<<"The input string is accepted."<<endl;
        else
            cout<<"The input string is not accepted."<<endl;
    }
};
//This function generates remaining string from the present string.
string generator(string word)
        {
            string remain=word.length()>0?word:"e";
            if(remain != "e")
            remain.erase(0,1);
            remain=remain.length()>0?remain:"e";
            return remain;
        }
//This function generates a single letter from the string.
char checkLetter(string word)
        {
             char checkLetter=word.at(0);
             return checkLetter;
        }
int main()
{
    Machine M1;
    string S1,remain;
    char state=M1.getInitialState();
    char check;
    cout<<"Enter a string to check:";
    cin>>S1;
    remain=S1;
    check=checkLetter(remain);
    cout<<"("<<'q'<<state<<','<<remain<<")"<<endl;
    while(1)
    {
        state=M1.transistionFunction(state, check);
        remain=generator(remain);
        cout<<"  |-"<<"("<<'q'<<state<<','<<remain<<")"<<endl;
        check=checkLetter(remain);
        if(check=='e')
        break;
    }
    M1.checker(state);
}
