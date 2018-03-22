#ifndef REPL_H
#define REPL_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;


class SingletonShell
{
    private:
        string buffer,define,opr,dir;
        const static int buffer_size = 256;
        const string welcome = "Welcome to OS SHell!";
        bool loop_active = true;
        char cwd[buffer_size];
        int temp;
        
        static SingletonShell* shell;

        SingletonShell();
        bool first_cd(string dir);
        bool to_quit(string choice);

    public:
        
       
        static SingletonShell* getInstance();
        void runShell();
};
#endif