#include<iostream>
#include<chrono>
#include<algorithm>
#include<cstdlib>
#include<fstream>
//selection sort
int* selection_sort( int arr[], int size)
{
    int min_index, count = 0;
    for (int i = 0; i < size - 1; i++)
    {
        min_index = i;
        count = 0;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
                count = 1;
            }
        }
        if (count == 1)
        {
            std::swap(arr[min_index], arr[i]);
        }
    }
    return arr;
}


//bubble sort
int* bubble_sort(int arr[], int size)
{
    int flag = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                    flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    return arr;
    /*std::cout << "Bubble sort" << std::endl;
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;*/
}


//insertion sort
int* insertion_sort(int arr[], int size)
{
    int temp,j;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0 && temp < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
    return arr;
}
int main()
{
    int* a=new int[1000000];
    int k = 0;
    long long total = 0,d[10];
    for (int i = 0; i < 1000000; i++)
    {
        a[i] = i + 1;
    }
    while (k < 10)
    {
        std::cout << "hello ";
        auto t1 = std::chrono::high_resolution_clock::now();
        selection_sort(a, 1000000);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        std::cout << "Selection sort ";
        std::cout << duration << std::endl;
        total += duration;
        k++;        
    }
   delete[] a;
   total = total / 10;
    std::ofstream out("data.csv",std::ios::app);
   out << "Alogrithm,ArraySize,ArrayType,Number of runs,Average time taken" << std::endl;
    out << "Selection sort,1000000,sorted,10," << total << std::endl;
    out.close();
    /* t1 = std::chrono::high_resolution_clock::now();
     bubble_sort(a, 6);
     t2 = std::chrono::high_resolution_clock::now();
     duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
     //std::cout << "Bubble sort ";
     //std::cout << duration << std::endl;
     t1 = std::chrono::high_resolution_clock::now();
     insertion_sort(a, 6);
     t2 = std::chrono::high_resolution_clock::now();
     duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
     std::cout << "Insertion sort ";
     std::cout << duration << std::endl;*/
}

