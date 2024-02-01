#include "pch.h"
#include "../hamhanded/hamhanded.h"

TEST(hhCalc, Operations) {
  EXPECT_EQ(12, hhCalc("125-5/10"));
  EXPECT_EQ(260, hhCalc("125+5*2"));
}

TEST(hhCalc, CheckDoubleAndMoreSignSymbols) {
	EXPECT_EQ(-1, hhCalc("10+-35-2"));
}

TEST(hhCalc, CheckOtherSymbols) {
	EXPECT_EQ(362, hhCalc("10+35$2"));
	EXPECT_EQ(-1, hhCalc("3#%@4+48"));
}

