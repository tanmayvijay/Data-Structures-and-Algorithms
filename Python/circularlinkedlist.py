class Node:  
      
    def __init__(self, data):  
        self.data = data  
        self.prev = None
        self.next = None
  
# Utility function to create 
# a node in memory 
def getNode(): 
  
    return (Node(0)) 
  
# Function to display the list 
def displayList(temp): 
  
    t = temp 
    if (temp == None): 
        return 0
    else : 
        print("The list is: ", end = " ") 
  
        while (temp.next != t):  
            print( temp.data, end = " ") 
            temp = temp.next
          
        print(temp.data ) 
  
        return 1
  
# Function to count nunmber of 
# elements in the list 
def countList( start): 
  
    # Declare temp pointer to 
    # traverse the list 
    temp = start 
  
    # Variable to store the count 
    count = 0
  
    # Iterate the list and increment the count 
    while (temp.next != start) : 
        temp = temp.next
        count = count + 1
  
    # As the list is circular, increment the 
    # counter at last 
    count = count + 1
  
    return count 
  
# Function to insert a node at a given position 
# in the circular doubly linked list 
def insertAtLocation(start, data, loc): 
  
    # Declare two pointers 
    temp = None
    newNode = None
    i = 0
    count = 0
  
    # Create a new node in memory 
    newNode = getNode() 
  
    # Point temp to start 
    temp = start 
  
    # count of total elements in the list 
    count = countList(start) 
  
    # If list is empty or the position is 
    # not valid, return False 
    if (temp == None or count < loc): 
        return start 
  
    else : 
          
        # Assign the data 
        newNode.data = data 
  
        # Iterate till the loc 
        i = 1; 
        while(i < loc - 1) : 
            temp = temp.next
            i = i + 1
  
        # See in Image, circle 1 
        newNode.next = temp.next
  
        # See in Image, Circle 2 
        (temp.next).prev = newNode 
  
        # See in Image, Circle 3 
        temp.next = newNode 
  
        # See in Image, Circle 4 
        newNode.prev = temp 
  
        return start 
      
    return start 
  
# Function to create circular  
# doubly linked list from array elements 
def createList(arr, n, start): 
  
    # Declare newNode and temporary pointer 
    newNode = None
    temp = None
    i = 0
  
    # Iterate the loop until array length 
    while (i < n) : 
          
        # Create new node 
        newNode = getNode() 
  
        # Assign the array data 
        newNode.data = arr[i] 
  
        # If it is first element 
        # Put that node prev and next as start 
        # as it is circular 
        if (i == 0) : 
            start = newNode 
            newNode.prev = start 
            newNode.next = start 
          
        else : 
              
            # Find the last node 
            temp = (start).prev 
  
            # Add the last node to make them 
            # in circular fashion 
            temp.next = newNode 
            newNode.next = start 
            newNode.prev = temp 
            temp = start 
            temp.prev = newNode 
        i = i + 1; 
      
    return start 
  
# Driver Code 
if __name__ == "__main__":  
  
    # Array elements to create 
    # circular doubly linked list 
    arr = [ 1, 2, 3, 4, 5, 6]  
    n = len(arr) 
  
    # Start Pointer 
    start = None
  
    # Create the List 
    start = createList(arr, n, start) 
  
    # Display the list before insertion 
    displayList(start) 
  
    # Inserting 8 at 3rd position 
    start = insertAtLocation(start, 8, 3) 
  
    # Display the list after insertion 
    displayList(start) 
      
# This code is contributed by Arnab Kundu 