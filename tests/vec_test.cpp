#include <iostream>
#include <vector>

using namespace std;

class Obj {

    protected:
        vector<Obj *> z;
        int zz;

    public:
        int x;
        int y;

        Obj() {
            cout << "Constructor" << endl;
        }

        vector<Obj *> getVec() {
            return this->z;
        }
};

int main() {
    Obj *o = new Obj();

    // vector<int> x = o->getVec();

    // cout << x.size() << endl;

    // for(int i = 0; i < 2; i++) {
    //     x.push_back(i);
    // }

    // cout << x.size() << endl;

    // for(int i = 0; i < 2; i++) {
    //     cout << x.at(i) << endl;
    // }

    vector<Obj *> x = o->getVec();

    cout << x.size() << endl;

    for(int i = 0; i < 2; i++) {
        x.push_back(new Obj());
    }

    cout << x.size() << endl;

    for(int i = 0; i < 2; i++) {
        cout << x.at(i) << endl;
    }

    

    delete o;

    return 0;
}
