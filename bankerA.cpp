#include <iostream>

const int P = 5; //num of processes
const int R = 3; //num of resources

bool isSafe(int proc[], int max[][R], int alloc[][R], int avail[]) {

    int need[P][R]; // Prepping need array

    // Calculating need 
    for (int i = 0 ; i < P ; i++)
        for (int j = 0 ; j < R ; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    bool done[P] = {false}; // Mark all processes as not finished
    int safeSeq[P]; // Store safe sequence
    int work[R]; // Work array

    for (int i = 0; i < R; i++)
        work[i] = avail[i]; // Initialize work as available resources

    int count = 0; // Count of processes in safe sequence
    
    while (count < P) { // While all processes are not finished
        bool found = false; // Flag to check if process is found
        for (int p = 0; p < P; p++) { // Check each process
            if (!done[p]) { // If process is not finished
                int j;
                for (j = 0; j < R; j++) // Check if need <= work
                    if (need[p][j] > work[j])
                        break;

                if (j == R) { // If all resources are less than or equal to work
                    for (int k = 0 ; k < R ; k++)
                        work[k] += alloc[p][k]; // Add allocated resources to work
                    safeSeq[count++] = p; // Add process to safe sequence
                    done[p] = true; // Mark process as finished
                    found = true; // Process is found
                }
            }
        }
        if (!found) { // If no process is found, system is not in a safe state
            return false;
        }
    }

    // If we reach here, then the system is in a safe state
    std::cout << "Safe sequence is: ";
    for (int i = 0; i < P; i++)
        std::cout << safeSeq[i] << " ";
    std::cout << std::endl;

    return true;
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

    isSafe(proc, max, alloc, avail);
    
    return 0;

}
