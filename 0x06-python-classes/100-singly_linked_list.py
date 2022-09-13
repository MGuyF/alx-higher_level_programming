#!/usr/bin/python3


class Node:
    """Represents a node in a singly linked list
    Attributes:
        __data (int): data stored inside the node
        __next_node (Node): next node in the linked list
    """
    def __init__(self, data, next_node=None):
        """Initializes the node
        Args:
            data (int): data stored inside the node
            next_node (Node): next node in the linked list
        Returns:
            None
        """
        self.data = data
        self.next_node = next_node

    @property
    def data(self):
        """getter of __data
        Returns:
            data stored inside the node
        """
        return self.__data

    @data.setter
    def data(self, value):
        """setter of __data
        Args:
            value (int): data stored insite the node
        Returns:
            None
        """
        if type(value) is not int:
            raise TypeError("data must be an integer")
        self.__data = value

    @property
    def next_node(self):
        """getter of __next_node
        Returns:
           the next node in the linked list
        """
        return self.__next_node
