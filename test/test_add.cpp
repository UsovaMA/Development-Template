#include <gtest/gtest.h>
#include "add.h"

TEST(Pemometeeeeer, openfileintrue) {
  Pedometer rs;
  ASSERT_NO_THROW(rs.infile());
}

TEST(Pemometeeeeer, openfileouttrue) {
  Pedometer rs;
  ASSERT_NO_THROW(rs.outfile());
}

TEST(Pemometeeeeer, constrcopy) {
  Pedometer rs;
  Pedometer rc(rs);
  EXPECT_EQ(rs, rc);
}

/* 

� ���� � �������, ��� ������, ����� ���� ._. �� ���� ����� ������ ����� :(
��� ����� ������ ����� �� �������(���������) ��� ����������??(����� ���������� ������ �����)

*/