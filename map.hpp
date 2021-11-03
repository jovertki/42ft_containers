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
	> class map;
}
#include "MapIterator.hpp"


namespace ft {
	template<
		class Key,
		class T,
		class Compare,
		class Allocator
	> class map {
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef Compare key_compare;
		typedef std::size_t							size_type;
		typedef std::ptrdiff_t						difference_type;
		typedef Allocator							allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer 	const_pointer;

		typedef ft::MapIterator<Key, T, Compare> iterator;
		typedef ft::MapIterator<Key, const T, Compare>  const_iterator;//not sure
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

		
	private:
		friend class ft::MapIterator<Key, T, Compare>;
		class treeNode {
			public:
			value_type* value;
			treeNode* right;
			treeNode* left;
			treeNode* parent;
			treeNode( const value_type& value, treeNode* parent = NULL, treeNode* right = NULL, treeNode* left = NULL ) : value( new value_type(value) ), right( right ), left( left ), parent( parent ) {}
		};

		allocator_type _alloc;
		size_type _size;
		treeNode* _root;
		Compare _comp;


		treeNode* getNewNode( const value_type& data, treeNode* parent ) {
			treeNode* treeNode = new class treeNode( data, parent);
			return treeNode;
		}

		//use lixicograph!!!!!!
		treeNode* insertReq( treeNode* root, treeNode* parent, const value_type& value ) {
			if(root == NULL)
				root = getNewNode( value,  parent);
			else if(value.first <= root->value->first) {
				root->left = insertReq( root->left, root, value );
			}
			else {
				root->right = insertReq( root->right, root, value );
			}
			return root;
		}



		treeNode* searchTree( treeNode* root, const Key& key ) const{
			if(root != NULL) {
				if(root->value->first == key)
					return root;
				else if(root->value->first <= key)
					return searchTree( root->right, key );
				else
					return searchTree( root->left, key );
			}
			return NULL;
		}




		treeNode* findMin( treeNode * root) const {
			treeNode* out = root;
			if(out->left == NULL)
				return out;
			out = findMin( out->left );
			return out;
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
		T& at( const Key& key ) {
			treeNode* temp = searchTree( _root, key );
			if(temp == NULL)
				throw std::out_of_range( "map::at" );
			else
				return temp->value->second;
		}
		const T& at( const Key& key ) const{
			treeNode* temp = searchTree( _root, key );
			if(temp == NULL)
				throw std::out_of_range( "map::at" );
			else
				return temp->value->second;
		}

		//operator[]
		T& operator[]( const Key& key ) {
			treeNode* temp = searchTree( _root, key );
			if(temp != NULL) {
				return temp->value->second;
			}
			else {
				insert( ft::make_pair( key, T() ) );
			}

		}

		//ITERATORS
		//begin
		iterator begin() {
			return iterator(findMin(_root), this);
		}
		const_iterator begin() const {
			return const_iterator( findMin( _root ), this );
		}
		//end
		iterator end() {
			return iterator( NULL, this );
		}
		const_iterator end() const {
			return const_iterator( NULL, this );
		}
		//CAPACITY
		//empty
		bool empty() const {
			return begin() == end();
		}

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
			_root = insertReq( _root, NULL, value );
		}
		//erase

		//swap

	};

}

