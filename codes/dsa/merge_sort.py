"""
    Merge sort is a divide and conquer algorithm that was invented by John von Neumann in 1945.
    It is an efficient, stable, comparison-based sorting algorithm.
"""





def merge_sort(list):
    """
    Sorts a list in ascending order
    Returns a new sorted list
    
    Divide: Find the midpoint of the list and divide into sublists
    Conquer: Recursively sort the sublists created in previous step
    Combine: Merge the sorted sublists created in previous step
    
    Takes O(kn log n) time complexity
    """
    
    if len(list) <= 1:
        return list
    
    left_half, right_half = split(list)
    left = merge_sort(left_half)
    right = merge_sort(right_half)
    
    return merge(left,right)
    
    
def split(list):
    """
    Divide the unsorted list at midpoint into sublists
    Returns two sublists - left and right
    Takes overall O(log n) time complexity
    """
    mid = len(list)//2
    left = list[:mid] # from start to mid
    right = list[mid:] # from mid to end
    
    return left, right
    
def merge(left,right):
    """
    Merges two lists (arrays), sorting them in the process
    Returns a new merged list
    
    """
    l=[]
    i=0
    j=0
    
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            l.append(left[i])
            i += 1
        else:
            l.append(right[j])
            j += 1
            
    while i < len(left):
        l.append(left[i])
        i += 1 
        
    while j < len(right):
        l.append(right[j])
        j+=1
        
    return l

def verify_sorted(list):
    n=len(list) 
    
    
    if n==0 or n==1:
        return True
    
    return list[0]<list[1] and verify_sorted(list[1:])



list=[10,3,4,2,1,5,23,6,7,8,9,0]
print(list)
print(verify_sorted(list))
    
l  = merge_sort(list)
print(l)
print(verify_sorted(l))