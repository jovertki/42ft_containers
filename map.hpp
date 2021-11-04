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
		class Allocator = std::allocator<ft::pair<const Key, T> >
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
		class treeNode {
			public:
			value_type* value;
			treeNode* right;
			treeNode* left;
			treeNode* parent;
			treeNode(const value_type* value, treeNode* parent = NULL, treeNode* right = NULL, treeNode* left = NULL )
				: value( const_cast<value_type*>(value) ), parent( parent ), right( right ), left( left ) {}
			value_type* getValue() {
				return value;
			}
			const value_type* getValue() const{
				return value;
			}
		};

		
	private:

		allocator_type _alloc;
		size_type _size;
		treeNode* _root;
		Compare _comp;


		treeNode* getNewNode( const value_type* data, treeNode* parent ) {
			treeNode* treeNode = new class treeNode( data, parent );
			return treeNode;
		}

		//use lixicograph!!!!!!
		ft::pair<ft::pair<iterator, bool>, treeNode*> insertReq( treeNode* root, treeNode* parent, const value_type* value ) {
			ft::pair<ft::pair<iterator, bool>, treeNode*> out;
			if(root == NULL) {
				root = getNewNode( value, parent );
				out = ft::make_pair( ft::make_pair( iterator( root, _root ), true ), root );
			}
			else if(value->first < root->value->first) {
				out = insertReq( root->left, root, value );
				root->left = out.second;
			}
			else if(value->first > root->value->first) {
				out = insertReq( root->right, root, value );
				root->right = out.second;
			}
			else
				out = ft::make_pair( ft::make_pair( iterator( root, _root ), false ), root );
			out.second = root;
			return out;
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

		void    deleteAll( treeNode* node )
		{
			if(!node)
				return;
			deleteAll( node->left );
			deleteAll( node->right );
			_alloc.destroy( node->value );
			_alloc.deallocate( node->value, sizeof( value_type ) );
			delete node;
			_size -= 1;
		}
	public:
		//BASE MEMBERS
		//constructors
		//default
		map() : _root( NULL ), _comp( Compare() ), _alloc( Allocator() ), _size( 0 ) {}
		explicit map( const Compare& comp,
			const Allocator& alloc = Allocator() ) : _root( NULL ), _comp(comp), _alloc(alloc), _size(0) {}


		virtual ~map() {
			clear();
		}
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
			return (insert( ft::make_pair( key, T() ) ).first)->second;

		}

		//ITERATORS
		//begin
		iterator begin() {
			return iterator( findMin( _root ), _root );
		}
		const_iterator begin() const {
			return const_iterator( findMin( _root ), this );
		}
		//end
		iterator end() {
			return iterator( NULL, _root );
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
		void clear() {
			deleteAll( _root );
		}

		//insert
		//(1)
		ft::pair<iterator, bool> insert( const value_type& value ) {
			pointer temp = _alloc.allocate( 1 );
			_alloc.construct( temp, value );

			ft::pair<ft::pair<iterator, bool>, treeNode*> out = insertReq( _root, NULL, temp );
			if (_size == 0)
				_root = out.second;
			_size++;
			return out.first;
		}
		//(4)
		// iterator insert( iterator hint, const value_type& value ) {
		// 	pointer temp = _alloc.allocate( 1 );
		// 	_alloc.construct( temp, value );

		// 	ft::pair<ft::pair<iterator, bool>, treeNode*> out = insertReq( const_cast<treeNode*>(hint.getNode()), NULL, temp );
		// 	if(_size == 0)
		// 		_root = out.second;
		// 	_size++;
		// 	return out.first.first;
		// }
		//erase

		//swap

	};

}

