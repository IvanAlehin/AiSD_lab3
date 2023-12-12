
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


        for (int i = 0; i < num_vec; ++i) {

            vector<int> bubble_random_vector = RandomVec<int>(len);
            stats bubble_stat = BubbleSort(bubble_random_vector);
            bubble_random_stat.comparison_count += bubble_stat.comparison_count;
            bubble_random_stat.copy_count += bubble_stat.copy_count;

        }
  
        stats bubble_random_average_stats{
            bubble_random_stat.comparison_count / num_vec,
            bubble_random_stat.copy_count / num_vec
        };

        vector<int> bubble_sorted_vector = SortedVec<int>(len);

        stats bubble_sorted_stats = BubbleSort(bubble_sorted_vector);
        bubble_sorted_stat.comparison_count += bubble_sorted_stats.comparison_count;
        bubble_sorted_stat.copy_count += bubble_sorted_stats.copy_count;


        vector<int> bubble_reverse_sorted_vector = ReverseSortedVec<int>(len);

        stats bubble_reverse_sorted_stats = BubbleSort(bubble_reverse_sorted_vector);
        bubble_reverse_sorted_stat.comparison_count += bubble_reverse_sorted_stats.comparison_count;
        bubble_reverse_sorted_stat.copy_count += bubble_reverse_sorted_stats.copy_count;
        

        
        cout << "Vector Length: " << len << endl;
        cout << "Random Vectors - Bubble Sort Average Stats:"<<endl;
        cout << "   Comparisons: " << bubble_random_average_stats.comparison_count << endl;
        cout << "   Copies: " << bubble_random_average_stats.copy_count << endl;
        cout << endl;

        cout << "Sorted Vectors - Bubble Sort Average Stats:" << endl;
        cout << "   Comparisons: " << bubble_sorted_stat.comparison_count << endl;
        cout << "   Copies: " << bubble_sorted_stat.copy_count << endl;
        cout << endl;

        cout << "Reverse Sorted Vectors - Bubble Sort Average Stats:" << endl;
        cout << "   Comparisons: " << bubble_reverse_sorted_stat.comparison_count << endl;
        cout << "   Copies: " << bubble_reverse_sorted_stat.copy_count << endl;
        cout << endl;
        
    }


}
