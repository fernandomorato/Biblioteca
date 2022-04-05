#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

// Supports the same operations as the std::set

// find_by_order(k) - Returns an iterator to the k-th largest element (counting from 0)

// order_of_key(x) - Returns the number of items in a set that are strictly smaller than x