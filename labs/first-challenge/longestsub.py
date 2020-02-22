def getChars(string):
    return [char for char in string] 

def findLongest(string):
    if(len(string)==0):
        return 0

    chars = getChars(string.lower())
    longest = 1
    visited = []



    for char in chars:
        if char in visited:
            visited = visited[visited.index(char)+1:]
            visited.append(char)
        else:
            visited.append(char)
            if(len(visited) > longest):
                longest = len(visited)
    return longest

def main():
    string = input()
    print(findLongest(string))

main()
