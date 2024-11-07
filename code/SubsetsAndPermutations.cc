// Find all permutations for a vector or all possible subsets of a set
int main() {
    int n; // Size of the vector
    // Permutations
    vector<int> permutation;
    for (int i = 0; i < n; i++) {
        permutation.push_back(i);
    }
    do {
        // process permutation
    } while (next_permutation(permutation.begin(),permutation.end()));

    // Subsets
    for (int b = 0; b < (1<<n); b++) {
        // Process subset, using the binary representation of b
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (b&(1<<i)) subset.push_back(i); // Change i for whatever element[i] that goes in the subset
        }
        // process the subset b 
    }
}

