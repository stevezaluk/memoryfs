#include <iostream>
#include <vector>

#include "../include/block.hpp"
#include "../include/inode.hpp"
#include "../include/utils.hpp"

using namespace std;
using namespace block;
using namespace IndexNode;

Block::Block(int blockNumber, string data) {
    Block::blockNumber = blockNumber;
    Block::data = data;
}

int Block::getBlockNumber() {
    return Block::blockNumber;
}

void Block::setBlockNumber(int blockNumber) {
    Block::blockNumber = blockNumber;
}

string Block::getData() {
    return Block::data;
}

void Block::setData(string data) {
    Block::data = data;
}

SuperBlock::SuperBlock(Dentry *root):Block(0, "") {
    SuperBlock::totalNumberOfInodes = 0;
    SuperBlock::totalUsedInodes = 0;
    SuperBlock::totalUsedBlocks = 0;
    SuperBlock::defaultBlockSize = 512;
    
    SuperBlock::filesystemCreationDate = getCurrentDateTime();
    SuperBlock::filesystemModifiedDate = getCurrentDateTime();

}

int SuperBlock::getTotalNumberInodes() {
    return SuperBlock::totalNumberOfInodes;
}

int SuperBlock::getDefaultBlockSize() {
    return SuperBlock::defaultBlockSize;
}

string SuperBlock::getFileSystemCreation() {
    return SuperBlock::filesystemCreationDate;
}

string SuperBlock::getFileSystemModified() {
    return SuperBlock::filesystemModifiedDate;
}

vector<Block *> SuperBlock::getBlockBitmap() {
    return SuperBlock::blockBitmap;
}

void SuperBlock::appendBlockBitmap(Block *block) {
    SuperBlock::blockBitmap.push_back(block);
}

