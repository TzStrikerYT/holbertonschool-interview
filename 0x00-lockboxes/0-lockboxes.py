#!/usr/bin/python3


def canUnlockAll(boxes):
    """ lockboxes app """
    if len(boxes) == 0:
        return False

    iBox = [0]
    for key in iBox:
        for keyBox in boxes[key]:
            if keyBox not in iBox:
                if keyBox < len(boxes):
                    iBox.append(keyBox)
    if len(iBox) == len(boxes):
        return True

    return False
    