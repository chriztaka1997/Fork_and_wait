#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <cstring>
#include <string>
using namespace std;

int main() {
    string text = "Tom M. Mitchell provided a widely quoted, more formal definition of the algorithms studied in the machine learning field: A computer program is said to learn from experience E with respect to some class of tasks T and performance measure P if its performance at tasks in T, as measured by P, improves with experience E.[9] This definition of the tasks in which machine learning is concerned offers a fundamentally operational definition rather than defining the field in cognitive terms. This follows Alan Turing's proposal in his paper Computing Machinery and Intelligence, in which the question Can machines think? is replaced with the question Can machines do what we (as thinking entities) can do?. In Turing's proposal the various characteristics that could be possessed by a thinking machine and the various implications in constructing one are exposed. Machine learning tasks Machine learning tasks are typically classified into several broad categories:Supervised learning: The computer is presented with example inputs and their desired outputs, given by a teacher, and the goal is to learn a general rule that maps inputs to outputs. As special cases, the input signal can be only partially available, or restricted to special feedback.Semi-supervised learning: The computer is given only an incomplete training signal: a training set with some (often many) of the target outputs missing. Active learning: The computer can only obtain training labels for a limited set of instances (based on a budget), and also has to optimize its choice of objects to acquire labels for. When used interactively, these can be presented to the user for labeling.Unsupervised learning: No labels are given to the learning algorithm, leaving it on its own to find structure in its input. Unsupervised learning can be a goal in itself (discovering hidden patterns in data) or a means towards an end (feature learning). Reinforcement learning: Data (in form of rewards and punishments) are given only as feedback to the program's actions in a dynamic environment, such as driving a vehicle or playing a game against an opponent."
    
    pid_t child_pid;
    string target_string;
    bool loop = true;
    
    while (loop):
        cout<< text <<endl;
        loop = false;
    

}
