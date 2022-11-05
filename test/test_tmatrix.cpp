#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> v(5);
	TDynamicMatrix<int> w(v);
	EXPECT_EQ(v, w);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> v(5);
	TDynamicMatrix<int> w(v);
	w[0][0] = 1;
	EXPECT_FALSE(v[0][0] == 1);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> v(4);

	EXPECT_EQ(4, v.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> v(4);
	v[0][0] = 4;

	EXPECT_EQ(4, v[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> v(1);
	EXPECT_ANY_THROW(v.at(-1).at(0) = 2);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> v(1);
	EXPECT_ANY_THROW(v.at(2).at(0) = 2);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> v(1);
	EXPECT_NO_THROW(v = v);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> v(5);
	TDynamicMatrix<int> w(5);
	EXPECT_NO_THROW(v = w);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> v(5);
	TDynamicMatrix<int> w(6);
	v = w;
	EXPECT_EQ(v.size(), 6);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> v(5);
	TDynamicMatrix<int> w(6);
	v = w;
	EXPECT_NO_THROW(v = w);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> v(2);
	TDynamicMatrix<int> w(2);
	v[0][0] = 1; v[0][1] = 2;
	v[1][0] = 3; v[1][0] = 4;
	w[0][0] = 1; w[0][1] = 2;
	w[1][0] = 3; w[1][0] = 4;
	EXPECT_EQ(v, w);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> v(2);
	EXPECT_EQ(v, v);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> v(5);
	TDynamicMatrix<int> w(6);
	EXPECT_FALSE(v == w);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> v(5);
	TDynamicMatrix<int> w(5);
	EXPECT_NO_THROW(v + w);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> v(5);
	TDynamicMatrix<int> w(6);
	EXPECT_ANY_THROW(v + w);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> v(5);
	TDynamicMatrix<int> w(5);
	EXPECT_NO_THROW(v - w);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> v(5);
	TDynamicMatrix<int> w(6);
	EXPECT_ANY_THROW(v - w);
}

