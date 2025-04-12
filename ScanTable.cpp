#include "ScanTable.h"


PDatValue ScanTable::Find(const Key& key) {
    if (Reset()) return nullptr;
    do {
        if (this->GetKey() == key) {
            return this->GetValuePtr();
        }
    } while (!this->GoNext());
    return nullptr;
}
void ScanTable::InsRecord(const Key& key, PDatValue value){
    if(IsFull())
        throw "table is full";
    else{
        _records[_dataCount]=new TabRecord(key, value);//нужно override print прям тут
        _dataCount++;
    }
}
void ScanTable::DelRecord(const Key& key){
    PDatValue tmp=Find(key);
    if(tmp==nullptr)
        throw "no element with this key";
    else{
        _records[_curPos]=_records[_dataCount-1];
        _dataCount--;
    }
}