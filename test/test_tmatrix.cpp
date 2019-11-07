#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	int size = 2;
	TMatrix <int> v(size);
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++)
		v[i][j] = j;
	}
	TMatrix <int> v1(v);
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++)
			EXPECT_EQ(j, v1[i][j]);
	}
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	int size = 2;
	TMatrix <int> v(size);
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++)
			v[i][j] = j;
	}
	TMatrix <int> v1(v);
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++)
			v[i][j] = size+j;
	}
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++)
			EXPECT_NE(v1[i][j], v[i][j]);
	}
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	EXPECT_EQ(5,m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(1);
	m[0][0] = 1;
	EXPECT_EQ(1, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> v(3);
	ASSERT_ANY_THROW(v[-2][1]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> v(4);
	ASSERT_ANY_THROW(v[10][3]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> v(4);
	ASSERT_NO_THROW(v = v);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	int size = 2;
	TMatrix<int> v(size);
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++)
			v[i][j] = size - j;
	}
	TMatrix<int> v1(size);
	v1 = v;
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++)
		EXPECT_EQ(v[i][j], v1[i][j]);
	}
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> v1(1);
	TMatrix<int> v2(2);
	v2 = v1;
	EXPECT_EQ(v2.GetSize(), 1);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  TMatrix <int> m1(1);
  m1[0][0] = 1;
  TMatrix<int>m2(2);
  ASSERT_NO_THROW(m2 = m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	int size = 1;
	TMatrix<int> m1(size);
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++)
			m1[i][j] = j;
	}
	TMatrix<int> m2(m1);
	EXPECT_EQ(m2, m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	int size = 1;
	TMatrix<int> m1(size);
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++)
			m1[i][j] = j;
	}
	EXPECT_EQ(m1, m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(1),m2(2);
	EXPECT_NE(m1, m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	int size = 3;
	TMatrix<int> v1(size), v2(size), v3(size);
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			v1[i][j] = 1;
			v2[i][j] = 1;
			v3[i][j] = 2;
		}
	}
	EXPECT_TRUE(v3 == v1 + v2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix <int> m1(1), m2(2);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	int size = 3;
	TMatrix<int> v1(size), v2(size), v3(size);
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			v1[i][j] = 3;
			v2[i][j] = 2;
			v3[i][j] = 1;
		}
	}
	EXPECT_TRUE(v3 == v1 - v2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix <int> m1(1), m2(2);
	ASSERT_ANY_THROW(m1 * m2);
}

