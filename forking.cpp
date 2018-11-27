#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <cstring>
#include <string>
using namespace std;

//This the method for replacing string inside the text
//This method will be executed if the child process is invoked
int child_program(string target_string,string replacement, string text){
    int target_length = target_string.length();
    int replacement_length = replacement.length();
    int replacement_count=0;
    
    bool loop = true;
    while(loop){
        int index = text.find(target_string);
        
        //if the number of replacing is 0
        if (replacement_count==0 ){
            //if the string is found in the text
            if (index != -1){
                text.erase(index,target_length);
                text.insert(index, replacement);
                replacement_count++;
                //cout<<"count == 0"<<endl;
            }
        }
        else{
            //if the string is found in the text
            if (index != -1){
                text.erase(index,target_length);
                text.insert(index, replacement);
                replacement_count++;
                //cout<<"Count != 0"<<endl;
            }
            //if the target string is not found in the text
            else{
                loop = false;
                //cout<<"end"<<endl;
            }
        }
    }
    cout<<"The amount of string replaced: "<<replacement_count<<endl;
    cout<<endl;
    cout<<"Changed text: \n"+text<<endl;
    cout<<endl;
}

int main() {
    //hard code text
    string text = "Tom M. Mitchell provided a widely quoted, more formal definition of the algorithms studied in the machine learning field: A computer program is said to learn from experience E with respect to some class of tasks T and performance measure P if its performance at tasks in T, as measured by P, improves with experience E.[9] This definition of the tasks in which machine learning is concerned offers a fundamentally operational definition rather than defining the field in cognitive terms. This follows Alan Turing's proposal in his paper Computing Machinery and Intelligence, in which the question Can machines think? is replaced with the question Can machines do what we (as thinking entities) can do?. In Turing's proposal the various characteristics that could be possessed by a thinking machine and the various implications in constructing one are exposed. Machine learning tasks Machine learning tasks are typically classified into several broad categories:Supervised learning: The computer is presented with example inputs and their desired outputs, given by a teacher, and the goal is to learn a general rule that maps inputs to outputs. As special cases, the input signal can be only partially available, or restricted to special feedback.Semi-supervised learning: The computer is given only an incomplete training signal: a training set with some (often many) of the target outputs missing. Active learning: The computer can only obtain training labels for a limited set of instances (based on a budget), and also has to optimize its choice of objects to acquire labels for. When used interactively, these can be presented to the user for labeling.Unsupervised learning: No labels are given to the learning algorithm, leaving it on its own to find structure in its input. Unsupervised learning can be a goal in itself (discovering hidden patterns in data) or a means towards an end (feature learning). Reinforcement learning: Data (in form of rewards and punishments) are given only as feedback to the program's actions in a dynamic environment, such as driving a vehicle or playing a game against an opponent.";
    
    pid_t child_pid;
    string target_string;
    string replacement;
    bool loop = true;
    
    while (loop){
        cout<<"The original text: \n"+text<<endl;
        cout<<endl;
        
        //ask for the user for input
        cout<<"What string you want to replace in the text: "<<endl;
        cin.clear();
        getline(cin,target_string);
        
        //if the input is !wq then process terminated
        if (target_string.compare("!wq")==0)loop = false;
        
        else{
            //ask the user for replacement
            cout<<"What is the replacement: "<<endl;
            cin.clear();
            getline(cin,replacement);
            //if the input is !wq then process terminated
            if (replacement.compare("!wq")==0)loop = false;
        }
        
        if (loop){
            child_pid = fork();
            if (child_pid <0){
                //if the child process failed to be created
                cout<<"Error in creating a child."<<endl;
                exit(0);
            }
            else if (child_pid ==0){
                //call the child_process method
                child_program(target_string, replacement, text);
                exit(0);
            }
            else{
                //If parent process is invoked, then the parent have to wait until the child finish
                wait(NULL);
            }
        }
    }
    
    return 0;
}

