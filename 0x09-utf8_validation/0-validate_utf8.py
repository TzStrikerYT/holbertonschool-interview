#!/usr/bin/python3
"""Call this function to find and utf-8 character"""


def validUTF8(data):
    """
    Return: True if data is a valid UTF-8 encoding, else return False
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    """
    counter = 0
    firstValidation = 1 << 7
    secondValidation = 1 << 6

    for i in data:
        mask_n_byte = 1 << 7
        if counter == 0:
            while mask_n_byte & i:
                counter += 1
                mask_n_byte = mask_n_byte >> 1
            if counter == 0:
                continue
            if counter == 1 or counter > 4:
                return False
        else:
            if not (i & firstValidation and not (i & secondValidation)):
                return False
        counter -= 1
    if counter == 0:
        return True
