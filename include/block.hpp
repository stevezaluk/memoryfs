#include <iostream>
#include <vector>
#include <cstdlib>

#ifndef BLOCK_H
#define BLOCK_H

#include "inode.hpp"

namespace block {
    class Block {
        protected: 
            int blockNumber;
            std::string data;
        
        public:
            Block(int blockNumber, std::string data);
            int getBlockNumber();
            void setBlockNumber(int blockNumber);

            std::string getData();
            void setData(std::string data);
    };

    class SuperBlock: public Block {
        protected:
            int totalNumberOfInodes;
            int totalUsedInodes;

            int totalUsedBlocks;
            int defaultBlockSize;

            IndexNode::Dentry *root;

            std::string filesystemCreationDate;
            std::string filesystemModifiedDate;

            std::vector<block::Block *> blockBitmap; // inodes to blocks

        public:
            SuperBlock(IndexNode::Dentry *root);

            int getTotalNumberInodes();
            int getDefaultBlockSize();

            std::vector<block::Block *> getBlockBitmap();
            void appendBlockBitmap(block::Block *block);

            std::string getFileSystemCreation();
            std::string getFileSystemModified();
    };
};

#endif