
// function to swap elements
void swapElements(int array[], int i, int j){
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// function to sort 3 elements
void sort3(int array[], int first, int second, int third){
    if(array[second] < array[first]){
        swapElements(array, second, first);
    }
    if(array[third] < array[first]){
        swapElements(array, third, first);
    }
    if(array[third] < array[second]){
        swapElements(array, third, second);
    }
}

//Quick Sort Function
void quickSort(int array[], int left, int right){
    int middle = (left+right)/2;
    sort3(array,left,middle,right);

    if(right-left >= 3){
        int i = left, j = right;
        while (i<j)
        {
            do
            {
                i++;
            } while (array[i]<=array[middle]);
            do
            {
                j--;
            } while (array[j]>=array[middle]);
            
            if (i<j)
            {
                swapElements(array,i,j);
            }
            
        }

        int temp;
        if (i<middle && j<middle)
        {
            temp = i;
        }
        else if (i>middle && j>middle)
        {
            temp = j;
        }
        else{
            temp = middle;
        } 
        swapElements(array,temp,middle);
        quickSort(array,left,temp-1);
        quickSort(array,temp+1,right);
        
    }
}