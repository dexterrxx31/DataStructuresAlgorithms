long repeatedString(string s, long n) {
    int num_a , c;
    num_a = 0 ;
    c = 0 ;
    for (int i = 0 ; i < s.size(); i++)
    {
        if (s[i] == 'a') 
        {
            num_a++;
        }
    }
    for (int j = 0 ; j < n % s.size(); j++) {
        if (s[j] == 'a') 
        {
            c++;
        }
    }
