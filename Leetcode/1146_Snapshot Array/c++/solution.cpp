/*******************
Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length.  Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

class SnapshotArray {
private:
    unordered_map<int, map<int, int> > nums;
    int snap_id = 0;
public:
    SnapshotArray(int length) {
        snap_id = 0;
        for(int i = 0; i < length; i++)
            nums[i][snap_id] = 0;
    }
    
    void set(int index, int val) {
        nums[index][snap_id] = val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        while(nums[index].find(snap_id) == nums[index].end())
            snap_id--;
        return nums[index][snap_id];
    }
};


int main() {
    return 0;
}