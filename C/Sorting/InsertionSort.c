void insertSort(int array[], int n){
    int i,j,temp;

    for (int i = 1; i < n; i++)
    {
        temp = array[i];
        j=i-1;

        while (j>=0 && temp < array[j])
        {
            array[j+1] = array[j];
            j--;
        }
       array[j+1] = temp ;
    }
}