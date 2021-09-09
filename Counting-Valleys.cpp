int countingValleys(int steps, string path) {
   int counter = 0;
   int result = 0 ;
   int arr[path.length()];
    for (int i = 0 ; i < path.length(); i++) {
        if(path[i] == 'D')
        {
            counter--;
        }else {
            counter++;
        }
        arr[i] = counter ;
    }   
    for (int j =1; j <path.length(); j++)
    {
        if (arr[j] == 0 && arr[j-1] == -1) {
        result++;
        }
    }
    return result;
}
