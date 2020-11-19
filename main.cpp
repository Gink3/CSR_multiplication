/*
 *  Taylor King
 *  taylorking5@my.unt.edu
 *  Sparse vector multiplication with CSR compression formatted matrix
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]) {

    //number of elements
    int ne = 4;

    //inital csr arrays
    int v[4] = {1, 5, 6, 2};
    int col[4] = {0, 1, 2, 2};
    int r[5] = {0, 0, 1, 3, 4};

    //handles command line arguements
    if(argc < 1) {
        printf("Too few arguements supplied\n");
        printf("Usage ./a.out <debug>\n");
        return -1;
    } else if (argc > 2) {
        printf("Too many arguements supplied\n");
        printf("Usage ./a.out <debug>\n");
        return -1;
    } 


    int x[3] = {1, 2, 3};

    //sets debug print statements
    bool debug;
    if(argc == 2) {
        const char *flag = argv[2];
        const char *debug_flag = "-d";
       
        if(strcmp(flag, debug_flag) == 0) {
            debug = true;
        }
    } else {
        debug = false;
    }
    /*
    * Sparse matrix vector multiplication
    *  
    * 
    * 
    * 
    * 
    * 
    */
    int result[4] = {0,0,0,0};
    //ep elements processed
    int ep = 0;
    for(int row = 0; row<ne;row++) {
        int nze = r[row+1] - r[row];    //calculates number of nonzero elements
        if(debug) {
            printf("nze: %d\n",nze);
        }
        //loops through the non zero elements in the row
        int sum = 0;
        for(int ele=0;ele<nze;ele++) {
            //calculates index of curent element
            int index = ele+ep;
            if(debug) {
                printf("v[index]:%d * x[col[index]]:%d = %d \n",v[index], x[col[index]], v[index] * x[col[index]]);
            }
            sum += v[index] * x[col[index]];
        }
        //increments elements processed by the number of non zero elements in the roow
        ep+=nze;
        result[row]=sum;
    }
    //prints the output of the SPMV
    for(int i = 0; i< 4;i++) {
        printf("result[%d] = %d \n", i, result[i]);
    }

}

