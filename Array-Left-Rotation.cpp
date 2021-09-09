vector<int> rotLeft(vector<int> a, int d) {
    int r = 0 ; 
    vector<int> result ;
    if (a.size() <= d )
    {
        r = d ;
    }
    else 
    {
        r = d % a.size();
    }
    for (int i = r ; i < a.size() ; i++) {
    result.push_back(a[i]);
    }
    for (int j = 0 ; j < r; j++) {
    result.push_back(a[j]);
    }
    return result;
}
