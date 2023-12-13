
#include <iostream>
#include "Sort/Sort.cpp"

using namespace std;

int main() {

    const int num_vec = 100;
    const vector<size_t> vec_lengths = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000 };
    
    for (size_t len : vec_lengths) {

        stats bubble_random_stat{ 0, 0 };
        stats bubble_sorted_stat{ 0, 0 };
        stats bubble_reverse_sorted_stat{ 0, 0 };
        
        stats shell_random_stat{ 0, 0 };
        stats shell_sorted_stat{ 0, 0 };
        stats shell_reverse_sorted_stat{ 0, 0 };

        stats heap_random_stat{ 0, 0 };
        stats heap_sorted_stat{ 0, 0 };
        stats heap_reverse_sorted_stat{ 0, 0 };

        for (int i = 0; i < num_vec; ++i) {

            vector<int> random_vector = RandomVec<int>(len);

            vector<int> bubble_random_vector = random_vector;

            stats bubble_stat = BubbleSort(bubble_random_vector);
            bubble_random_stat.comparison_count += bubble_stat.comparison_count;
            bubble_random_stat.copy_count += bubble_stat.copy_count;

            vector<int> shell_random_vector = random_vector;

            stats shell_stat = ShellSort(shell_random_vector);
            shell_random_stat.comparison_count += shell_stat.comparison_count;
            shell_random_stat.copy_count += shell_stat.copy_count;

            vector<int> heap_random_vector = random_vector;

            stats heap_stat = HeapSort(heap_random_vector);
            heap_random_stat.comparison_count += heap_stat.comparison_count;
            heap_random_stat.copy_count += heap_stat.copy_count;

        }
  
        stats bubble_random_average_stats{
            bubble_random_stat.comparison_count / num_vec,
            bubble_random_stat.copy_count / num_vec
        };
        
        stats shell_random_average_stats{
            shell_random_stat.comparison_count / num_vec,
            shell_random_stat.copy_count / num_vec
        };

        stats heap_random_average_stats{
            heap_random_stat.comparison_count / num_vec,
            heap_random_stat.copy_count / num_vec
        };
        

        vector<int> sorted_vector = SortedVec<int>(len);

        vector<int> bubble_sorted_vector = sorted_vector;
        stats bubble_sorted_stats = BubbleSort(bubble_sorted_vector);
        bubble_sorted_stat.comparison_count += bubble_sorted_stats.comparison_count;
        bubble_sorted_stat.copy_count += bubble_sorted_stats.copy_count;

        vector<int> shell_sorted_vector = sorted_vector;
        stats shell_sorted_stats = ShellSort(shell_sorted_vector);
        shell_sorted_stat.comparison_count += shell_sorted_stats.comparison_count;
        shell_sorted_stat.copy_count += shell_sorted_stats.copy_count;

        vector<int> heap_sorted_vector = sorted_vector;
        stats heap_sorted_stats = HeapSort(heap_sorted_vector);
        heap_sorted_stat.comparison_count += heap_sorted_stats.comparison_count;
        heap_sorted_stat.copy_count += heap_sorted_stats.copy_count;
        

        vector<int> reverse_sorted_vector = ReverseSortedVec<int>(len);

        vector<int> bubble_reverse_sorted_vector = reverse_sorted_vector;
        stats bubble_reverse_sorted_stats = BubbleSort(bubble_reverse_sorted_vector);
        bubble_reverse_sorted_stat.comparison_count += bubble_reverse_sorted_stats.comparison_count;
        bubble_reverse_sorted_stat.copy_count += bubble_reverse_sorted_stats.copy_count;
        
        
        vector<int> shell_reverse_sorted_vector = reverse_sorted_vector;
        stats shell_reverse_sorted_stats = ShellSort(shell_reverse_sorted_vector);
        shell_reverse_sorted_stat.comparison_count += shell_reverse_sorted_stats.comparison_count;
        shell_reverse_sorted_stat.copy_count += shell_reverse_sorted_stats.copy_count;

        vector<int> heap_reverse_sorted_vector = reverse_sorted_vector;
        stats heap_reverse_sorted_stats = HeapSort(heap_reverse_sorted_vector);
        heap_reverse_sorted_stat.comparison_count += heap_reverse_sorted_stats.comparison_count;
        heap_reverse_sorted_stat.copy_count += heap_reverse_sorted_stats.copy_count;
        

        
        cout << "Vector Length: " << len << endl;
        cout << endl;
        cout << "Random Vectors - Bubble Sort Average Stats:"<<endl;
        cout << "   Comparisons: " << bubble_random_average_stats.comparison_count << endl;
        cout << "   Copies: " << bubble_random_average_stats.copy_count << endl;
        cout << endl;

        cout << "Sorted Vector - Bubble Sort Stats:" << endl;
        cout << "   Comparisons: " << bubble_sorted_stat.comparison_count << endl;
        cout << "   Copies: " << bubble_sorted_stat.copy_count << endl;
        cout << endl;

        cout << "Reverse Sorted Vector - Bubble Sort Stats:" << endl;
        cout << "   Comparisons: " << bubble_reverse_sorted_stat.comparison_count << endl;
        cout << "   Copies: " << bubble_reverse_sorted_stat.copy_count << endl;
        cout << endl;
        
        

        cout << "Random Vectors - Shell Sort Average Stats:" << endl;
        cout << "   Comparisons: " << shell_random_average_stats.comparison_count << endl;
        cout << "   Copies: " << shell_random_average_stats.copy_count << endl;
        cout << endl;

        cout << "Sorted Vector - Shell Sort Stats:" << endl;
        cout << "   Comparisons: " << shell_sorted_stat.comparison_count << endl;
        cout << "   Copies: " << shell_sorted_stat.copy_count << endl;
        cout << endl;

        cout << "Reverse Sorted Vector - Shell Sort Stats:"<<endl;
        cout << "   Comparisons: " << shell_reverse_sorted_stat.comparison_count << endl;
        cout << "   Copies: " << shell_reverse_sorted_stat.copy_count << endl;
        cout << endl;
        


        cout << "Random Vectors - Heap Sort Average Stats:" << endl;
        cout << "   Comparisons: " << heap_random_average_stats.comparison_count << endl;
        cout << "   Copies: " << heap_random_average_stats.copy_count << endl;
        cout << endl;

        cout << "Sorted Vector - Heap Sort Stats:" << endl;
        cout << "   Comparisons: " << heap_sorted_stat.comparison_count << endl;
        cout << "   Copies: " << heap_sorted_stat.copy_count << endl;
        cout << endl;

        cout << "Reverse Sorted Vector - Heap Sort Stats:" << endl;
        cout << "   Comparisons: " << heap_reverse_sorted_stat.comparison_count << endl;
        cout << "   Copies: " << heap_reverse_sorted_stat.copy_count << endl;
        cout << endl;
        cout << endl;
    }



    vector<string> v1s = { "q", "w", "e" , "e", "d", "g" , "x", "z", "h", "n", "k", "t", "a", "t", "l" , "u", "j", "f" };
    vector<string> v2s = { "q", "w", "e" , "e", "d", "g" , "x", "z", "h", "n", "k", "t", "a", "t", "l" , "u", "j", "f" };
    vector<string> v3s = { "q", "w", "e" , "e", "d", "g" , "x", "z", "h", "n", "k", "t", "a", "t", "l" , "u", "j", "f" };

    cout << "Vector Before Sorting: " << endl;
    PrintVec(v1s);
    stats statistics1 = BubbleSort(v1s);
    cout << "Vector After Bubble Sorting: " << endl;
    PrintVec(v1s);
    cout << "Bubble Sorting Comparison Count: " << statistics1.comparison_count << endl;
    cout << "Bubble Sorting Copy Count: " << statistics1.copy_count << endl << endl;

    cout << "Vector Before Sorting: " << endl;
    PrintVec(v2s);
    stats statistics2 = ShellSort(v2s);
    cout << "Vector After Shell Sorting: " << endl;
    PrintVec(v1s);
    cout << "Shell Sorting Comparison Count: " << statistics2.comparison_count << endl;
    cout << "Shell Sorting Copy Count: " << statistics2.copy_count << endl << endl;

    cout << "Vector Before Sorting: " << endl;
    PrintVec(v3s);
    stats statistics3 = HeapSort(v3s);
    cout << "Vector After Heap Sorting: " << endl;
    PrintVec(v3s);
    cout << "Heap Sorting Comparison Count: " << statistics3.comparison_count << endl;
    cout << "Heap Sorting Copy Count: " << statistics3.copy_count << endl << endl;




    vector<MyClass> v1;
    vector<MyClass> v2;
    vector<MyClass> v3;

    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < 50; ++i) {
        v1.push_back(rand() % 100);
    }

    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < 50; ++i) {
        v2.push_back(rand() % 100);
    }

    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < 50; ++i) {
        v3.push_back(rand() % 100);
    }


    cout << "Vector Before Sorting: " << endl;
    for (const auto& obj : v1) {
        cout << obj.get_value() << " ";
    }

    stats statistics4 = BubbleSort(v1);
    cout << endl;
    cout << "Vector After Bubble Sorting: " << endl;
    for (const auto& obj : v1) {
        cout << obj.get_value() << " ";
    }
    cout << endl;
    cout << "Bubble Sorting Comparison Count: " << statistics4.comparison_count << endl;
    cout << "Bubble Sorting Copy Count: " << statistics4.copy_count << endl << endl;


    cout << "Vector Before Sorting: " << endl;
    for (const auto& obj : v2) {
        cout << obj.get_value() << " ";
    }

    stats statistics5 = ShellSort(v2);
    cout << endl;
    cout << "Vector After Shell Sorting: " << endl;
    for (const auto& obj : v2) {
        cout << obj.get_value() << " ";
    }
    cout << endl;
    cout << "Shell Sorting Comparison Count: " << statistics5.comparison_count << endl;
    cout << "Shell Sorting Copy Count: " << statistics5.copy_count << endl << endl;


    cout << "Vector Before Sorting: " << endl;
    for (const auto& obj : v3) {
        cout << obj.get_value() << " ";
    }

    stats statistics6 = HeapSort(v3);
    cout << endl;
    cout << "Vector After Heap Sorting: " << endl;
    for (const auto& obj : v3) {
        cout << obj.get_value() << " ";
    }
    cout << endl;
    cout << "Heap Sorting Comparison Count: " << statistics6.comparison_count << endl;
    cout << "Heap Sorting Copy Count: " << statistics6.copy_count << endl << endl;
    return 0;


}
