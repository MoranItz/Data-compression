import heapq

class Node:
    def __init__(self, frequency, index, left=None, right=None):
        self.frequency = frequency
        self.index = index
        self.left = left
        self.right = right

def main():
    file_data = ""
    frequency_list = []
    frequency_minheap = []
    keys_dict = {}
    encoded_file = []
    
    file_data = get_string_data()
    frequency_list = get_frequency(file_data)
    keys_dict = get_huffman_encoding(frequency_list)
    encoded_file = encode(keys_dict, file_data)

    for letter in encoded_file:
        print(letter, end=" ")


def get_string_data(): # temporary
    return input("Enter the string data:\n")

# - get_data(file_path)
# This function gets a file path, it then proceeds to open it and read the data and returns it
# Input : file_path - str
# Output: file_data - str
def get_data(file_path):
    pass

# - get_frequency(file_data)
# This function gets file data for a file then it proceeds to create a dictionary for each letter by its frequency
# inside the file (frequency - amount of times that the letter has shown up)
# The function returns the dict with the apperance of every letter and how many times it has shown up as its value.
# Input : file_data - str
# Output : frequency_dict - dictionary
def get_frequency(file_data):
    frequency_dict = {}
    sorted_frequency_list = []
    
    for letter in file_data:
        if letter in frequency_dict:
            frequency_dict[letter] += 1
        else:
            frequency_dict[letter] = 1
    for letter, frequency in sorted(frequency_dict.items(), key=lambda item: item[1]):
        sorted_frequency_list.append([letter, frequency])
    return sorted_frequency_list

# - encode_letters(root, carried_code, encoded_file)
# This function gets the root of the tree, the carried code(0 or 1) and a pointer to a list which will server
# as a list to hold all of the codes for all of the letters in the file.
# The function itself goes over all of the letters in the tree and gives each one its own code and adds that code into encoded_file
# which will hold them in order of most frequent letters to the smallest frequency.
# Input : root - Node, carried_code - str, encoded_file - list
# Output : None
def encode_letters(root, carried_code, encoded_file):
    if root is None:
        return

    if root.left is None and root.right is None:
        if carried_code == "":
            carried_code = "0"
        encoded_file.append(carried_code)
        return

    encode_letters(root.left, carried_code + '0', encoded_file)
    encode_letters(root.right, carried_code + '1', encoded_file)

# get_huffman_encoding(frequency_list)
# This function gets a frequency list which holds lists of 2 items each, the letter in index 0 and the frequency in index 1.
# The function itself creates a binary huffman tree and then calls the function "encode_letters" to traverse the tree and give codes
# to each letter that shows up in the file.
# afterwords the function returns a dictionary of all of the letters and as their value their code.
# Input : frequency_list - 2D list
# Output : keys_dict - dictionary
def get_huffman_encoding(frequency_list):
    keys_dict = {}
    encoded_file = []
    min_heap = []

    for i in range(len(frequency_list)):
        temp_node = Node(frequency_list[i][1], i)
        heapq.heappush(min_heap, (temp_node.frequency, temp_node.index, temp_node))

    if len(frequency_list) == 1 and frequency_list[0][1] == 1:
        return ["0"]

    while len(min_heap) >= 2:

        freq_left, indx_left, left = heapq.heappop(min_heap) # Left node
        freq_right, indx_right, right = heapq.heappop(min_heap) # Right node

        newNode = Node(left.frequency + right.frequency, min(left.index, right.index), left, right) # Creates a new node with both of the frequencies
        heapq.heappush(min_heap, (newNode.frequency, newNode.index, newNode)) # Pushes the new node inside the heap

    root = min_heap[0][2] # The first index is 0, and the second index (2) is the node itself (the root)
    encode_letters(root, "", encoded_file)
    for i in range(len(frequency_list)):
        keys_dict[frequency_list[i][0]] = encoded_file[i]
    return keys_dict

# - encode(keys_dict, file_data)
# This function gets a dictionary of all of the letters that appear in the file data
# and it goes over all of the file data and assign to each letter in it its code from the huffman tree.
# The function returns the encoded file with all of the codes themselves.
# Input : keys_dict - dictionary, file_data - str
# Output : encoded_file - str
def encode(keys_dict, file_data):
    encoded_file = []

    for letter in file_data:
        encoded_file.append(keys_dict[letter])
    return encoded_file















if __name__ == "__main__":
    main()