###############################
#    Name: Nathan Rogers
#    Date: 11/26/2018
###############################

import structure as struc
          
# Sort 1: Insertion Sort
def sort1(llist):
    start = llist.head
    node = start.next  
    while node:
            node2 = start
            while node2.cargo < node.cargo:
                    node2 = node2.next    
            oldval = node.cargo
            while node2 != node:
                    oldval, node2.cargo = node2.cargo, oldval
                    node2 = node2.next       
            node.cargo = oldval                  
            node = node.next               
    return llist
    
#Sort 2: Selection Sort
def sort2(llist):
    sort = True
    cur = llist.head.next
    precur = llist.head
    while sort:
        minNode = cur
        minPrev = None
        nxt = minNode.next
        prev = cur
        sort = False
        while nxt != None:
            if nxt.cargo < minNode.cargo:
                minPrev = prev
                minNode = nxt
                sort = True
            if nxt.next != None and nxt.cargo > nxt.next.cargo:
                sort = True
            prev = nxt
            nxt = nxt.next
        curNxt = cur.next
        minNxt = minNode.next
        if cur.next == minNode:
            precur.next = minNode
            minNode.next = cur
            cur.next = minNxt
        elif cur != minNode:
            precur.next = minNode
            minNode.next = curNxt
            minPrev.next = cur
            cur.next = minNxt
        precur = minNode
        cur = minNode.next
    return llist

#Sums up the LinkedList
def sumList(llist):
    current = llist.head
    result = current.cargo
    while current.next is not None:
        current = current.next
        result += current.cargo
    return result

#This will print out all the values in LinkedList
def printAll(name):
    
    node = name.head
    while node is not None:
        print(node.cargo, end=',')
        node = node.next
     

if __name__ == "__main__":
    import random
    #Test 1
    print("\nInsertion Sort:")
    LinkedL = struc.LinkedList()
    for x in range(20):
        LinkedL.insert(random.randint(1, 100))
    print("\nUnsorted Linked List: \n")
    printAll(LinkedL)
    sortLinkedL = sort1(LinkedL)
    print("\n\nSorted Linked List: \n")
    printAll(sortLinkedL)
    
    #Test 2
    print("\n\nSelection Sort:")
    LinkedL = struc.LinkedList()
    for x in range(20):
        LinkedL.insert(random.randint(1, 100))
    print("\nUnsorted Linked List: \n")
    printAll(LinkedL)
    sortLinkedL = sort2(LinkedL)
    print("\n\nSorted Linked List: \n")
    printAll(sortLinkedL)


    #Sum Test
    ll = struc.LinkedList()
    #Add Values
    ll.insert(100)
    ll.insert(12)
    ll.insert(30)
    ll.insert(25)
    #Call Sum Function
    sums = sumList(ll)
    print("\n\nTHE SUM:\n")
    print(sums)

    

