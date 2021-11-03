namespace ft {
	template <class value_type>
	class treeNode {
	public:
		value_type value;
		treeNode* right;
		treeNode* left;
		treeNode* parent;
		treeNode( const value_type& value, treeNode* right = NULL, treeNode* left = NULL, treeNode* parent = NULL ) : value( value ), right( right ), left( left ), parent( parent ) {}
	};
}