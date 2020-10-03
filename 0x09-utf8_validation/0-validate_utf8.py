#!/usr/bin/python3
"""Call this function to find and utf-8 character"""


def validUTF8(data):
    """
    Return: True if data is a valid UTF-8 encoding, else return False
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    """
    countBytes = 0
    oneVer = 1 << 7
    secondVer = 1 << 6

    for i in data:
        mask_n_byte = 1 << 7
        if countBytes == 0:
            while mask_n_byte & i:
                countBytes += 1
                mask_n_byte = mask_n_byte >> 1
            if countBytes == 0:
                continue
            if countBytes == 1 or countBytes > 4:
                return False
        else:
            if not (i & oneVer and not (i & secondVer)):
                return False
        countBytes -= 1
    if countBytes == 0:
        return True
    return False
