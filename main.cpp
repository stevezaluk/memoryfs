#include <iostream>
#include <vector>

#include "include/inode.hpp"
#include "include/block.hpp"
#include "include/cli.hpp"

using namespace std;
using namespace IndexNode;
using namespace block;

void firstStart() {
    Dentry *root = new Dentry(nullptr);
    root->setType(ROOT);
    SuperBlock *sb = new SuperBlock(root);

    // inode table here

    CommandLine *cli = new CommandLine("");
    cli->currentDirectory = root;
    cli->currentPath = "";

}

void inode_test() {
    Dentry *root = new Dentry(nullptr);
    SuperBlock *sb = new SuperBlock(root);
    
    Inode *inode = new Inode();

    inode->setInodeNumber(5);
    inode->setType("directory");

    cout << inode->getInodeNumber() << endl;
    cout << inode->getType() << endl;
    cout << inode->getCreationTime() << endl;

    vector<Block *> blocks = sb->getBlockBitmap();

    inode->allocateBlocks(sb->getBlockBitmap(), 2);

    cout << endl << sb->getBlockBitmap().size() << endl;

    for(int i = 0; i < sb->getBlockBitmap().size(); i++) {
        cout << sb->getBlockBitmap().at(i)->getBlockNumber() << endl;
    }
    
    delete inode;
}

int main() {
    inode_test();
    return 0;
}