/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)
 * Actual space required by the tree = 2*2^ceil(log_2(n)) - 1
 */

vi arr, st, lazy;

/**
 * Build and init tree
 */
void build(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
        st[node] = arr[a]; // Init value
		return;
	}
	
	build(node*2, a, (a+b)/2); // Init left child
	build(node*2+1, 1+(a+b)/2, b); // Init right child
	
	st[node] = max(st[node*2], st[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update(int node, int a, int b, int i, int j, int value) {
  
  	if(lazy[node] != 0) { // This node needs to be updated
   		st[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
            lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >= i && b <= j) { // Segment is fully within range
    		st[node] += value;

		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

        return;
	}

	update(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	st[node] = max(st[node*2], st[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return -oo; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		st[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return st[node];

	int q1 = query(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = max(q1, q2); // Return final result
	
	return res;
}

int main() {
    
    int n = 10; //size of array
    arr.resize(n);
	
    for(int i = 0; i < n; i++) arr[i] = 1; //all elements set to 1

    lazy.assign(4*n, 0);
    st.resize(4*n);
    
	build(1, 0, n-1); //(node, left, right)

	update(1, 0, n-1, 0, 6, 5); // Increment range [0, 6] by 5. here 0, n-1 represents the current range.
	update(1, 0, n-1, 7, 9, 8); // Incremenet range [7, 10] by 8. here 0, n-1 represents the current range.

	cout << query(1, 0, n-1, 0, n-1) << endl; // Get max element in range [0, N-1]
}
