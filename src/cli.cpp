#include <iostream>
#include <string>

#include "../include/inode.hpp"
#include "../include/block.hpp"
#include "../include/cli.hpp"
#include "../include/list.hpp"

using namespace std;

CommandLine::CommandLine(string command) {
    CommandLine::command = command;
}

void CommandLine::parseInput() {
    CommandLine::subCommand = CommandLine::command.substr(command.find(' '));
}

void CommandLine::loop() {
    bool exit = true;
    while(exit) {
        cout << CommandLine::currentPath << " $ ";
        getline(cin, CommandLine::command);

        parseInput();
    }
}

void CommandLine::help() {
    cout << "Unix Commands: " << endl;
    cout << "ls [-la] [-r] [DIR] : List directory structure" << endl;
    cout << "cd [DIR] : Change your working directory" << endl;
    cout << "pwd : Print your working directory" << endl;
    cout << "mkdir <DIR> : Make a new directory" << endl;
    cout << "touch <NAME> : Create a new file" << endl;
    cout << "rm <NAME> : Remove a file or directory" << endl;
    cout << "nano <FILE> : Edit a file" << endl;

    cout << "Internal Commands" << endl;
    cout << "sb : Print the superblock metadata" << endl;
    cout << "inode-table [-v] : List the inode table" << endl;
    cout << "info [NAME] : Print info about your current inode" << endl;
    cout << "restart : Restart memoryfs, freeing all inodes from memory, and creating a new superblock" << endl;

    cout << "Persistance Commands: " << endl;
    cout << "save <FILE/DIR> : Save a file/directory, and replicate it to your computer" << endl;
    cout << "save-sb : Save your superblock for later use (includes root dir)" << endl;
    cout << "load-sb <SUPERBLOCK> : Load your superblock" << endl;
    cout << "daemonize : Daemonize memoryfs to make it run in the background with out wiping memory" << endl;
}