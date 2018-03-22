#include"repl.h"

int main(int argc, char const *argv[])
{

    SingletonShell* shell = SingletonShell::getInstance();
    shell->runShell();
    return 0;
}