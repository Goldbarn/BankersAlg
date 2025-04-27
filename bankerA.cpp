#include <iostream>

const int P = 5; //num of processes
const int R = 3; //num of resources

bool isSafe(int proc[], int max[][R], int alloc[][R], int avail[]) {

    int need[P][R]; //Preppin need array

    // Calculating need 
    for (int i = 0 ; i < P ; i++)
        for (int j = 0 ; j < R ; j++)

            // Need of instance = maxm instance - allocated instance
            need[i][j] = max[i][j] - alloc[i][j];


    bool done[P] = {false}; // Mark all processes as not finished
    int safeSeq[P]; // Store safe sequence


}

int main() {

    int proc[] = {0, 1, 2, 3, 4};   // Names of processes

    int max[P][R] = {
        {7, 5, 3}, 
        {3, 2, 2}, 
        {9, 0, 2}, 
        {2, 2, 2}, 
        {4, 3, 3} };

    int alloc[P][R] = { 
        {0, 1, 0}, 
        {2, 0, 0}, 
        {3, 0, 2}, 
        {2, 1, 1}, 
        {0, 0, 2} };

    int avail[R] = {3, 3, 2};

    if (isSafe(proc, max, alloc, avail)) { //Check if safe, then return result
        std::cout << "System is in a safe state." << std::endl;
    } else {
        std::cout << "System is not in a safe state." << std::endl;
    }

    return 0;

}
