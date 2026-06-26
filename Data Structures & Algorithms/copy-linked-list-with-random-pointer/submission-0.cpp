/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


class
 
Solution
 
{

public
:

    Node
*
 
copyRandomList
(
Node
*
 head
)
 
{

        
if
 
(
!
head
)
 
return
 
nullptr
;

        
// Step 1: Create a mapping from original nodes to their copies

        std
::
unordered_map
<
Node
*
,
 Node
*
>
 nodeMap
;

        
// Step 2: First pass to create all nodes and store them in the map

        Node
*
 current 
=
 head
;

        
while
 
(
current
)
 
{

            nodeMap
[
current
]
 
=
 
new
 
Node
(
current
->
val
)
;

            current 
=
 current
->
next
;

        
}

        
// Step 3: Second pass to assign next and random pointers

        current 
=
 head
;

        
while
 
(
current
)
 
{

            nodeMap
[
current
]
->
next 
=
 nodeMap
[
current
->
next
]
;

            nodeMap
[
current
]
->
random 
=
 nodeMap
[
current
->
random
]
;

            current 
=
 current
->
next
;

        
}

        
// Return the head of the copied list

        
return
 nodeMap
[
head
]
;

    
}

}
;
