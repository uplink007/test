#ifndef REPL_H
#define REPL_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
//-------------------
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;


class SingletonShell
{
    private:
        string buffer,define,opr,dir;
        const static int buffer_size = 256;
        const string welcome = "Welcome to OS SHell!";
        bool loop_active = true;
        char cwd[buffer_size];
        string home;
        int exit_status;
        static SingletonShell* shell;
        string getParsedCurrentDirectory();
        SingletonShell();
        bool first_cd(string dir);
        void to_quit(string choice,int status=0);
        void printShellDirectory();
        void run_command_exec(string command);

    public:
        static SingletonShell* getInstance();
        void runShell();
};
#endif