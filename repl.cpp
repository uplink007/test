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
string SingletonShell::getParsedCurrentDirectory(){

        //cout<<define;
        //getline(cin,buffer);
        string currentDirectory=const_cast<char*>(getcwd(cwd,this->buffer_size));
        int i =currentDirectory.find(home);
        cout<<i<<endl;
        if(i!=-1 && currentDirectory.length()>home.length()){
          currentDirectory="~/"+currentDirectory.substr(i+(this->home.length())+1); 
        }else if (i != -1 ){
            currentDirectory="~/";
        }
        return currentDirectory;
}
void SingletonShell::printShellDirectory(){
    cout<< this->define + getParsedCurrentDirectory()<<">";
}

SingletonShell::SingletonShell()
{
   this->define="OS SHell:";
   this->home=getenv("HOME");
}
void SingletonShell::runShell(){
    int indexOfLastSpace;
    cout<<welcome << endl;
    while(loop_active)
    {
       // buffer = getcwd(cwd, sizeof(cwd));//push command line to buffer
        // temp = int(buffer.find_last_of("/"));//find index of last "/"
        // buffer=buffer.substr(temp+1);//fush to buffer sub string with "/"
       // cout<<buffer<<endl;
        printShellDirectory();

        getline(cin,dir);

        to_quit(dir);// if user input exit or quit

        if(first_cd(dir))
        {
            //cout<<dir<<endl;
            indexOfLastSpace = int(dir.find_last_of(" ")+1);//if first cd split cd and directory
            dir = dir.substr(indexOfLastSpace);//put directory to dir without "cd"
           // cout<<dirPath<<endl;
           // char* env_p = getenv("PWD");
            //print all location of folder "PATH" - "not working"
            // cout <<env_p<<endl;
            // if(env_p){
            //     cout << "Your PATH is: " << env_p <<endl;
            // }     
            cout<<dir<<endl;
            if(chdir(dir.c_str())<0)//check if directory was changed successfully 
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
    
void SingletonShell::to_quit(string choice,int status)
{
    if(choice == "quit" || choice == "exit"){
            cout << "C ya!\n";
            //loop_active=false;
            exit(status);
    }
}


