#!/usr/bin/python3
""" Function that adds a new attribute to an object if it’s possible """


def add_attribute(obj, name, value):
    """ Function for add attribute"""
    if hasattr(obj, '__dict__') is False:
        raise TypeError("can't add new attribute")

    setattr(obj, name, value)
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms
Priva
