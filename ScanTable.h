#pragma once
#include "ArrayTable.h"



class ScanTable:public ArrayTable{
public:
    ScanTable(size_t size=25):ArrayTable(size){};

    virtual PDatValue Find(const Key& key) override;
    virtual void InsRecord(const Key& key, PDatValue value) override;
    virtual void DelRecord(const Key& key) override;

};