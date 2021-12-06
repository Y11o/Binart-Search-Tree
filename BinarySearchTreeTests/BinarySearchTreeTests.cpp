#include "pch.h"
#include "CppUnitTest.h"
#include "..\BinarySearchTree\BST.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinarySearchTreeTests
{
	TEST_CLASS(BinarySearchTreeTests)
	{
	public:
		
		TEST_METHOD(Contains)
		{
			BinarySearchTree tree;
			tree.insert(5);
			Assert::IsTrue(tree.contains(5) == 1);
			Assert::IsTrue(tree.contains(10) == 0);

		}

		TEST_METHOD(Insert)
		{
			BinarySearchTree tree;
			tree.insert(5);
			tree.insert(88);
			tree.insert(30);
			Assert::IsTrue(tree.contains(5) == 1);
			Assert::IsTrue(tree.contains(88) == 1);
			Assert::IsTrue(tree.contains(30) == 1);
			Assert::IsTrue(tree.contains(99) == 0);
		}

		TEST_METHOD(Remove)
		{
			BinarySearchTree tree;
			tree.insert(5);
			tree.insert(88);
			tree.insert(11);
			tree.insert(-100);
			tree.insert(30);
			Assert::IsTrue(tree.contains(5) == 1);
			tree.remove(-100);
			Assert::IsTrue(tree.contains(-100) == 0);
		}
	};
}

