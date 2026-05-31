#include <gtest/gtest.h>

#include "../include/ClassDoublyLinkedList.h"

TEST(ClassDoublyLinkedList, TestConstructors)
{
	DoublyLinkedList<int> Zero;
	EXPECT_EQ(Zero.printData(), nullptr);
	EXPECT_EQ(Zero.printSize(), 0);
	EXPECT_TRUE(Zero.empty());

	DoublyLinkedList<int> One{ 1, 2, 3 };
	EXPECT_EQ(One.printSize(), 3);
	EXPECT_EQ(One[0], 1);
	EXPECT_EQ(One[1], 2);
	EXPECT_EQ(One[2], 3);

	list<int> a = { 4, 5, 6 };
	DoublyLinkedList<int> Two(a);
	EXPECT_EQ(Two.printSize(), 3);
	EXPECT_EQ(Two[0], 4);
	EXPECT_EQ(Two[1], 5);
	EXPECT_EQ(Two[2], 6);

	DoublyLinkedList<int> Three(Two);
	EXPECT_EQ(Three.printSize(), 3);
	EXPECT_EQ(Three[0], 4);
	EXPECT_EQ(Three[1], 5);
	EXPECT_EQ(Three[2], 6);

	DoublyLinkedList<int> Original{ 7, 8 };
	DoublyLinkedList<int> Moved(move(Original));
	EXPECT_EQ(Original.printSize(), 0);
	EXPECT_EQ(Original.printData(), nullptr);
	EXPECT_EQ(Moved.printSize(), 2);
	EXPECT_EQ(Moved[0], 7);
	EXPECT_EQ(Moved[1], 8);
}

TEST(ClassDoublyLinkedList, Index_Operator)
{
	DoublyLinkedList<int> One;
	EXPECT_THROW(One[20], runtime_error);

	DoublyLinkedList<int> Two{ 5, 7, 10, 9 };
	EXPECT_EQ(Two[2], 10);
}

TEST(ClassDoublyLinkedList, EQ_Operators)
{
	DoublyLinkedList<int> One{ 1, 2, 3, 4, 5 };
	DoublyLinkedList<int> Two{ 1, 2, 3, 4, 5 };
	DoublyLinkedList<int> Three{ 1, 2, 3, 4 };
	EXPECT_TRUE(One == Two);
	EXPECT_TRUE(One != Three);
	EXPECT_FALSE(One == Three);
}

TEST(ClassDoublyLinkedList, Assign_Operators)
{
	DoublyLinkedList<int> One;
	DoublyLinkedList<int> Two{ 1, 2, 3 };
	One = Two;
	EXPECT_EQ(One.printSize(), 3);
	EXPECT_EQ(One[0], 1);
	EXPECT_EQ(One[1], 2);
	EXPECT_EQ(One[2], 3);

	DoublyLinkedList<int> Three;
	Three = move(Two);
	EXPECT_EQ(Two.printSize(), 0);
	EXPECT_EQ(Two.printData(), nullptr);
	EXPECT_EQ(Three.printSize(), 3);
	EXPECT_EQ(Three[0], 1);
	EXPECT_EQ(Three[1], 2);
	EXPECT_EQ(Three[2], 3);
}

TEST(ClassDoublyLinkedList, Insert_Functions)
{
	DoublyLinkedList<int> First;
	First.push_back(2);
	First.push_front(1);
	First.push_back(4);
	First.insert(2, 3);

	EXPECT_EQ(First.printSize(), 4);
	EXPECT_EQ(First[0], 1);
	EXPECT_EQ(First[1], 2);
	EXPECT_EQ(First[2], 3);
	EXPECT_EQ(First[3], 4);
}

TEST(ClassDoublyLinkedList, Remove_Functions)
{
	DoublyLinkedList<int> First{ 1, 2, 3, 4 };

	EXPECT_EQ(First.pop_front(), 1);
	EXPECT_EQ(First.printSize(), 3);
	EXPECT_EQ(First[0], 2);

	EXPECT_EQ(First.pop_back(), 4);
	EXPECT_EQ(First.printSize(), 2);
	EXPECT_EQ(First[1], 3);

	First.remove(0);
	EXPECT_EQ(First.printSize(), 1);
	EXPECT_EQ(First[0], 3);
}

TEST(ClassDoublyLinkedList, Find_And_Modify)
{
	DoublyLinkedList<int> First{ 10, 20, 30 };

	EXPECT_EQ(First.find(20), 1);
	EXPECT_EQ(First.find(50), -1);
	EXPECT_TRUE(First.contains(30));
	EXPECT_FALSE(First.contains(40));

	EXPECT_TRUE(First.modify(20, 25));
	EXPECT_EQ(First[1], 25);
	EXPECT_FALSE(First.modify(100, 200));
}

TEST(ClassDoublyLinkedList, Shift_Operators)
{
	DoublyLinkedList<int> First{ 1, 2 };
	First << 3;
	EXPECT_EQ(First.printSize(), 3);
	EXPECT_EQ(First[2], 3);

	int deleted = 0;
	First >> deleted;
	EXPECT_EQ(deleted, 1);
	EXPECT_EQ(First.printSize(), 2);
	EXPECT_EQ(First[0], 2);
}

TEST(ClassDoublyLinkedList, Empty)
{
	DoublyLinkedList<int> First;
	EXPECT_TRUE(First.empty());

	First.push_back(10);
	EXPECT_FALSE(First.empty());
}

TEST(ClassDoublyLinkedList, Clear)
{
	DoublyLinkedList<int> First{ 1, 2 };
	First.clear();

	EXPECT_EQ(First.printSize(), 0);
	EXPECT_EQ(First.printData(), nullptr);
	EXPECT_TRUE(First.empty());
}

TEST(ClassDoublyLinkedList, ToString)
{
	DoublyLinkedList<int> First{ 1, 2, 3 };
	EXPECT_EQ(First.toString(), "{1, 2, 3}");
}

TEST(ClassDoublyLinkedList, Empty_Errors)
{
	DoublyLinkedList<int> First;
	EXPECT_THROW(First.pop_front(), runtime_error);
	EXPECT_THROW(First.pop_back(), runtime_error);
	EXPECT_THROW(First.remove(0), runtime_error);
}

int main(int argc, char** argv)
{
	system("chcp 65001 > nul");

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
