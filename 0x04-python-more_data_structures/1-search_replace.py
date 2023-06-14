#!/usr/bin/python3

def search_replace(my_list, search, replace):
    # Create a new list to store the modified elements
    new_list = []

    # Iterate over the elements in my_list
    for element in my_list:
        # Check if the current element matches the search element
        if element == search:
            # If it matches, append the replace element to the new list
            new_list.append(replace)
        else:
            # If it doesn't match, append the current element to the new list
            new_list.append(element)

    return new_list
