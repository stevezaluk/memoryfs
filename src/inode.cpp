#include <iostream>
#include <vector>
#include <string>

#include "../include/inode.hpp"
#include "../include/block.hpp"
#include "../include/utils.hpp"
#include "../include/list.hpp"

using namespace std;
using namespace IndexNode;
using namespace block;
using namespace LinkedList;

/**

 * Inode - class functions

**/
Inode::Inode() {
    Inode::creationTime = getCurrentDateTime();
    Inode::modifiedTime = getCurrentDateTime();
    Inode::accessTime = getCurrentDateTime();

    Inode::type = "file";
}

Inode::~Inode() {
    // for(int i = 0; i < Inode::allocatedBlocks.size(); i++) {
    //     Block *block = Inode::allocatedBlocks.at(i);
    //     delete block;
    // } // untested code
}

int Inode::getInodeNumber() {
    return Inode::inodeNumber;
}

void Inode::setInodeNumber(int number) {
    Inode::inodeNumber = number;
}

int Inode::getBlockCount() {
    return Inode::blockCount;
}

string Inode::getCreationTime() {
    return Inode::creationTime;
}

string Inode::getModifiedTime() {
    return Inode::modifiedTime;
}

string Inode::getAccessTime() {
    return Inode::accessTime;
}

string Inode::getType() {
    return Inode::type;
}

void Inode::setType(string type) {
    Inode::type = type;
}

vector<Block *> Inode::getAllocatedBlocks() {
    return Inode::allocatedBlocks;
}

/*
    Allocates a number of blank blocks to the inode, and avoids misplacing and
    misnumbering blocks.

    Protects the blockBitmap from getting scattered. Prefered method of allocating blocks
*/
void Inode::allocateBlocks(vector<Block *> blockBitmap, int numberOfBlocks) {
    int bmSize = blockBitmap.size();

    if(numberOfBlocks == 0) {
        cout << "[error] Cannot allocate zero blocks to inode: " << Inode::inodeNumber << endl;
    }

    int buf = bmSize + 1;
    for(int i = 0; i < numberOfBlocks; i++) {
        // Block *block = new Block(buf, "");
        blockBitmap.push_back(new Block(buf + 1, ""));
        buf++;
    }
}

/*
    Allocates a single block with a user-created Block object

    Does not protect blockBitmap
*/
void Inode::allocateBlocks(Block *block) {
    Inode::allocatedBlocks.push_back(block);
}
/*
    Allocates multiple blocks using user-created block objects

    Does not protect blockBitmap
*/
void Inode::allocateBlocks(vector<Block *> blocks) {
    for(int i = 0; i < blocks.size(); i++) {
        Inode::allocatedBlocks.push_back(blocks.at(i));
    }
}

// dentry class functions

Dentry::Dentry(Dentry *parent) {
    Dentry::type = "directory";

    Dentry::subdirs = new List(".", Dentry::inodeNumber);

    if(Dentry::parent != nullptr) {
        appendList(subdirs, "..", Dentry::parent->inodeNumber);
    }
}

