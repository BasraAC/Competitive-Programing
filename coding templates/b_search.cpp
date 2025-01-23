

const int n = 100;
int array[n];


void bsearch(){

    int a = 0;
    int b = n-1;
    int x = 10;
    
    while (a <= b) {
        int k = (a+b)/2;
        if (array[k] == x) {
        // x found at index k
        }
        if (array[k] > x) b = k-1;
        else a = k+1;
    }
}

