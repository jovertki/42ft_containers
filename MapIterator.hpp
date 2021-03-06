#pragma once
#include "iterator_traits.hpp"
#include <functional>
#include "utils.hpp"
#include "map.hpp"

namespace ft {
	template <class Key, class T, bool isConst >
	class MapIterator : public iterator<std::bidirectional_iterator_tag, T> {
	private:
	public:
		typedef Key
			key_type;
		typedef T
			mapped_type;
		typedef ft::pair<const Key, T>
			value_type;

		typedef typename conditional<isConst, const value_type, value_type>::type true_value_type;
		
		typedef typename iterator<std::bidirectional_iterator_tag, value_type>::iterator_category
			iterator_category;
		typedef typename iterator<std::bidirectional_iterator_tag, value_type>::difference_type
			diff_type;
		typedef typename iterator<std::bidirectional_iterator_tag, true_value_type>::pointer
			pointer;
		typedef typename iterator<std::bidirectional_iterator_tag, true_value_type>::reference
			reference;
		typedef typename ft::map<Key, T>::treeNode treeNode;
	private:
		const treeNode* _nodePtr;
		const treeNode* _tree;
	public:
		MapIterator( const treeNode* curr, const treeNode* root ) : _nodePtr( curr ), _tree( root ) {}
		MapIterator() : _nodePtr( NULL ), _tree( NULL ) {}
		MapIterator( MapIterator const& a ) : _nodePtr( a._nodePtr ), _tree( a._tree ) {}
		MapIterator& operator=( MapIterator const& a ) {
			_nodePtr = a._nodePtr;
			return *this;
		}
		virtual ~MapIterator() {}

		reference operator*() const {
			return *_nodePtr->value;
		}
		pointer operator->() const {
			return _nodePtr->value;
		}

		const treeNode* getNode() const {
			return _nodePtr;
		}
		// 	//INCREMENTS DECREMENTS
		MapIterator& operator++() {
			treeNode* p;
			if(_nodePtr == NULL)
			{
				return *this;
			}
			else
				if(_nodePtr->right != NULL)
				{
					// successor is the farthest left node of
					// right subtree
					_nodePtr = _nodePtr->right;

					while(_nodePtr->left != NULL) {
						_nodePtr = _nodePtr->left;
					}
				}
				else
				{
					p = _nodePtr->parent;
					while(p != NULL && _nodePtr == p->right)
					{
						_nodePtr = p;
						p = p->parent;
					}
					_nodePtr = p;
				}

			return *this;
		}
		MapIterator operator++( int ) {
			MapIterator iterator = *this;
			++(*this);
			return iterator;
		}



		MapIterator& operator--() {
			treeNode* p;
			if(_nodePtr == NULL)
			{
				_nodePtr = _tree;
				if(_nodePtr == NULL)
					return *this;
				while(_nodePtr->right != NULL) {
					_nodePtr = _nodePtr->right;
				}
			}
			else
				if(_nodePtr->left != NULL)
				{
					// successor is the farthest right node of
					// left subtree
					_nodePtr = _nodePtr->left;

					while(_nodePtr->right != NULL) {
						_nodePtr = _nodePtr->right;
					}
				}
				else
				{
					p = _nodePtr->parent;
					while(p != NULL && _nodePtr == p->left)
					{
						_nodePtr = p;
						p = p->parent;
					}
					_nodePtr = p;
				}

			return *this;
		}
		
		MapIterator operator--( int ) {
			MapIterator iterator = *this;
			--(*this);
			return iterator;
		}

		//to const
		operator ft::MapIterator<Key, T, true>() const {
			return ft::MapIterator<Key, T, true>( _nodePtr, _tree );
		}

		//COMPARE
		//methods are doubled to handle iterator<int> == iterator<const int>

		//==
		template <class Keyy, class T1, bool Const1, bool Const2>
		friend bool operator==( const MapIterator<Keyy, T1, Const1>& a, const MapIterator<Keyy, T1, Const2>& b ) {
			return (a._nodePtr == b._nodePtr);
		}
		template <class Keyy, class T1, bool Const1>
		friend bool operator==( const MapIterator<Keyy, T1, Const1>& a, const MapIterator<Keyy, T1, Const1>& b ) {
			return (a._nodePtr == b._nodePtr);
		}
		

		//!=
		template <class Keyy, class T1, bool Const1, bool Const2>
		friend bool operator!=( const MapIterator<Keyy, T1, Const1>& a, const MapIterator<Keyy, T1, Const2>& b ) {
			return (a._nodePtr != b._nodePtr);
		}
		template <class Keyy, class T1, bool Const1>
		friend bool operator!=( const MapIterator<Keyy, T1, Const1>& a, const MapIterator<Keyy, T1, Const1>& b ) {
			return (a._nodePtr != b._nodePtr);
		}

	};
}