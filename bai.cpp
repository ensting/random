#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std::chrono;
using namespace std;
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
};
//-----------------------------------
void bubble_sort(int a[], int n, FILE *outfile)
{
    //  for (int i = 0; i < n; i++){
    //     cout <<a[i]<<" ";
    // }
    auto start = high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[i])
            {
                swap(a[j], a[i]);
            }
        }
    }
    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    cout << endl
         << "bubble sort thgian chay: " << elapsed.count() << "s" << endl;
    for (int i = 0; i < n; i++)
    {
        fprintf(outfile, "%d ", a[i]);
    }
};
//------------------------------------------
void selection_sort(int a[], int n, FILE *outfile)
{
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a[min], a[i]);
    }
    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    cout << endl
         << "selection sort thgian chay: " << elapsed.count() << "s" << endl;
    for (int i = 0; i < n; i++)
        fprintf(outfile, "%d ", a[i]);
};
//-------------------------------
void insertion_sort(int a[], int n, FILE *outfile)
{
    int pos, temp;
    auto start = high_resolution_clock::now();
    for (int i = 1; i < n; i++)
    {
        temp = a[i];
        pos = i;
        while (pos > 0 && temp < a[pos - 1])
        {
            a[pos] = a[pos - 1];
            pos--;
        };
        a[pos] = temp;
    }
    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    cout << endl
         << "insertion sort thgian chay: " << elapsed.count() << "s" << endl;
    for (int i = 0; i < n; i++)
        fprintf(outfile, "%d ", a[i]);
}
int main()
{
    FILE *infile;
    FILE *outfile;
    infile = fopen("file.inp", "r");
    outfile = fopen("file.out", "w");

    int n;
    fscanf(infile, "%d \n", &n);
    int *a = new int[n];
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(infile, "%d ", &a[i]);
    }

    cout << "n= " << n;
    // for (int i=0;i<n;i++){
    //     cout <<a[i]<<" ";
    // }
    fprintf(outfile, "%d \n", n);
    copy(a, a + n, temp);
    insertion_sort(temp, n, outfile);
    copy(a, a + n, temp);
    selection_sort(temp, n, outfile);
    copy(a, a + n, temp);
    bubble_sort(temp, n, outfile);

    return 0;
}