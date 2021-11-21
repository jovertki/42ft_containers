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

		typedef ft::MapIterator<Key, T, false> iterator;
		typedef ft::MapIterator<Key, T, true>  const_iterator;//not sure
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		// class treeNode {
		// 	public:
		// 	value_type* value;
		// 	treeNode* right;
		// 	treeNode* left;
		// 	treeNode* parent;
		// 	int balanceFactor;
		// 	int height;
		// 	treeNode( const value_type* value, treeNode* parent = NULL, treeNode* right = NULL, treeNode* left = NULL )
		// 		: value( const_cast<value_type*>(value) ), right( right ), left( left ), parent( parent ), balanceFactor( 0 ), height( 0 ) {}
		// 	value_type* getValue() {
		// 		return value;
		// 	}
		// 	const value_type* getValue() const{
		// 		return value;
		// 	}
		// };
		typedef treeNode<Key, T> treeNode;
		
	private:

		allocator_type _alloc;
		size_type _size;
		treeNode* _root;
		Compare _comp;
		typedef typename Allocator::template rebind<treeNode>::other node_allocator_type;
		node_allocator_type _altn;

		treeNode* getNewNode( const value_type* data, treeNode* parent ) {
			treeNode* node = _altn.allocate( 1 );
			_altn.construct( node, treeNode( data, parent ) );
			return node;
		}


	public:
		class value_compare {
		protected:
			Compare _comp;
		public:
			value_compare( const Compare& c ) : _comp( c ) {}
			bool operator()( const value_type& lhs,	const value_type& rhs ) const
			{
				return (this->_comp( lhs.first, rhs.first ));
			}
		};
	private:

		bool compValues( const value_type& value1, const value_type& value2 ) const{
			return _comp( value1.first, value2.first );
		}
		
		//key compares
		//==
		bool keysEqual( const Key& key1, const Key& key2 )const {
			if(!_comp( key1, key2 ) && !_comp( key2, key1 ))
				return true;
			return false;
		}
		//<=
		bool keysEqualLess( const Key& key1, const Key& key2 )const {
			if (keysEqual(key1, key2) || _comp(key1, key2))
				return true;
			return false;
		}
		//>=
		bool keysEqualMore( const Key& key1, const Key& key2 )const {
			if(keysEqual( key1, key2 ) || _comp( key2, key1 ))
				return true;
			return false;
		}

		

		//update balance factor for a node
		void update( treeNode* node ) {
			if (node != NULL){
				int lh = -1;
				int rh = -1;
				if(node->left != NULL)
				lh = node->left->height;
				if(node->right != NULL)
				rh = node->right->height;
				node->height = 1 + std::max( rh, lh );
				node->balanceFactor = rh - lh;
			}
		}

		//rotation
		treeNode* rightRotation( treeNode* a ) {
			treeNode* b = a->left;
			b->parent = a->parent;
			a->parent = b;
			a->left = b->right;
			if (a->left != NULL)
 				a->left->parent = a;
			b->right = a;
			update( a );
			update( b );
			return b;
		}
		treeNode* leftRotation( treeNode* a ) {
			treeNode* b = a->right;
			b->parent = a->parent;
			a->parent = b;
			a->right = b->left;
			if (a->right != NULL)
				a->right->parent = a;
			b->left = a;
			update( a );
			update( b );
			return b;
		}
		treeNode* leftLeftCase( treeNode* node ) {
			return rightRotation( node );
		}
		treeNode* leftRightCase( treeNode* node ) {
			node->left = leftRotation( node->left );
			return leftLeftCase( node );
		}
		treeNode* rightRightCase( treeNode* node ) {
			return leftRotation( node );
		}
		treeNode* rightLeftCase( treeNode* node ) {
			node->right = rightRotation( node->right );
			return rightRightCase( node );
		}
		treeNode* balance( treeNode* node ) {
			if(node != NULL) {
				if(node->balanceFactor == -2) {
					if(node->left->balanceFactor <= 0)
						return leftLeftCase( node );
					else
						return leftRightCase( node );
				}
				else if(node->balanceFactor == +2) {
					if(node->right->balanceFactor >= 0)
						return rightRightCase( node );
					else
						return rightLeftCase( node );
				}
			}
			return node;
		}

		//use compare objects
		ft::pair<ft::pair<iterator, bool>, treeNode*> insertReq( treeNode* root, treeNode* parent, const value_type* value ) {
			ft::pair<ft::pair<iterator, bool>, treeNode*> out;
			if(root == NULL) {
				root = getNewNode( value, parent );
				out = ft::make_pair( ft::make_pair( iterator( root, _root ), true ), root );
			}
			else if(compValues(*value, *root->value)) {
				out = insertReq( root->left, root, value );
				root->left = out.second;
			}
			else if(compValues(*root->value, *value )) {
				out = insertReq( root->right, root, value );
				root->right = out.second;
			}
			else
				out = ft::make_pair( ft::make_pair( iterator( root, _root ), false ), root );
			update( root );
			out.second = balance( root );
			return out;
		}



		treeNode* searchTree( treeNode* root, const Key& key ) const {
			if(root != NULL) {
				if(keysEqual(root->value->first, key))
					return root;
				else if (keysEqualLess(root->value->first, key))
					return searchTree( root->right, key );
				else
					return searchTree( root->left, key );
			}
			return NULL;
		}



		treeNode* upper_boundReq( treeNode* root, const Key& key ) const {
			treeNode* tmp = _root;
			while(root)
            {
				if(!_comp( key, root->value->first )) // value <= key
                    root = root->right;
                else // value > key
                {
                    if (root->left)
                    {
						tmp = upper_boundReq( root->left, key );
                        if (tmp)
                            root = tmp;
                        break;
                    }
                    else
                        break;
                }
            }
            return root;
		}

		treeNode* lower_boundReq( treeNode* root, const Key& key ) const {
			treeNode* tmp = _root;
			while(root)
			{
				if(_comp(root->value->first, key )) // value < key
					root = root->right;
				else // value >= key
				{
					if(root->left)
					{
						tmp = lower_boundReq( root->left, key );
						if(tmp)
							root = tmp;
						break;
					}
					else
						break;
				}
			}
			return root;
		}

		treeNode* findMin( treeNode * root) const{
			treeNode* out = root;
			if(out != NULL) {
				if(out->left == NULL)
					return out;
				out = findMin( out->left );
			}return out;
		}


		void    deleteAll( treeNode* node )
		{
			if(!node)
				return;
			deleteAll( node->left );
			deleteAll( node->right );
			_alloc.destroy( node->value );
			_alloc.deallocate( node->value, sizeof( value_type ) );
			_altn.destroy( node );
			_altn.deallocate( node, sizeof( treeNode ) );
			_size -= 1;
		}



		//ERASE (1) STUFF BEGIN
		treeNode* succeedWithTwo( const treeNode* node ) {
			treeNode* donor = node->right;
			while(donor->left != NULL)
				donor = donor->left;
			treeNode* successor = _altn.allocate( 1 );
			_altn.construct( successor, treeNode( NULL, node->parent, node->right, node->left ) );
			successor->value = _alloc.allocate( 1 );
			_alloc.construct( successor->value, *donor->value );
			node->right->parent = successor;
			node->left->parent = successor;
			if(node->parent == NULL) {
				_root = successor;
			}
			else if(node->parent->left == node) {
				node->parent->left = successor;
			}
			else if(node->parent->left == node) {
				node->parent->right = successor;
			}
			update( successor );
			erasePos( donor );
			return successor;
		}


		treeNode* succeedNode( treeNode* successor, treeNode* node ) {
			if(node->parent->left == node) {
				node->parent->left = successor;
				successor->parent = node->parent;
			}
			else {
				node->parent->right = successor;
				successor->parent = node->parent;
			}
			return successor;
		}


		void erasePos( treeNode* node ) {
			treeNode* successor = NULL;
			//erase leaf
			if(!node->right && !node->left) {
				if(node->parent != NULL) {
					if(node->parent->left == node) {
						node->parent->left = NULL;
					}
					else {
						node->parent->right = NULL;
					}
				}
			}
			//erase with only one successor
			else if(node->right && !node->left) {
				successor = succeedNode( node->right, node );

			}
			else if(node->left && !node->right) {
				successor = succeedNode( node->left, node );
			}
			//erase with two successors
			else {
				successor = succeedWithTwo( node );
			}
			update( successor );
			update( node->parent );
			balance( node->parent );
			_alloc.deallocate( node->value, sizeof( value_type ) );
			_altn.destroy( node );
			_altn.deallocate( node, sizeof( treeNode ) );
		}
		//ERASE (1) STUFF END


		//EVERYTHING BELOW IS FOR ERASE 3, MADE WITH REQURSION
		treeNode* succeedNodeReq( treeNode* successor, treeNode* node, bool dealloc ) {
			if(node->parent != NULL) {
				if(node->parent->left == node) {
					node->parent->left = successor;
					successor->parent = node->parent;
				}
				else {
					node->parent->right = successor;
				}
			}
			successor->parent = node->parent;
			if(dealloc) {
				_alloc.deallocate( node->value, sizeof( value_type ) );
				_altn.destroy( node );
				_altn.deallocate( node, sizeof( treeNode ) );
				node = NULL;
			}
			return successor;
		}

		treeNode* eraseLeaf( treeNode* node, bool dealloc ) {
			treeNode* temp = node->parent;
			if(node->parent != NULL) {
				if(node->parent->left == node) {
					node->parent->left = NULL;
				}
				else {
					node->parent->right = NULL;
				}
			}
			if(dealloc) {
				_alloc.deallocate( node->value, sizeof( value_type ) );
				_altn.destroy( node );
				_altn.deallocate( node, sizeof( treeNode ) );
				node = NULL;
			}
			return temp;
		}

		treeNode* eraseReq( treeNode* root, const Key& key, bool dealloc ) {
			if(root == NULL) {
			}
			else if(root->value->first > key) {
				root->left = eraseReq( root->left, key, dealloc );

			}
			else if(root->value->first < key) {
				root->right = eraseReq( root->right, key, dealloc );
			}
			else if(root->value->first == key) {
				if(!root->right && !root->left) {
					eraseLeaf( root, dealloc );
					root = NULL;
					if(dealloc)
						_size--;
				}
				else if(root->right && !root->left) {
					root = succeedNodeReq( root->right, root, dealloc );
					if(dealloc)
						_size--;
				}
				else if(root->left && !root->right) {
					root = succeedNodeReq( root->left, root, dealloc );
					if(dealloc)
						_size--;
				}
				else {
					treeNode* donor = root->right;
					while(donor->left != NULL)
						donor = donor->left;
					//there cant be left in donor
					donor->left = root->left;
					if(root->left)
						root->left->parent = donor;

					if(donor->parent) {
						donor->parent->left = donor->right;
					}
					if(donor->right)
						donor->right->parent = donor->parent;

					if(root->right == donor)
						donor->right = root->right->right;
					else
						donor->right = root->right;
					if(donor->right)
						donor->right->parent = donor;
					donor->parent = root->parent;
					if(donor->parent) {
						if(donor->parent->left == root)
							donor->parent->left = donor;
						else
							donor->parent->right = donor;
					}
					_alloc.deallocate( root->value, sizeof( value_type ) );
					_altn.destroy( root );
					_altn.deallocate( root, sizeof( treeNode ) );
					root = NULL;
					eraseReq( donor->right, donor->value->first, false );
					update( donor );
					root = balance( donor );
					_size--;
				}
			}

			update( root );
			root = balance( root );
			return root;
		}
		//END OF ERASE (3) STUFF

		
	public:
		//BASE MEMBERS
		//constructors
		//default
		map() : _alloc( Allocator() ), _size( 0 ), _root( NULL ), _comp( Compare() ), _altn( node_allocator_type() ) {}
		explicit map( const Compare& comp,
			const Allocator& alloc = Allocator() ) : _alloc( alloc ), _size( 0 ), _root( NULL ), _comp( comp ), _altn( node_allocator_type() ) {}

		//range
		template< class InputIt >
		map( InputIt first, InputIt last,
			const Compare& comp = Compare(),
			const Allocator& alloc = Allocator() ) : _alloc( alloc ), _size( 0 ), _root( NULL ), _comp( comp ), _altn( node_allocator_type() ) {
			insert( first, last );
		}
		//copy
		map( const map& other ) : _alloc( other._alloc ), _size( 0 ), _root( NULL ), _comp( other._comp ), _altn( other._altn ) {
			insert( other.begin(), other.end() );
		}


		map& operator=( const map& other ){
			if(this != &other) {
				deleteAll( _root );
				_alloc = other._alloc;
				_size = 0;
				_root = NULL;
				_comp = other._comp;
				_altn = other._altn;
				insert( other.begin(), other.end() );
			}
			return *this;
		}

		
		virtual ~map() {
			clear();
			_root = NULL;
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
			return const_iterator( findMin( _root ), _root );
		}
		//end
		iterator end() {
			return iterator( NULL, _root );
		}
		const_iterator end() const {
			return const_iterator( NULL, _root );
		}
		//rbegin
		reverse_iterator rbegin() {
			return reverse_iterator( end() );
		}
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator( end() );
		}
		//rend
		reverse_iterator rend() {
			return reverse_iterator( begin() );
		}
		const_reverse_iterator rend() const {
			return const_reverse_iterator( begin() );
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
			return _altn.max_size();
		}

		//MODIFIERS
		//clear
		void clear() {
			deleteAll( _root );
			_root = NULL;
		}

		//insert
		//(1)
		ft::pair<iterator, bool> insert( const value_type& value ) {
			pointer temp = _alloc.allocate( 1 );
			_alloc.construct( temp, value );

			ft::pair<ft::pair<iterator, bool>, treeNode*> out = insertReq( _root, NULL, temp );
			_root = out.second;
			if(out.first.second)
				_size++;
			else {
				_alloc.destroy( temp );
				_alloc.deallocate( temp, sizeof( value_type ) );
			}
			if(_size == 1)
				return ft::make_pair( iterator( _root, _root ), out.first.second );
			return out.first;
		}
		//(4)
		iterator insert( iterator , const value_type& value ) {

			return (insert( value )).first;
		}

		//(7)
		template< class InputIt >
		void insert( InputIt first, InputIt last, typename ft::enable_if < !ft::is_integral<InputIt>::value, char>::type* = 0/*NULL*/ ) {
			while(first != last) {
				insert( *first );
				first++;
			}
		}
		
		//erase
		//(1)
		void erase( iterator pos ) {
			//I could find node with pos's value and do erase(3)
			erase( (*pos).first );
			// erasePos( pos.getNode() );
		}
		//(2)
		void erase( iterator first, iterator last ) {
			//just call (1)???
			while(first != last) {
				iterator next = first;
				next++;
				erase( first );
				first = next;
			}
		}
		//(3)
		size_type erase( const Key& key ) {
			size_type temp = _size;

			_root = eraseReq( _root, key, true );
			update( _root );
			_root = balance( _root );

			if(temp != _size)
				return 1;
			return 0;
		}
		
		//swap
		void swap( map& other ) {
			allocator_type _alloc_b = _alloc;
			size_type _size_b = _size;
			treeNode* _root_b = _root;
			Compare _comp_b = _comp;
			node_allocator_type _altn_b = _altn;

			_alloc = other._alloc;
			_size = other._size;
			_root = other._root;
			_comp = other._comp;
			_altn = other._altn;

			other._alloc = _alloc_b;
			other._size = _size_b;
			other._root = _root_b;
			other._comp = _comp_b;
			other._altn = _altn_b;
		}

		//LOOKUP
		//count
		size_type count( const Key& key ) const {
			if(searchTree( _root, key ) == NULL)
				return 0;
			else
				return 1;
		}
		//find
		//(1)
		iterator find( const Key& key ){
			treeNode* toFind = searchTree( _root, key );
			if(toFind != NULL) {
				return iterator( toFind, _root );
			}
			else
				return end();
		}
		//(2)
		const_iterator find( const Key& key ) const {
			treeNode* toFind = searchTree( _root, key );
			if(toFind != NULL) {
				return iterator( toFind, _root );
			}
			else
				return end();
		}

		//equal_range
		//(1)
		ft::pair<iterator, iterator> equal_range( const Key& key ) {
			return ft::make_pair( lower_bound( key ), upper_bound( key ) );
		}
		//(2)
		ft::pair<const_iterator, const_iterator> equal_range( const Key& key ) const {
			return ft::make_pair( lower_bound( key ), upper_bound( key ) );
		}

		//lower_bound
		//(1)
		iterator lower_bound( const Key& key ) {
			return iterator( lower_boundReq( _root, key ), _root );
		}
		//(2)
		const_iterator lower_bound( const Key& key ) const {
			return iterator( lower_boundReq( _root, key ), _root );
		}
		//upper_bound
		//(1)
		iterator upper_bound( const Key& key ) {
			return iterator(upper_boundReq( _root, key ), _root);
		}
		//(2)
		const_iterator upper_bound( const Key& key ) const{
			return iterator( upper_boundReq( _root, key ), _root );
		}


		//OBSERVERS
		key_compare key_comp() const{
			return _comp;
		}
		
		value_compare value_comp() const{
			return value_compare( _comp );
		}

		

	};

	//compare
	//==
	template< class Key, class T, class Compare, class Allocator >
		bool operator==( const ft::map<Key, T, Compare, Allocator>& lhs,
			const ft::map<Key, T, Compare, Allocator>& rhs ) {
			return lhs.size() == rhs.size() && \
				ft::equal( lhs.begin(), lhs.end(), rhs.begin() ) && \
				ft::equal( rhs.begin(), rhs.end(), lhs.begin() );
		}
	//!=
	template< class Key, class T, class Compare, class Allocator >
	bool operator!=( const ft::map<Key, T, Compare, Allocator>& lhs,
		const ft::map<Key, T, Compare, Allocator>& rhs ) {
		return !( lhs == rhs );
	}
	//<
	template< class Key, class T, class Compare, class Allocator >
	bool operator<( const ft::map<Key, T, Compare, Allocator>& lhs,
		const ft::map<Key, T, Compare, Allocator>& rhs ) {
		return ft::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() ) && \
			lhs != rhs;
	}
	//<=
	template< class Key, class T, class Compare, class Allocator >
	bool operator<=( const ft::map<Key, T, Compare, Allocator > &lhs,
		const ft::map<Key, T, Compare, Allocator>& rhs ) {
		return lhs < rhs || lhs == rhs;
	}
	//>
	template< class Key, class T, class Compare, class Allocator >
	bool operator>( const ft::map<Key, T, Compare, Allocator>& lhs,
		const ft::map<Key, T, Compare, Allocator>& rhs ) {
		return !ft::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() ) && \
			lhs != rhs;
	}
	//>=
	template< class Key, class T, class Compare, class Allocator >
	bool operator>=( const ft::map<Key, T, Compare, Allocator>& lhs,
		const ft::map<Key, T, Compare, Allocator>& rhs ) {
		return lhs > rhs || lhs == rhs;
	}


	//ft::swap
	template< class Key, class T, class Compare, class Allocator >
	void swap( ft::map<Key, T, Compare, Allocator>& a, ft::map<Key, T, Compare, Allocator>& b ) {
		a.swap( b );
	}
}

