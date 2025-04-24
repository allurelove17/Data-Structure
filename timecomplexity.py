import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os

# Your CSV files
worst_csv = "sorting_worstcase.csv"
average_csv = "sorting_averagecase.csv"

# Create a function to process each CSV file and generate a graph
def process_and_plot(csv_file, title_prefix):
    if not os.path.exists(csv_file):
        print(f"File not found: {csv_file}")
        return None
    
    try:
        # Read the data
        df = pd.read_csv(csv_file, header=None)
        
        # Assign appropriate column names
        if len(df.columns) >= 5:  # For size + 4 algorithms
            df.columns = ['size', 'insertion', 'quick', 'merge', 'heap'][:len(df.columns)]
        
        print(f"\nFirst few rows of {title_prefix} case data:")
        print(df.head())
        
        # Create the plot (log-log scale)
        plt.figure(figsize=(12, 8))
        
        # Plot each algorithm with correct complexity labels
        plt.loglog(df['size'], df['insertion'], 'o--', color='#FFB000', label='Insertion Sort (O(n²))')
        
        # For worst case, quick sort is O(n²), for average it's O(n log n)
        if title_prefix.lower() == "worst":
            plt.loglog(df['size'], df['quick'], 's--', color='#FF6B00', label='Quick Sort (O(n²))')
        else:
            plt.loglog(df['size'], df['quick'], 's--', color='#FF6B00', label='Quick Sort (O(n log n))')
            
        plt.loglog(df['size'], df['merge'], 'd--', color='#DC267F', label='Merge Sort (O(n log n))')
        plt.loglog(df['size'], df['heap'], 'p--', color='#FE00FE', label='Heap Sort (O(n log n))')
        
        # Add grid and styling
        plt.grid(True, which="both", ls="--", alpha=0.3)
        plt.title(f'Sorting Algorithm {title_prefix} Case Performance Comparison', fontsize=20)
        plt.xlabel('n (Input Size)', fontsize=16)
        plt.ylabel('Time (ms)', fontsize=16)
        plt.legend(fontsize=12)
        
        # Save the figure
        output_file = f'sorting_{title_prefix.lower()}_comparison.png'
        plt.savefig(output_file, dpi=300, bbox_inches='tight')
        print(f"{title_prefix} case graph saved as '{output_file}'")
        
        return df
    except Exception as e:
        print(f"Error processing {title_prefix} case data: {e}")
        return None

# Process each CSV file and generate graphs
worst_df = process_and_plot(worst_csv, "Worst")
average_df = process_and_plot(average_csv, "Average")

# Create a comparison graph for selected algorithms if both datasets are available
if worst_df is not None and average_df is not None:
    try:
        plt.figure(figsize=(12, 8))
        
        # Compare quick sort worst vs average (with correct complexity labels)
        plt.loglog(worst_df['size'], worst_df['quick'], 's--', color='#FF6B00', label='Quick Sort (Worst Case - O(n²))')
        plt.loglog(average_df['size'], average_df['quick'], 's-', color='#AA4400', label='Quick Sort (Average Case - O(n log n))')
        
        # Compare heap sort worst vs average
        plt.loglog(worst_df['size'], worst_df['heap'], 'p--', color='#FE00FE', label='Heap Sort (Worst Case - O(n log n))')
        plt.loglog(average_df['size'], average_df['heap'], 'p-', color='#AA00AA', label='Heap Sort (Average Case - O(n log n))')
        
        # Add grid and styling
        plt.grid(True, which="both", ls="--", alpha=0.3)
        plt.title('Worst vs Average Case Comparison', fontsize=20)
        plt.xlabel('n (Input Size)', fontsize=16)
        plt.ylabel('Time (ms)', fontsize=16)
        plt.legend(fontsize=12)
        
        # Save the figure
        plt.savefig('sorting_comparison_combined.png', dpi=300, bbox_inches='tight')
        print("Combined comparison graph saved as 'sorting_comparison_combined.png'")
        
    except Exception as e:
        print(f"Error creating combined comparison graph: {e}")

# Show all plots at the end
plt.show()