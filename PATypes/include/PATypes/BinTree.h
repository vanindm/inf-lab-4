#pragma once

#include <random>
#include <ctime>
#include "PairTuple.h"

namespace PATypes {
	template <class T>
	class BinaryTreeNode {
		T val;
		int priority;
		BinaryTreeNode<T> *l, *r;
	public:
		BinaryTreeNode(T val, int priority, BinaryTreeNode<T> *l = nullptr, BinaryTreeNode<T> *r = nullptr) : val(val), priority(priority), l(l), r(r) {};
		BinaryTreeNode(const BinaryTreeNode<T> &node);
		BinaryTreeNode(bool (*f)(T), const BinaryTreeNode<T> &node);
		~BinaryTreeNode() {
		delete l;
		delete r;
	}
		void map(T (*f)(T));
		BinaryTreeNode<T> *getLeft() const { return l; }
		BinaryTreeNode<T> *getRight() const { return r; }
		void setLeft(BinaryTreeNode<T>* n) { this->l = n; }
		void setRight(BinaryTreeNode<T>* n) { this->r = n; }

		int getPriority() { return priority; }
		T getVal() { return val; }
	};

	template<class T>
	class BinaryTree {
		BinaryTreeNode<T> *root;
		std::mt19937 mt;
	public:
		BinaryTree() : root(nullptr), mt(time(nullptr)) {};
		BinaryTree(const BinaryTreeNode<T> &root);
		BinaryTree(bool (*f)(T), BinaryTree<T> tree);
		void merge(BinaryTree<T> tree);
		BinaryTree<T> *map(T (*f)(T));
		BinaryTreeNode<T> *_merge(BinaryTreeNode<T> *l, BinaryTreeNode<T> *r);
		Pair<BinaryTreeNode<T>*, BinaryTreeNode<T>*> _split(BinaryTreeNode<T> *root, T key);
		BinaryTreeNode<T>* _search(BinaryTreeNode<T> *node, T key);
		void _insertAll(const BinaryTreeNode<T> *node);
		void _insertAllWhere(bool (*f)(T), const BinaryTreeNode<T> *node);

		BinaryTreeNode<T> *getRoot() { return root; };
		BinaryTreeNode<T> *findElement(T val);

		void insert(T key);
		BinaryTree<T> getSubTree(BinaryTreeNode<T> *current);
	};

	template<class T>
	BinaryTreeNode<T>::BinaryTreeNode(const BinaryTreeNode<T> &node) {
		val = node.val;
		priority = node.priority;
		if (node.l != nullptr) {
			this->l = new BinaryTreeNode<T>(*node.getLeft());
		}
		if (node.r != nullptr) {
			this->r = new BinaryTreeNode<T>(*node.getRight());
		}
	}

	template<class T>
	BinaryTreeNode<T>::BinaryTreeNode(bool (*f)(T), const BinaryTreeNode<T> &node) {
		_insertAllWhere(f, &node);
	}

	template<class T>
	void BinaryTree<T>::_insertAll(const BinaryTreeNode<T> *node) {
		if (node != nullptr)
			this->insert(node->getVal());
		if (node->getLeft())
			_insertAll(node->getLeft());
		if (node->getRight())
			_insertAll(node->getRight());
	}

	template<class T>
	void BinaryTree<T>::_insertAllWhere(bool (*f)(T), const BinaryTreeNode<T> *node) {
		if (node != nullptr && f(node->getVal()))
			this->insert(node->getVal());
		if (node->getLeft())
			_insertAll(node->getLeft());
		if (node->getRight())
			_insertAll(node->getRight());
	}

	template<class T>
	void BinaryTreeNode<T>::map(T (*f)(T)) {
		val = f(val);
		if (l != nullptr)
			l->map(f);
		if (r != nullptr)
			r->map(f);
	}

	template<class T>
	BinaryTree<T>::BinaryTree(const BinaryTreeNode<T> &root) : mt(time(nullptr)) {
		this->root = new BinaryTreeNode<T>(root);
	}

	template<class T>
	BinaryTree<T>::BinaryTree(bool (*f)(T), BinaryTree<T> tree) : mt(time(nullptr)) {
		this->root = new BinaryTreeNode<T>(*tree.root);
	}

	template<class T>
	BinaryTree<T> *BinaryTree<T>::map(T (*f)(T)) {
		BinaryTree<T> *newTree = new BinaryTree(*root);
		newTree->root->map(f);
	}

	template<class T>
	void BinaryTree<T>::merge(BinaryTree<T> tree) {
		if (tree.getRoot()->getVal() < getRoot()->getVal()) {
			root = _merge(tree.getRoot(), root);
		} else {
			root = _merge(root, tree.getRoot());
		}
	}
	
	template<class T>
	BinaryTreeNode<T> *BinaryTree<T>::_merge(BinaryTreeNode<T> *l, BinaryTreeNode<T> *r) {
		//if (r != nullptr && l != nullptr && l->getVal() >= r->getVal()) {
		//	throw std::logic_error("слияние нарушит инвариант дерева!");
		//}
		if (l == nullptr)
			return r;
		if (r == nullptr)
			return l;
		if (l->getPriority() > r->getPriority()) {
			l->setRight(_merge(l->getRight(), r));
			return l;
		} else {
			r->setLeft(_merge(l, r->getLeft()));
			return r;
		}
	}

	template<class T>
	Pair<BinaryTreeNode<T>*, BinaryTreeNode<T>*> BinaryTree<T>::_split(BinaryTreeNode<T> *first, T key) {
		if (first == nullptr) {
			return Pair<BinaryTreeNode<T>*, BinaryTreeNode<T>*>(nullptr, nullptr);
		}
		if (first->getVal() <= key) {
			Pair<BinaryTreeNode<T>*, BinaryTreeNode<T>*> second = _split(first->getRight(), key);
			first->setRight(second.getFirst());
			return Pair<BinaryTreeNode<T>*, BinaryTreeNode<T>*>(first, second.getSecond());
		} else {
			Pair<BinaryTreeNode<T>*, BinaryTreeNode<T>*> second = _split(first->getLeft(), key);
			first->setLeft(second.getSecond());
			return Pair<BinaryTreeNode<T>*, BinaryTreeNode<T>*>(second.getFirst(), first); 
		}
	}

	template<class T>
	void BinaryTree<T>::insert(T key) {
		Pair<BinaryTreeNode<T>*, BinaryTreeNode<T>*> second = _split(root, key);
		BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>(key, mt());
		root = _merge(second.getFirst(), _merge(newNode, second.getSecond()));
	}

	template<class T>
	BinaryTreeNode<T>* BinaryTree<T>::_search(BinaryTreeNode<T> *node, T key) {
		if (node == nullptr || key == node->getVal()) {
			return node;
		}
		if (key < node->getVal()) {
			return _search(node->getLeft(), key);
		} else {
			return _search(node->getRight(), key);
		}
	}

	template<class T>
	BinaryTreeNode<T> *BinaryTree<T>::findElement(T val) {
		return _search(root, val);
	}
}