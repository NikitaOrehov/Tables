#pragma once
#include "Table.h"
#include "marks.h"
#include <string>


class TableTestKit{
private:
    Table& _table;


public:
    TableTestKit(Table& table) : _table(table){}
    void FillTable(){}

    void GenBenchmarkTab(std::vector<std::string> keys) {
        for (int i = 0; i < 100; i++) {
            _table.InsRecord(keys[i], new Marks());
        }
    }


    void ShowTable(){
        if (_table.Reset()) return;
        do {
            std::cout << _table.GetKey() << " " << *_table.GetValuePtr() << "\n";
        } while (!_table.GoNext());
    }

    void FindRecord(){}

    void DelRecord() {}

    void PrintMetrics() {}




};