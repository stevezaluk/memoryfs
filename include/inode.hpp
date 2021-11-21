#include <iostream>
#include <vector>

#ifndef INODE_H
#define INODE_H

namespace block { // forward decleration
    class Block;
}

#include "list.hpp"

namespace IndexNode {
    /**
    * 
    * 
    * Inode - Abstraction of file metadata
    * 
    * inodeNumber (int) - Its assigned inode number
    * blockCount (int) - The ammount of blocks allocated to this inode
    * 
    * type (str) - File type ie directory, file, or symlink
    * allocatedBlocks (vector<Block *>) -  A vector of pointers that point the file contents
    * 
    * creationTime (str) - Date time of when file was created
    * modifiedTime (str) - Date time of when file was modified
    * accessTime (str) - Date time of when file was accessed
    * 
    **/
    class Inode {
        protected:
            int inodeNumber;
            int blockCount;

            std::string type;

            std::string creationTime;
            std::string modifiedTime;
            std::string accessTime;

            std::vector<block::Block *> allocatedBlocks;

        public:
            Inode();
            ~Inode(); // delete blocks allocated to it

            int getInodeNumber();
            void setInodeNumber(int number);

            int getBlockCount();
            
            std::string getCreationTime();
            std::string getModifiedTime();
            std::string getAccessTime();

            std::string getType();
            void setType(std::string type);

            std::vector<block::Block *> getAllocatedBlocks();

            void allocateBlocks(std::vector<block::Block *> blockBitmap, int numberOfBlocks);
            void allocateBlocks(block::Block *block);
            void allocateBlocks(std::vector<block::Block *> blocks);
    };

    #define FILE "file"
    #define DIR "directory"
    #define ROOT "root"

    class Dentry: public Inode {
        public:
            LinkedList::List *subdirs;
            Dentry *parent;

            Dentry(Dentry *parent);
    };

    class InodeTable {
        public:
            std::vector<Inode *> nodes;
            int length;

            InodeTable();
            void addInode(Inode *inode);
    };
};
#endif