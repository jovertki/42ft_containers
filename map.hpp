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
			int balanceFactor;
			int height;
			treeNode( const value_type* value, treeNode* parent = NULL, treeNode* right = NULL, treeNode* left = NULL )
				: value( const_cast<value_type*>(value) ), parent( parent ),
				right( right ), left( left ), balanceFactor( 0 ), height( 0 ) {}
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
		typedef typename Allocator::template rebind<treeNode>::other node_allocator_type;
		node_allocator_type _altn;

		treeNode* getNewNode( const value_type* data, treeNode* parent ) {
			treeNode* node = _altn.allocate( 1 );
			_altn.construct( node, treeNode( data, parent ) );
			return node;
		}


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



		treeNode* upper_boundReq( treeNode* root, const Key& key ) {
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

		treeNode* lower_boundReq( treeNode* root, const Key& key ) {
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
			_altn.destroy( node );
			_altn.deallocate( node, sizeof(treeNode));
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



		//ERASE (1) STUFF BEGIN
		treeNode* succeedWithTwo( const treeNode* node ) {
			treeNode* donor = node->right;
			while(donor->left != NULL)
				donor = donor->left;
			treeNode* successor = _altn.allocate( 1 );
			_altn.construct( successor, treeNode( NULL, node->parent, node->right, node->left ) );
			successor->value = _alloc.allocate( 1 );
			_alloc.construct(successor->value, *donor->value);
			node->right->parent = successor;
			node->left->parent = successor;
			if(node->parent == NULL) {
				_root = successor;
			}
			else if(node->parent->left == node) {
				node->parent->left = successor;
			}
			else if(node->parent->left == node){
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
		treeNode* succeedNodeReq( treeNode* successor, treeNode* node ) {
			if(node->parent->left == node) {
				node->parent->left = successor;
				successor->parent = node->parent;
			}
			else {
				node->parent->right = successor;
				successor->parent = node->parent;
			}
			_alloc.deallocate( node->value, sizeof( value_type ) );
			_altn.destroy( node );
			_altn.deallocate( node, sizeof( treeNode ) );
			return successor;
		}

		treeNode* eraseLeaf( treeNode* node ) {
			treeNode* temp = node->parent;
			if(node->parent != NULL) {
				if(node->parent->left == node) {
					node->parent->left = NULL;
				}
				else {
					node->parent->right = NULL;
				}
			}
			_alloc.deallocate( node->value, sizeof( value_type ) );
			_altn.destroy( node );
			_altn.deallocate( node, sizeof( treeNode ) );
			node = NULL;
			return temp;
		}
		
		treeNode* eraseReq( treeNode* root, treeNode* parent, const Key& key ) {
			_size--;
			if(root == NULL) {
				_size++;
			}
			else if(root->value->first > key) {
				eraseReq( root->left, root, key );
			}
			else if(root->value->first < key) {
				eraseReq( root->right, root, key );
			}
			else if(root->value->first == key) {
				if(!root->right && !root->left) {
					eraseLeaf( root );
					root = NULL;
				}
				else if(root->right && !root->left) {
					succeedNodeReq( root->right, root );
				}
				else if(root->left && !root->right) {
					succeedNodeReq( root->left, root );
				}
				else {
					treeNode* donor = root->right;
					while(donor->left != NULL)
						donor = donor->left;
					_alloc.destroy( root->value );
					//should I really do this this way? it is not really optimal
					_alloc.construct(root->value, *donor->value);
					eraseReq( root->right, root, root->value->first );
				}
			}
			update( root );
			balance( root );
			return root;
		}
	//END OF ERASE (3) STUFF




		
		//erase
		//(1)
		void erase( iterator pos ) {
			//I could find node with pos's value and do erase(3)
			erasePos( pos.getNode() );
			_size--;
		}
		//(2)
		void erase( iterator first, iterator last ) {
			//just call (1)???
			while(first != last) {
				erase( first );
				first++;
			}
		}
		//(3)
		size_type erase( const Key& key ) {
			_root = eraseReq( _root, NULL, key );
			return 1;
		}
		
		//swap


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
			return find( key );
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
			return lower_bound( key );
		}
		//upper_bound
		//(1)
		iterator upper_bound( const Key& key ) {
			return iterator(upper_boundReq( _root, key ), _root);
		}
		//(2)
		const_iterator upper_bound( const Key& key ) const{
			return upper_bound( key );
		}
	};

}
