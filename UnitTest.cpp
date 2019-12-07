//
// Created by taojianping on 2019/12/7.
//

#include "UnitTest.h"
#include "Utils.h"

void UnitTest::main() {
    TestUtils();
}

void UnitTest::TestUtils() {
    TestUtilsConvertToBitFormat();
}

void UnitTest::TestUtilsConvertToBitFormat() {
    auto u = new Utils();
    Utils::ConvertToBitFormat(2);
}
