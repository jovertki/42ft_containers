#pragma once

#include <memory>
#include <cstddef>
#include "VectorIterator.hpp"
#include "reverse_iterator.hpp"
#include <iostream>
#include <sstream>
#include "meta_functions.hpp"
#include "utils.hpp"

namespace ft {
	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<std::pair<const Key, T> >
	> class map {
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef std::size_t							size_type;
		typedef std::ptrdiff_t						difference_type;
		typedef Compare key_compare;
		typedef Allocator							allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer 	const_pointer;


		//NYI
		// typedef ft::VectorIterator<value_type> iterator;
		// typedef ft::VectorIterator< const value_type> const_iterator;
		// typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		// typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

		
	private:
		class treeNode {
			public:
			value_type value;
			treeNode* right;
			treeNode* left;
			treeNode( const value_type& value, treeNode* right = NULL, treeNode* left = NULL) : value( value ), right( right ), left( left ) {}
		};
		
		allocator_type _alloc;
		size_type _size;
		treeNode* _root;
		Compare _comp;


		treeNode* getNewNode( const value_type& data ) {
			treeNode* treeNode = new class treeNode( data);
			return treeNode;
		}

		//use lixicograph!!!!!!
		treeNode* insertReq( treeNode* root, const value_type& value ) {
			if(root == NULL)
				root = getNewNode( value );
			else if(value.first <= root->value.first) {
				root->left = insertReq( root->left, value );
			}
			else {
				root->right = insertReq( root->right, value );
			}
			return root;
		}



		treeNode* searchTree( treeNode* root, const Key& key ) {
			if(root == NULL)
				return NULL;
			if(root->value.first == key)
				return root;
			else if(root->value.first <= key)
				return searchTree( root->right, key );
			else
				return searchTree( root->left, key );
			return NULL;
		}
	public:
		//BASE MEMBERS
		//constructors
		//default
		map() : _root( NULL ), _comp( Compare() ), _alloc( Allocator() ), _size( 0 ) {}
		explicit map( const Compare& comp,
			const Allocator& alloc = Allocator() ) : _root( NULL ), _comp(comp), _alloc(alloc), _size(0) {}
		
		//get_allocator
		allocator_type get_allocator() const {
			return _alloc;
		}


		//ELEMENT ACCESS
		//at

		//operator[]
		T& operator[]( const Key& key ) {
			return searchTree( _root, key )->value.second;
			//return iterator to insert later?
		}

		//ITERATORS
		//begin

		//CAPACITY
		//empty
		// bool empty() const {
		// 	return begin() == end();
		// }

		//size
		size_type size() const {
			return _size;
		}

		//max_size
		size_type max_size() const {
			return _alloc.max_size();
		}


		//MODIFIERS
		//clear
		void clear() {}

		//insert
		//(1)
		// ft::pair<iterator, bool> insert( const value_type& value ) {
		void insert( const value_type& value ) {
			_root = insertReq( _root, value );
		}
		//erase

		//swap

	};

}

