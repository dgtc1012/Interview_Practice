/*
Find Kth permutation
    Given a set of ‘n’ elements, find their Kth permutation.
*/

int factorial(int n){
    if(n == 0 || n == 1) return 1;
    return n * factorial(n-1);
}

void find_kth_permutation(vector<char>& v, int k, string& result) {
    //TODO: Write - Your - Code
    if(v.empty()){
        return;
    }
    int n = (int)(v.size());
    //number of possible permutations
    int count = factorial(n - 1);
    int selected = (k-1)/count;
    
    result += v[selected];
    v.erase(v.begin() + selected);
    
    k = k - (count * selected);
    find_kth_permutation(v, k, result);
}