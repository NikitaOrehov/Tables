#pragma once
#include "Table.h"
#include "marks.h"
#include <string>
#include <chrono>
#include "people.h"


using namespace std;
using namespace chrono;

class TableTestKit{
private:
    Table& _table;
    

    int maxFindEfficient = 0;
    int minFindEfficient = 0;
    double averageFindEfficient = 0;
    double TimeFind = 0;
    int maxDelEfficient = 0;
    int minDelEfficient = 0;
    double averageDelEfficient = 0;
    double TimeDel = 0;

    void FindRecord() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, 199);
        for (int i = 0; i < 100; i++) {
            auto start = high_resolution_clock::now();
            _table.Find(names[distrib(gen)]);
            auto end = high_resolution_clock::now();
            TimeFind += duration_cast<microseconds>(end - start).count();
            if (maxFindEfficient <= _table.GetEfficiency()) {
                maxFindEfficient = _table.GetEfficiency();
            }
            else if (minFindEfficient > _table.GetEfficiency()) {
                minFindEfficient = _table.GetEfficiency();
            }
            averageFindEfficient += _table.GetEfficiency();
        }
        averageFindEfficient /= 100;
    }

    void DelRecord() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, 199);
        for (int i = 0; i < 100; i++) {
            auto start = high_resolution_clock::now();
            _table.DelRecord(names[distrib(gen)]);
            auto end = high_resolution_clock::now();
            TimeDel += duration_cast<microseconds>(end - start).count();
            if (maxDelEfficient <= _table.GetEfficiency()) {
                maxDelEfficient = _table.GetEfficiency();
            }
            else if (minDelEfficient > _table.GetEfficiency()) {
                minFindEfficient = _table.GetEfficiency();
            }
            averageDelEfficient += _table.GetEfficiency();
        }
        averageDelEfficient /= 100;
    }


public:
    TableTestKit(Table& table) : _table(table){}
    void FillTable(){}

    void GenBenchmarkTab() {
        for (int i = 0; i < 200; i++) {
            _table.InsRecord(names[i], new Marks());
        }
    }


    void ShowTable(){
        if (_table.Reset()) return;
        do {
            std::cout << _table.GetKey() << " " << *_table.GetValuePtr() << "\n";
        } while (!_table.GoNext());
    }

    void PrintMetrics() {
        FindRecord();
        DelRecord();
        std::cout << "---------------------\n";
        std::cout << "Maximum search efficiency: " << maxFindEfficient << "\n";
        std::cout << "Minimum search efficiency: " << minFindEfficient << "\n";
        std::cout << "Average search efficiency: " << averageFindEfficient << "\n";
        std::cout << "Maximum removal efficiency: " << maxDelEfficient << "\n";
        std::cout << "Minimum removal efficiency: " << minDelEfficient << "\n";
        std::cout << "Average removal efficiency: " << averageDelEfficient << "\n";
        std::cout << "search time: " << TimeFind << "\n";
        std::cout << "removal time: " << TimeDel << "\n";
    }




};