#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> w(v);
	EXPECT_EQ(v, w);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> w(v);
	w[0] = 1;
	EXPECT_FALSE(v[0] == 1);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v.at(0) = 4;
  EXPECT_EQ(v[0], 4);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
  TDynamicVector<int> v(1);
  EXPECT_ANY_THROW(v.at(-1) = 2);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(1);
	EXPECT_ANY_THROW(v.at(2) = 2);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(1);
	EXPECT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> w(5);
	EXPECT_NO_THROW(v = w);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> w(6);
	v = w;
	EXPECT_EQ(v.size(), 6);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> w(6);
	v = w;
	EXPECT_NO_THROW(v = w);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v(2);
	TDynamicVector<int> w(2);
	v[0] = 1; v[1] = 2;
	w[0] = 1; w[1] = 2;
	EXPECT_EQ(v, w);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v(2);
	EXPECT_EQ(v, v);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> w(6);
	EXPECT_FALSE(v == w);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v(5);
	EXPECT_NO_THROW(v + 6);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v(5);
	EXPECT_NO_THROW(v - 6);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> v(5);
	EXPECT_NO_THROW(v * 6);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> w(5);
	EXPECT_NO_THROW(v + w);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> w(6);
	EXPECT_ANY_THROW(v + w);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> w(5);
	EXPECT_NO_THROW(v - w);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> w(6);
	EXPECT_ANY_THROW(v - w);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> w(5);
	EXPECT_NO_THROW(v * w);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> w(6);
	EXPECT_ANY_THROW(v * w);
}

