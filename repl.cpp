#include "repl.h"


SingletonShell* SingletonShell::shell = 0;

SingletonShell* SingletonShell::getInstance()
{
    if (shell == 0)
    {
        shell = new SingletonShell();
    }

    return shell;
}

SingletonShell::SingletonShell()
{
    this->define="OS SHell: ~/";
}
void SingletonShell::runShell(){
    cout<<welcome << endl;
    while(loop_active)
    {
        //cout<<define;
        //getline(cin,buffer);
        buffer = getcwd(cwd, sizeof(cwd));//push command line to buffer
        temp = int(buffer.find_last_of("/"));//find index of last "/"
        buffer=buffer.substr(temp+1);//fush to buffer sub string with "/"
        
        cout<<endl;
        cout<<define+buffer<<">";

        getline(cin,dir);
        if(to_quit(dir))// if user input exit or quit
        {
            cout << "C ya!\n";
            //loop_active=false;
            exit(0);
        }
        

        
        if(first_cd(dir))
        {
            temp = int(dir.find_last_of(" ")+1);//if first cd split cd and directory
            dir = dir.substr(temp);//put directory to dir without "cd"
            
            /*
            //print all location of folder "PATH" - "not working"
            if(const char* env_p = getenv(dir.c_str())){
                cout << "Your PATH is: " << env_p <<endl;
            }
            */
            
            int p = chdir(dir.c_str());//change directory and check if exist - if exist 0 or 1 else -1
            if(p<0)
            {
                perror("OS SHell: cd:");//print error messege
            }
            
        }

        //buffer = "";
    }
}
bool SingletonShell::first_cd(string dir)
{
    string opr=dir.substr(0,2);
    return (opr == "cd");
}
    
bool SingletonShell::to_quit(string choice)
{
    return (choice == "quit" || choice == "exit");
}


