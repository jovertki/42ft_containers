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
		Container c;
	public:
		typedef Container	container_type;
		typedef typename Container::value_type			value_type;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;

		explicit stack( const Container& cont = Container() ) : c( cont ) {}
		stack( stack const& a ) : c( a.c ) {}

		virtual ~stack() {}

		stack& operator==( stack const& a ) {
			if(this != &a) {
				c = a.c;
			}
			return *this;
		}

		reference top() {
			return c.back();
		}
		const_reference top() const {
			return c.back();
		}


		bool empty() const {
			return c.empty();
		}

		size_type size() const {
			return c.size();
		}

		void push( const value_type& value ) {
			c.push_back( value );
		}

		void pop() {
			c.pop_back();
		}

		
	};
		//compare
		//==
		template <class T,class Container>
		bool operator==( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs ) {
			return lhs.c == rhs.c;
		}
		
		//!=
		template <class T, class Container>
		bool operator!=( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs ) {
			return lhs.c != rhs.c;
		}
		//<
		template <class T, class Container>
		bool operator<( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs ) {
			return lhs.c < rhs.c;
		}
		//<=
		template <class T, class Container>
		bool operator<=( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs ) {
			return lhs.c <= rhs.c;
		}
		//>
		template <class T, class Container>
		bool operator>( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs ) {
			return lhs.c > rhs.c;
		}
		//>=
		template <class T, class Container>
		bool operator>=( const ft::stack<T, Container>& lhs,
			const ft::stack<T, Container>& rhs ) {
			return lhs.c >= rhs.c;
		}
}