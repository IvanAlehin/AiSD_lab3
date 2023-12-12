
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


}
