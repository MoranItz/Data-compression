import heapq



def main():
    file_data = ""
    frequency_dict = {}
    frequency_minheap = []
    
    


def get_string_data(string_data): # temporary
    pass

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
    pass

# - build_minheap(frequency_dict)
# This function get a dict with all of the letters that have shown up in the file data as a key and the frequency they showed up
# as the keys value.
# The purpose of this function is to build a min-heap where the letters with the smallest frequency have the biggest priority
# and the letters with the most frequency have the lowest priority (saved as tuples, first value is the letter and second value is the frequency).
# Input : frequency_dict - dictionary
# Output: frequency_minheap - heap
def build_minheap(frequency_dict):
    pass

# - get_huffman_btree(frequency_minheap)
# This function gets a heap of all of the letters and their frequencies as tuples by min-value.
# The function creates a binary huffman tree and returns it.
# Input : frequency_minheap - heap
# Output : huffman_btree - binary tree
def get_huffman_btree(frequency_minheap):
    pass

# - build_code_dict(huffman_btree)
# This function gets a huffman binary tree of all of the letters and their frequencies sorted.
# The function creates the codes for all of the appearing letters inside the file.
# It does this by going either left or right in the binary tree, for each left turn it adds a '0'
# to the code and for each right turn it adds a '1'. the code is decided when after all the turns it reaches a letter.
# Input: huffman_btree - binary tree
# Output: code_dict - dictionary
def build_code_dict(huffman_btree):
    pass

# - encrypt(code_dict):
# This function gets a dictionary of all of the letters appearing in the file data as keys and their code as values,
# aswell as the file data itself.
# The function goes over the file data and for each letter insted inserts the code for that letter.
# Input : code_dict - dictionary, file_data - str
# Output: encryped_file - bytestr
def encrypt(code_dict, file_data):
    pass












if __name__ == "__main__":
    main()