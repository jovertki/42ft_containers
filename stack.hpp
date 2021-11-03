#include "vector.hpp"


namespace ft{
	template<
		class T,
		class Container = ft::vector<T>
	> class stack {
	private:
		friend bool ft::operator==( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs );
		friend bool ft::operator!=( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs );
		friend bool ft::operator<( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs );
		friend bool ft::operator<=( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs );
		friend bool ft::operator>( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs );
		friend bool ft::operator>=( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs );
	protected:
		Container _data;
	public:
		typedef Container	container_type;
		typedef typename Container::value_type			value_type;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;

		explicit stack( const Container& cont = Container() ) : _data( cont ) {}
		stack( stack const& a ) : _data( a._data ) {}

		virtual ~stack() {}

		stack& operator==( stack const& a ) {
			if(this != &a) {
				_data = a._data;
			}
			return *this;
		}

		reference top() {
			return _data.back();
		}
		const_reference top() const {
			return _data.back();
		}


		bool empty() const {
			return _data.empty();
		}

		size_type size() const {
			return _data.size();
		}

		void push( const value_type& value ) {
			_data.push_back( value );
		}

		void pop() {
			_data.pop_back();
		}

		
	};
		//compare
		//==
		template <class T,class Container>
		bool operator==( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs ) {
			return lhs._data == rhs._data;
		}
		
		//!=
		template <class T, class Container>
		bool operator!=( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs ) {
			return lhs._data != rhs._data;
		}
		//<
		template <class T, class Container>
		bool operator<( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs ) {
			return lhs._data < rhs._data;
		}
		//<=
		template <class T, class Container>
		bool operator<=( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs ) {
			return lhs._data <= rhs._data;
		}
		//>
		template <class T, class Container>
		bool operator>( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs ) {
			return lhs._data > rhs._data;
		}
		//>=
		template <class T, class Container>
		bool operator>=( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs ) {
			return lhs._data >= rhs._data;
		}
}