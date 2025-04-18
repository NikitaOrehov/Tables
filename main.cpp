#include <iostream>
#include "TableTestKit.h"
#include "ScanTable.h"
#include <random> // c++11
#include <algorithm> // c++11

#include <iostream>
#include <string>
#include <vector>
#include "ScanTable.h"
#include "TableTestKit.h"

using namespace std;

int main() {
    ScanTable scanTable(200);
    TableTestKit test(scanTable);
    test.GenBenchmarkTab();
    test.ShowTable();
    test.PrintMetrics();
    return 0;
}

