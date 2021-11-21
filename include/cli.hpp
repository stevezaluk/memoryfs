#include <iostream>

#include "inode.hpp"
#include "block.hpp"
#include "list.hpp"

#ifndef CLI_H
#define CLI_H

class CommandLine {

    private:
        void parseInput();

    public:
        std::string currentPath;
        IndexNode::Dentry *currentDirectory;
        IndexNode::InodeTable *inodeTable;
        LinkedList::List *currentSubdirs;
        block::SuperBlock *superBlock;
        
        std::string command;
        std::string subCommand;
        std::string previousCommand;
        
        CommandLine(std::string command);

        void loop();

        void help();

        void ls();
        void cd(std::string name);
        void pwd();
        void mkdir(std::string name);
        void touch(std::string name);
        void remove(std::string name);
        
        void sb();
        void intable();
        void info();
        void restart();

        void save(std::string name);
        void saveSb();
        void loadSb(std::string path);
};

#endif